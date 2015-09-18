/****************************************************************************
**
** Copyright (C) 2012 Carlo Nicolini (nicolini.carlo@gmail.com)
** All rights reserved.
**
** Warning: This program is protected by copyright law and international
** treaties. Unauthorized reproduction and distribution of this program,
** or any portion of it, may result in severe civil and criminal penalties,
** and will be persecuted to the maximum extent possible under the law.
**
****************************************************************************/

#ifndef _WORKER_H_
#define _WORKER_H_
#include <QtCore>
#include <QMutex>
#include "GLWidget.h"

class BackgroundLayoutThread : public QObject
{  Q_OBJECT
public:
   BackgroundLayoutThread( GLWidget *_m, int _nsteps);
   ~BackgroundLayoutThread();

public slots:
   void requestStop();
   void process();

signals:
   void isRunning(bool);
   void stepsDone(int n);
   void finished();
   void error(QString err);

private:
   GLWidget *glWidget;
   int nsteps;
   QMutex stepsMutex;
   bool stopRequested;
};

#endif
