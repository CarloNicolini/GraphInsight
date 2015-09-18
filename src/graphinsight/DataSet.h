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


#ifndef DATASET_H
#define DATASET_H
#include <QString>
#include <map>
#include <utility>
#include "GraphLayoutGL.h"

#include "Entity.h"
#include "EntityAttribute.h"
#include "EntityAttributeInt.h"
#include "EntityAttributeString.h"
#include "EntityAttributeUrl.h"
#include "EntityAttributeImage.h"

class GraphLayoutGL;

class DataSet
{
public:
   DataSet();
   ~DataSet();

   void clean();
   void initEmpty();
   bool loadPajek(QString pathname);
   bool loadDimacs(const QString &pathname);
   bool loadCNF(const QString &pathname, bool isVRG);

   bool writePajek(const QString &pathname);
   bool writeDimacs(const QString &pathname);
   bool writeGnuPlotColors(const QString &pathname);
   bool writeGnuPlotBW(const QString &pathname);
   bool writeDot(const QString &pathname);
   bool writeSvg(const QString &pathname);

   Node* addNodeEntity(int id, vector<string> attrs);
   void removeNodeEntity(LNode *n);

   //std::map<int, Entity*> entitiesMap;
   vector<string> colNames;

   QString errorMessage;
   QString warningMessage;

   GraphLayoutGL *graphGL;

   int minAttrs;
   int maxAttrs;

};

#endif // DATASET_H
