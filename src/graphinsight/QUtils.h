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


#ifndef QUTILS_H
#define QUTILS_H

#include "QWidget"
#include "QMessageBox"
#include "QTextStream"

class QUtils
{
public:
   QUtils();

   static void criticalMessage(QWidget *parent, QString message);
   static void aboutDialog(QWidget *parent, QString message);
   static QString trimQuotes(QString str);
   static unsigned char nextChar(QTextStream ss);
};

#endif // QUTILS_H
