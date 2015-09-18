/****************************************************************************
**
** Copyright (C) 2013 Carlo Nicolini (nicolini.carlo@gmail.com)
** All rights reserved.
**
** Warning: This program is protected by copyright law and international
** treaties. Unauthorized reproduction and distribution of this program,
** or any portion of it, may result in severe civil and criminal penalties,
** and will be persecuted to the maximum extent possible under the law.
**
****************************************************************************/

#include <stdexcept>
#include "LNodeWrapper.h"
#include "MainWindow.h"
// Public constructor
/**
 * @brief LNodeWrapper::LNodeWrapper
 * @param lnode
 */
LNodeWrapper::LNodeWrapper(LNode *lnode) : _lnodePtr(lnode), mainWin(NULL)
{
}

LNodeWrapper::LNodeWrapper(LNode *lnode, MainWindow *m) : _lnodePtr(lnode), mainWin(m)
{
    //DEBUG_PRINT( lnode << " " << m );
    QObject::connect(this,SIGNAL(nodeAttributeChanged(int,int, const QString &)), m, SLOT(updateDataSetElement(int , int ,  const QString &)));
}

// Implementation of slots (access methods)
/**
 * @brief LNodeWrapper::getId
 * @return
 */
int LNodeWrapper::getId() const
{
    return _lnodePtr->id;
}

/**
 * @brief LNodeWrapper::getComponent
 * @return
 */
int LNodeWrapper::getComponent() const
{  return _lnodePtr->component;
}


/**
 * @brief LNodeWrapper::getDegree
 * @return
 */
double LNodeWrapper::getDegree() const
{  return _lnodePtr->degree;
}

/**
 * @brief LNodeWrapper::getNumNeighbors Get the number of neighbors of the node
 * @return
 */
unsigned int LNodeWrapper::getNumNeighbors() const
{  return _lnodePtr->neighborsRand.size();
}

/**
 * @brief LNodeWrapper::getWeight Get the weight of the node (only used in internal algorithms)
 * @return
 */
double LNodeWrapper::getWeight() const
{  return _lnodePtr->weight;
}

/**
 * @brief LNodeWrapper::x Get the x position of the node
 * @return
 */
double LNodeWrapper::getX() const
{  return _lnodePtr->px;
}

/**
 * @brief LNodeWrapper::y Get the y position of the node
 * @return
 */
double LNodeWrapper::getY() const
{  return _lnodePtr->py;
}

/**
 * @brief LNodeWrapper::z Get the z position of the node
 * @return
 */
double LNodeWrapper::getZ() const
{  return _lnodePtr->pz;
}

/**
 * @brief LNodeWrapper::setpos Set the coordinates of the node
 * @param x
 * @param y
 * @param z
 */
void LNodeWrapper::setPos(const double &x, const double &y, const double &z)
{
    this->_lnodePtr->px =x;
    this->_lnodePtr->py = y;
    this->_lnodePtr->pz = z;
}

/**
 * @brief LNodeWrapper::setColorRGB
 * @param r
 * @param g
 * @param b
 */
void LNodeWrapper::setColorRGB(int r, int g, int b)
{
    if ( r>255 || r < 0 )
        throw std::out_of_range("Red out of range [0,255]");
    if ( g>255 || g < 0 )
        throw std::out_of_range("Green out of range [0,255]");
    if ( b>255 || b < 0 )
        throw std::out_of_range("Blue out of range [0,255]");

    if (this->mainWin->getGLWidget()->options.useCustomRGBColorMethod == false )
    {
        this->mainWin->getGLWidget()->options.useCustomRGBColorMethod=true;
        this->mainWin->updateColoringMethodsComboBoxes();
    }
    this->_lnodePtr->colorRed= r;
    this->_lnodePtr->colorGreen= g;
    this->_lnodePtr->colorBlue= b;
}

/**
 * @brief LNodeWrapper::move Move the node coordinates by some amount
 * @param dx
 * @param dy
 * @param dz
 */
void LNodeWrapper::move(const double &dx, const double &dy, const double &dz)
{  this->_lnodePtr->px+=dx;
    this->_lnodePtr->py+=dy;
    this->_lnodePtr->pz+=dz;
}

/**
 * @brief LNodeWrapper::neighbors Get the neighbors as dictionary of id-nodes
 * @return
 */
PyObject* LNodeWrapper::neighbors()
{
    PyObject *neighDict = PyDict_New();
    for (NeighborsRand::const_iterator iter =  this->_lnodePtr->neighborsRand.begin(); iter!= this->_lnodePtr->neighborsRand.end(); ++iter )
    {  LNode *n = static_cast<LNode*>((*iter)->second);
        PyObject *key = PyInt_FromLong((long int)n->id);

        PythonQtInstanceWrapper* wrap = (PythonQtInstanceWrapper*)PythonQt::priv()->wrapPtr(n, "LNode");
        wrap->_ownedByPythonQt = true;
        wrap->_useQMetaTypeDestroy = true;
        PyObject *value =  (PyObject*)wrap;
        PyDict_SetItem(neighDict, key ,value);
        Py_XDECREF(key);
        Py_XDECREF(value);
    }
    return neighDict;
}

/**
 * @brief LNodeWrapper::getNeighborsId
 * @return
 */
QList<int> LNodeWrapper::getNeighborsId() const
{
    QList<int> neighlist;
    for (NeighborsRand::const_iterator iter =  this->_lnodePtr->neighborsRand.begin(); iter!= this->_lnodePtr->neighborsRand.end(); ++iter )
        neighlist.push_back(((*iter)->second)->id);

    return neighlist;
}

/**
 * @brief LNodeWrapper::setAttribute
 * @param attributeName
 * @param attributeValue
 */
void LNodeWrapper::setAttribute(const QString &attributeName, const QString &attributeValue)
{
    // Search the index of the attribute with value attributeValue
    int colNumber=-1;
    for (int i=0; i<this->mainWin->getGLWidget()->layoutThread.dataSet.colNames.size();++i )
    {
        if (this->mainWin->getGLWidget()->layoutThread.dataSet.colNames.at(i)==attributeName.toStdString())
            colNumber=i;
    }
    if (colNumber==-1)
        throw std::out_of_range("No attribute "+attributeName.toStdString() +" found");
    EntityAttribute*e = this->_lnodePtr->ptrEntity->attributes.at(colNumber);
    e->valueString=attributeValue.toStdString();
     emit nodeAttributeChanged(this->_lnodePtr->index-1, colNumber+1, attributeValue);
}

/**
 * @brief LNodeWrapper::setAttribute
 * @param column
 * @param attributeValue
 */
void LNodeWrapper::setAttribute(int column, const QString &attributeValue)
{
    // Search the index of the attribute with value attributeValue
    int colNumber=column;
    if (colNumber >= this->mainWin->getGLWidget()->layoutThread.dataSet.colNames.size() || colNumber <0 )
        throw std::out_of_range("No such column, allowed values are in [" + QString::number(0).toStdString() + "," + QString::number(this->mainWin->getGLWidget()->layoutThread.dataSet.colNames.size()-1).toStdString() + "]" );

    EntityAttribute*e = this->_lnodePtr->ptrEntity->attributes.at(colNumber);
    e->valueString=attributeValue.toStdString();
     emit nodeAttributeChanged(this->_lnodePtr->index-1, colNumber+1, attributeValue);
}

/**
 * @brief LNodeWrapper::getAttributes
 * @return
 */
QStringList LNodeWrapper::getAttributes() const
{
    QList<QString> attributesList;
    for (unsigned int i=0; i<this->_lnodePtr->ptrEntity->attributes.size();++i)
    {
        attributesList << QString::fromStdString(this->_lnodePtr->ptrEntity->attributes.at(i)->valueString);
    }
    return attributesList;
}



