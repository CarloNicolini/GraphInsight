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

#ifndef NODEDECORATOR_H
#define NODEDECORATOR_H

#include <QObject>
#include <QList>
#include "PythonQt.h"
#include "LNode.h"

// add a decorator that allows to access the CustomObject from PythonQt
class MainWindow;
class LNodeWrapper : public QObject
{  Q_OBJECT
public:
    LNodeWrapper(LNode* lnode);
    LNodeWrapper(LNode* lnode, MainWindow *m);
    void setMainWindow(MainWindow *m)
    {
        mainWin = m;
    }

    MainWindow *mainWin;
public slots:
    // Add access methods on Python side
    double getDegree() const;
    double getWeight() const;
    int getComponent() const;
    int getId() const;
    unsigned int getNumNeighbors() const;
    PyObject *neighbors();

    double getX() const;
    double getY() const;
    double getZ() const;

    //http://pythonqt.sourceforge.net/Developer.html la faccenda di definire gli iteratori diventa un bel casino poi però...
    QList<int> getNeighborsId() const;
    void move(const double &dx, const double &dy, const double &dz);
    void setPos(const double &x, const double &y, const double &z);
    void setColorRGB(int r,int g,int b);
    void setAttribute(int column, const QString &value);
    void setAttribute(const QString &attributeName, const QString &attributeValue);
    QStringList getAttributes() const;

signals:
    void nodeAttributeChanged(int row, int column, const QString &value);
private:
    LNode* _lnodePtr;
};

#endif // NODEDECORATOR_H
