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


#include "QUtils.h"
/**
 * @brief QUtils::QUtils
 */
QUtils::QUtils()
{
}

/**
 * @brief QUtils::criticalMessage
 * @param parent
 * @param message
 */
void QUtils::criticalMessage(QWidget *parent, QString message)
{

   QMessageBox mbox(parent);
   mbox.setIcon(QMessageBox::Critical);
   mbox.setText(message);
   //  mbox.setWindowModality(Qt::WindowModal);
   mbox.setStandardButtons(QMessageBox::Close);
   mbox.exec();
}

/**
 * @brief QUtils::aboutDialog
 * @param parent
 * @param message
 */
void QUtils::aboutDialog(QWidget *parent, QString message)
{  QMessageBox mbox(parent);
   // mbox.setWindowModality(Qt::WindowModal);
   mbox.setStandardButtons(QMessageBox::Ok);
   mbox.setText(message);
   mbox.exec();
}

/**
 * @brief QUtils::trimQuotes
 * @param str
 * @return
 */
QString QUtils::trimQuotes(QString str)
{  QString ret = str;
   if(str.endsWith("\""))
      ret = ret.left(ret.size()-1);

   if(str.startsWith("\""))
      ret = ret.right(ret.size()-1);
   return ret;
}

/**
 * @brief QUtils::nextChar
 * @param ss
 * @return
 */
unsigned char QUtils::nextChar(QTextStream ss)
{  QString s = ss.read(1);
   return s[0].toAscii();
}
