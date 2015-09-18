/****************************************************************************
**
** Copyright (C) 2010 Michele Dallachiesa (michele.dallachiesa@gmail.com)
** All rights reserved.
**
** Warning: This program is protected by copyright law and international
** treaties. Unauthorized reproduction and distribution of this program,
** or any portion of it, may result in severe civil and criminal penalties,
** and will be persecuted to the maximum extent possible under the law.
**
****************************************************************************/


#include <QString>
#include "DataSet.h"
#include "Common.h"
#include "GraphLayout.h"
#include "Cnf.h"
#include "QUtils.h"

/**
 * @brief DataSet::DataSet
 */
DataSet::DataSet() : minAttrs(-1), maxAttrs(-1), graphGL(NULL)
{
    //this->minAttrs = -1;
    //this->maxAttrs = -1;
    //this->graphGL = NULL;
}

DataSet::~DataSet()
{
    this->clean();
}

/**
 * @brief DataSet::initEmpty
 */
void DataSet::initEmpty()
{
    this->clean();
    if (this->graphGL==NULL)
    {
        this->graphGL = new GraphLayoutGL();
    }
    else
    {
        delete this->graphGL;
        this->graphGL = new GraphLayoutGL();
    }
}

/**
 * @brief DataSet::addNodeEntity
 * @param id
 * @param attrs
 * @return
 */
Node *DataSet::addNodeEntity(int id, std::vector<std::string> attrs)
{
    // Find if the node is already present
    Nodes::iterator iter;
    if ((iter = graphGL->nodes.find(id)) != graphGL->nodes.end())
    {
        return (*iter).second;
    }
    // Insert the node in the graph
    Node *node = graphGL->insertNode(id);
    // Create a new entity that will store the node properties and must be present in the dataset visualization

    if (node->ptrEntity==NULL)
    {
        (node->ptrEntity) = new Entity();
    }
    else
    {
        qDebug() << "Error assigning entity in addNodeEntity" ;
    }

    if ( attrs.empty()  && minAttrs > 0)
    {  for(int i = 0; i < minAttrs; i++)
            attrs.push_back(string("?"));
    }

    if(minAttrs == -1)
    {  minAttrs = attrs.size();
        maxAttrs = attrs.size();
    }
    else
    {  minAttrs = std::min(minAttrs, (int)attrs.size());
        maxAttrs = std::max(maxAttrs, (int)attrs.size());
    }

    for(unsigned int i = 0; i < attrs.size(); i++)
    {
        EntityAttribute *e;
        // Search for something which makes us think that this is a URL
        if(attrs.at(i).find_first_of("http://") == 0 || attrs.at(i).find_first_of("https://") == 0 ||  attrs.at(i).find_first_of("file://") == 0 )
        {
            e = static_cast<EntityAttribute *> (new EntityAttributeUrl());
            (static_cast<EntityAttributeUrl *>(e))->setValue(attrs.at(i));
        }
        else
        {
            /*
              if(attrs.at(i).find_last_of("jpg") == 3 || attrs.at(i).find_last_of("png") == 3)
              {
              cerr << "found JPG: " << attrs.at(i).find_first_of("jpg") << "\n";
              e = static_cast<EntityAttribute *> (new EntityAttributeImage());
              (static_cast<EntityAttributeImage *>(e))->setValue(attrs.at(i));
          } else {
          */
            e = static_cast<EntityAttribute *> (new EntityAttributeString());
            (static_cast<EntityAttributeString *>(e))->setValue(attrs.at(i));
        }
        node->ptrEntity->attributes.push_back(e);
    }
    return node;
}

/**
 * @brief DataSet::removeNodeEntity
 * @param id
 */
void DataSet::removeNodeEntity(LNode *n)
{
    // If the specified nodes doesn't exist, return immediately
    if (!this->graphGL->nodeExists(n->id))
        return;
    // Then finally deletes the node
    this->graphGL->removeNode(n->id);
}

/**
 * @brief DataSet::loadPajek
 * @param pathname
 * @return
 */
bool DataSet::loadPajek(QString pathname)
{
    initEmpty();

    QFile f(pathname);

    if(!f.open(QIODevice::ReadOnly | QIODevice::Text))
    {  errorMessage ="Open failed";
        return false;
    }

    vector<string> emptyVec;
    vector<string> tokens;

    QString parsingErrors;

    int state = 0;
    int lineNumber=0;
    while(!f.atEnd())
    {  lineNumber++;
        QString line = f.readLine().trimmed();
        if (line.size() == 0)
            continue;
        QTextStream ss(&line);
        //   Common::skipSpaces(ss);
        if(line.startsWith("%"))
        {  if(line.startsWith("%*colnames",Qt::CaseInsensitive))
            {  ss.read(QString("%*colnames").size());
                ss.skipWhiteSpace();
                QString s = ss.readAll();
                QStringList list = s.split(";");
                list.replaceInStrings(QRegExp("(^\")|(\"$)"), " ");
                QStringList trimmed;
                for (int i = 0; i < list.size(); ++i)
                {  trimmed << list.at(i).trimmed();
                }
                for (int i = 0; i < list.size(); ++i)
                {  colNames.push_back(trimmed.at(i).toLocal8Bit().constData());
                }
                continue;
            }
            // it's a comment, skip.
            continue;
        }
        if(line.startsWith("*"))
        {  if(line.startsWith("*vertices", Qt::CaseInsensitive))
            {  state = 1;
                continue;
            }
            if(line.startsWith("*arcslist", Qt::CaseInsensitive) ||
                    line.startsWith("*edgeslist", Qt::CaseInsensitive))
            {  state = 3;
                continue;
            }
            if(line.startsWith("*arcs", Qt::CaseInsensitive) ||
                    line.startsWith("*edges", Qt::CaseInsensitive))
            {  state = 2;
                continue;
            }
            // tag not supported, set "unsupported section" state.
            state = 4;
            //        cerr << "nothing detected\n";
        }
        int id1, id2;
        ss.skipWhiteSpace();
        switch(state)
        {  case 1:
        {  ss >> id1;
            ss.skipWhiteSpace();
            char c;
            ss >> c;
            ss.seek(ss.pos()-1);
            if(c == '"')
            {  ss >> c; // get 1st "
                QString attrs;
                for(;;)
                {  ss >> c;
                    if ( c=='\0'  )
                    {  parsingErrors.append("\nParsing line " +  QString::number(lineNumber) + ": missing attribute endquote");
                        break;
                    }
                    // We continue in this case but report the error in warning message
                    if(c == '"' || c=='\0' )
                        break;
                    attrs = attrs.append(c);
                }

                QStringList list;
                if( !colNames.empty() )
                {  list = attrs.split(";");
                    if(list.size() == 0)
                        list << "?";
                    QStringList trimmed;
                    for (int i = 0; i < list.size(); ++i)
                    {  trimmed << list.at(i).trimmed();
                    }
                    list = trimmed;
                }
                else
                {  list << attrs;
                }
                //cerr << "attr: " << attrs.toAscii().data() << "\n";
                tokens.clear();
                for (int i = 0; i < list.size(); ++i)
                {  tokens.push_back(list.at(i).toLocal8Bit().constData());
                }
            }
            double coords[3]= {0.0,0.0,0.0};

            ss.skipWhiteSpace();
            ss >> coords[0];
            ss.skipWhiteSpace();
            ss >> coords[1];
            ss.skipWhiteSpace();
            ss >> coords[2];

            for (int i=0; i<3; i++)
            {  if ( isnan(coords[i]) || isinf(coords[i]) )
                {  parsingErrors+=QString("\nParsing line " + QString::number(lineNumber) );
                    coords[i]=Common::unifRand(-1.0,1.0);
                }
            }

            LNode *lnode = static_cast<LNode*>( this->addNodeEntity(id1, tokens) );
            lnode->px = coords[0];
            lnode->py = coords[1];
            lnode->pz = coords[2];
        }
            break;
            // XXX start reading arcs with weights
        case 2:
        {  ss >> id1;
            ss.skipWhiteSpace();
            ss >> id2;
            ss.skipWhiteSpace();
            Node *n1 = addNodeEntity(id1, emptyVec);
            Node *n2 = addNodeEntity(id2, emptyVec);
            double weight=-1;
            // se è finita la linea, mette peso di default
            if (ss.atEnd())
            {
                if(id1 != id2)       // ignore self edges
                {
                    graphGL->insertEdge(id1, id2);
                    graphGL->insertEdge(id2, id1);
                }
            }
            else
            {
                // altrimenti legge il peso, se non è 0 lo inserisce
                ss >> weight;
                if(id1 != id2)       // ignore self edges
                {
                    Edge *e1 = graphGL->getEdge(id1,id2);
                    Edge *e2 = graphGL->getEdge(id2,id1);
                    if ( (e1!=NULL) && (e2!=NULL) )
                    {
                        double oldWeight = e1->weight;  //XXX bisogna sempre pensare che all'andata e al ritorno il peso sia uguale
                        e1->weight=weight;
                        e2->weight=weight;
                        if (n1!=NULL)
                            n1->degree =n1->degree-oldWeight+weight;
                        if (n2!=NULL)
                            n2->degree =n2->degree-oldWeight+weight;
                    }
                    else
                    {
                        graphGL->insertEdge(id1, id2, weight);
                        graphGL->insertEdge(id2, id1, weight);
                    }
                }
            }
        }
            break;
            // starts reading edgestlist with **OPTIONAL** weights
        case 3:
        {
            ss >> id1;
            Node *n1 = addNodeEntity(id1, emptyVec);
            QStringList splittedLine = line.split(" ");
            for (int k=0; k<splittedLine.size();k++)
            {
                // This edge is weighted
                if (splittedLine.at(k).contains(":"))
                {
                    QStringList splitSplit = splittedLine.at(k).split(":");
                    int id2 = splitSplit.at(0).toInt();
                    Node *n2  = addNodeEntity(id2,emptyVec);
                    double weight = splitSplit.at(1).toDouble();
                    if (id1 != id2 )
                    {
                        Edge *e1 = graphGL->getEdge(id1,id2);
                        Edge *e2 = graphGL->getEdge(id2,id1);
                        if (e1!=NULL && e2!=NULL)
                        {
                            double oldWeight = e1->weight;  //XXX bisogna sempre pensare che all'andata e al ritorno il peso sia uguale
                            e1->weight=weight;
                            e2->weight=weight;
                            if (n1!=NULL)
                                n1->degree =n1->degree-oldWeight+weight;
                            if (n2!=NULL)
                                n2->degree =n2->degree-oldWeight+weight;
                        }
                        else
                        {
                            graphGL->insertEdge(id1, id2, weight);
                            graphGL->insertEdge(id2, id1, weight);
                        }
                    }
                } // the edge is not weighted
                else
                {
                    int id2 = splittedLine.at(k).toInt();
                    Node *n2  = addNodeEntity(id2,emptyVec);
                    if (id1 != id2 )
                    {
                        Edge *e1 = graphGL->getEdge(id1,id2);
                        Edge *e2 = graphGL->getEdge(id2,id1);
                        if (e1!=NULL && e2!=NULL)
                        {
                            double oldWeight = e1->weight;  //XXX bisogna sempre pensare che all'andata e al ritorno il peso sia uguale
                            e1->weight=1;
                            e2->weight=1;
                            if (n1!=NULL)
                                n1->degree =n1->degree-oldWeight+1;
                            if (n2!=NULL)
                                n2->degree =n2->degree-oldWeight+1;
                        }
                        else
                        {
                            graphGL->insertEdge(id1, id2);
                            graphGL->insertEdge(id2, id1);
                        }
                    }
                }
            }
            // OLD VERSION WITH NO WEIGHT SUPPORT
            /*
            for(;;)
            {  ss.skipWhiteSpace();
                ss >> id2;
                if(ss.status() == QTextStream::ReadPastEnd)
                    break;
                addNodeEntity(id2, emptyVec);
                if(id1 != id2)
                {   graphGL->insertEdge(id1, id2);
                    graphGL->insertEdge(id2, id1);
                }
            }
            */

        }
            break;
        default:
            continue;
        }
    }

    if ( !parsingErrors.isEmpty() )
    {  warningMessage.append(parsingErrors);
    }
    if(minAttrs != maxAttrs)
    {  // number of columns not constant
        errorMessage = "Number of columns is not constant";
        return false;
    }

    if(minAttrs == 1 && colNames.empty() )
    {  // standard pajek format: no col names, 1 label
        colNames.push_back(string("Label"));
    }

    if(minAttrs != colNames.size())
    {  cerr << "minattrs:" << minAttrs << "colnames size=" << colNames.size() << "\n";
        errorMessage = "Number of column names and number of columns differ";
        // column names != number of columns
        return false;
    }
    f.close();
    return true;
}

/**
 * @brief DataSet::writeSvg
 * @param pathname
 * @return
 */
bool DataSet::writeSvg(const QString &pathname)
{  
    ofstream os;
    os.open(pathname.toAscii().data());

    if(os.fail())
    {
        os.close();
        errorMessage = "Open failed";
        return false;
    }

    os << "<?xml version=\"1.0\" standalone=\"no\"?>\n<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\"\n\"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">\n<svg width=\"100%\" height=\"100%\" version=\"1.1\"\nxmlns=\"http://www.w3.org/2000/svg\">\n";
    os << "\n<!-- Graph in SVG format (.svg) - generated by GraphInsight, http://www.GraphInsight.com !-->\n\n";

    for (NodesRand::const_iterator iter1=graphGL->nodesRand.begin(); iter1!=graphGL->nodesRand.end(); ++iter1)
    {
        LNode *n1=(static_cast<LNode*>(*iter1));
        for(NeighborsRand::const_iterator iter2 = n1->neighborsRand.begin(); iter2 != n1->neighborsRand.end(); ++iter2)
        {
            LNode *n2 = static_cast<LNode*>((*iter2)->second);
            os << "<line x1=\"" << 100+100*graphGL->normalizedCoord(n1->px,0) << "\" y1=\"" << 100+100*graphGL->normalizedCoord(n1->py,1) << "\" x2=\"" << 100+100*graphGL->normalizedCoord(n2->px,0) <<"\" y2=\"" << 100+100*graphGL->normalizedCoord(n2->py,1)<< "\" style=\"stroke:black;stroke-width:0.2\"/>\n";
        }
    }

    for (NodesRand::const_iterator iter1=graphGL->nodesRand.begin(); iter1!=graphGL->nodesRand.end(); ++iter1)
    {
        LNode *n1=(static_cast<LNode*>(*iter1));
        os << "<circle cx=\"" << 100+100*graphGL->normalizedCoord(n1->px,0) << "\" cy=\"" << 100+100*graphGL->normalizedCoord(n1->py,1) << "\" r=\"0.5\" stroke=\"black\" stroke-width=\"0.2\" fill=\"red\"/>\n";
    }

    os << "</svg>\n";
    os.close();
    return true;
}

/**
 * @brief DataSet::writePajek
 * @param pathname
 * @return
 */
bool DataSet::writePajek(const QString &pathname)
{  
    ofstream os;
    os.open(pathname.toAscii().data());
    if(os.fail())
    {  os.close();
        errorMessage = "Open failed";
        return false;
    }
    os << "%\n% Graph in extended Pajek network format (.net) - generated by GraphInsight, http://www.GraphInsight.com\n%\n\n";

    if(!colNames.empty() )
    {  if(!(colNames.size() == 1 && Common::equalCaseInsensitive(colNames[0],string("Label"))))
        {  os << "%*Colnames \"";
            for(unsigned int i = 0; i < colNames.size(); i++)
            {  os << colNames[i];
                if(i < colNames.size()-1)
                {  os << "; ";
                }
            }
            os << "\"\n\n";
        }
    }
    
    os << "*Vertices " << graphGL->nodesRand.size() << "\n";
    for (NodesRand::const_iterator iter1=graphGL->g->nodesRand.begin(); iter1!=graphGL->g->nodesRand.end(); ++iter1)
    {
        LNode *n1=(static_cast<LNode*>(*iter1));
        os << n1->id ;
        if (! n1->ptrEntity->attributes.empty() )
        {
            os << " \"";
            int i = 0;
            for(vector<EntityAttribute*>::iterator iter2 = n1->ptrEntity->attributes.begin(); iter2 != n1->ptrEntity->attributes.end(); ++iter2)
            {
                os << (*iter2)->toString()->c_str();
                if(i < n1->ptrEntity->attributes.size()-1)
                {  os << "; ";
                }
                i++;
            }
            os << "\"";
        }
        os << " " << n1->px << " "<< n1->py << " "<< n1->pz << "\n";
    }
    os << "\n*Edgeslist\n";
    for (NodesRand::const_iterator iter1=graphGL->nodesRand.begin(); iter1!=graphGL->nodesRand.end(); ++iter1)
    {
        LNode *n1=(static_cast<LNode*>(*iter1));
        os << n1->id << " ";
        for(NeighborsRand::const_iterator iter2 = n1->neighborsRand.begin(); iter2 != n1->neighborsRand.end(); ++iter2)
        {
            LNode *n2 = static_cast<LNode*>((*iter2)->second);
            Edge *e = static_cast<Edge*>((*iter2)->first);
            if ( abs(e->weight-1.0) < std::numeric_limits<double>::epsilon()*10 )
                os << n2->id << " ";
            else
                os << n2->id << ":" << e->weight << " ";
        }
        os << endl;
    }

    os << "\n%\n% end.\n%\n";
    os.close();

    return true;
}

/**
 * @brief DataSet::loadCNF
 * @param pathname
 * @param isVRG
 * @return
 */
bool DataSet::loadCNF(const QString &pathname, bool isVRG)
{
    this->clean();
    initEmpty();
    Cnf cnf;
    ifstream is;
    is.open(pathname.toAscii().data());
    if(is.fail())
    {  is.close();
        errorMessage = "Open failed";
        return false;
    }
    cnf.loadFromFile(is);
    bool ret;
    if(isVRG)
        ret = cnf.buildResolutionGraph(graphGL);
    else
        ret= cnf.buildVariableInteractionGraph(graphGL);

    for (NodesRand::iterator iterNodes = graphGL->nodesRand.begin(); iterNodes != graphGL->nodesRand.end(); ++iterNodes)
    {
        LNode *n = static_cast<LNode*> (*iterNodes);
        if (n->ptrEntity==NULL)
            n->ptrEntity = new Entity();
    }
    
    is.close();
    return ret;
}

/**
 * @brief DataSet::loadDimacs
 * @param pathname
 * @return
 */
bool DataSet::loadDimacs(const QString &pathname)
{  this->clean();
    initEmpty();
    ifstream is;
    is.open(pathname.toAscii().data());
    vector<string> emptyVec;
    if(is.fail())
    {  is.close();
        errorMessage ="Open failed";
        return false;
    }
    string line;
    while (getline(is, line))
    {  if (line.size() == 0)
            continue;
        stringstream str(line);
        Common::skipSpaces(str);
        if(Common::nextChar(str) == '%')
            continue;
        int nodeId1, nodeId2;
        double weight;
        double coordinates[] = {0.0, 0.0, 0.0};
        int nodesCount;

        str >> nodeId1;
        Common::skipSpaces(str);
        Common::skipSpacesReadChar(str, '(');
        str >> coordinates[0];
        Common::skipSpacesReadChar(str, ',');
        str >> coordinates[1];
        Common::skipSpaces(str);
        if (Common::nextChar(str) == ',')
        {  Common::skipSpacesReadChar(str, ',');
            str >> coordinates[2];
        }
        Common::skipSpacesReadChar(str, ')');
        str >> nodesCount;
        LNode *n1 = static_cast<LNode*>(addNodeEntity(nodeId1, emptyVec));
        n1->px = coordinates[0];
        n1->py = coordinates[1];
        n1->pz = coordinates[2];
        for (int i = 0; i < nodesCount; i++)
        {  str >> nodeId2;
            if (str.get() == ':')
            {  str >> weight;
            }
            else
            {  str.unget();
                weight = 1;
            }
            addNodeEntity(nodeId2, emptyVec);
            if(nodeId1 != nodeId2)       // ignore self edges
            {  graphGL->insertEdge(nodeId1, nodeId2, weight);
                graphGL->insertEdge(nodeId2, nodeId1, weight);
            }
        }
    }
    is.close();
    return true;
}

/**
 * @brief DataSet::writeDimacs
 * @param pathname
 * @return
 */
bool DataSet::writeDimacs(const QString &pathname)
{  ofstream os;
    os.open(pathname.toAscii().data());
    if(os.fail())
    {  os.close();
        errorMessage = "Open failed";
        return false;
    }
    os << "%\n% Graph in DIMACS format (.dimacs) - generated by GraphInsight, http://www.GraphInsight.com\n%\n\n";
    graphGL->writeDimacs(os);
    os.close();
    return true;
}

/**
 * @brief DataSet::writeDot
 * @param pathname
 * @return
 */
bool DataSet::writeDot(const QString &pathname)
{  ofstream os;
    os.open(pathname.toAscii().data());
    if(os.fail())
    {  os.close();
        errorMessage = "Open failed";
        return false;
    }
    os << "/*\n * Graph in DOT format (.dot) - generated by GraphInsight, http://www.GraphInsight.com\n */\n";
    graphGL->writeDOT(os);
    os.close();
    return true;
}

/**
 * @brief DataSet::writeGnuPlotBW
 * @param pathname
 * @return
 */
bool DataSet::writeGnuPlotBW(const QString &pathname)
{  ofstream os;
    os.open(pathname.toAscii().data());
    if(os.fail())
    {  os.close();
        errorMessage = "Open failed";
        return false;
    }
    graphGL->writeGnuplot(os,false);
    os.close();
    return true;
}

/**
 * @brief DataSet::writeGnuPlotColors
 * @param pathname
 * @return
 */
bool DataSet::writeGnuPlotColors(const QString &pathname)
{  ofstream os;
    os.open(pathname.toAscii().data());
    if(os.fail())
    {  os.close();
        errorMessage = "Open failed";
        return false;
    }
    graphGL->writeGnuplot(os,true);
    os.close();
    return true;
}

/**
 * @brief DataSet::clean
 */
void DataSet::clean()
{
    colNames.clear();
    warningMessage.clear();
    errorMessage.clear();
    minAttrs = -1;
    maxAttrs = -1;

    if(graphGL)
    {
        // Must clean the entities related to nodes
        delete graphGL;
        graphGL = NULL;
    }
}
