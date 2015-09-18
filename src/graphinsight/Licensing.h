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

#ifndef LICENSING_H
#define LICENSING_H

#include "EntityAttribute.h"
#include <vector>
#include "LNode.h"
#include <string>
#include <QString>
#include <QObject>

using namespace std;


class Licensing
{
public:
   Licensing();
   Licensing(QString appPath);
   bool activate();
   ~Licensing();

private:

   bool validate();
   bool readFromFile();
   bool writeToFile();
   QByteArray encode(int salt, QByteArray v);
   QByteArray decode(int salt, QByteArray v);


   QString appPath;
   QString eMail;
   QString productKey;

   unsigned char *xorKey;


};


#endif
