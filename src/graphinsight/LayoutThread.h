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


#ifndef LAYOUTTHREAD_H
#define LAYOUTTHREAD_H

#include <QThread>
#include <QMutex>
#include "GraphLayoutGL.h"
#include "Statistic.h"
#include "DataSet.h"
#include "Timer.h"

class LayoutThread :  public QThread
{  Q_OBJECT

   static const int ActionReload = 1;
   static const int ActionOpenFile = 2;

protected:
   void run();

public:
   LayoutThread();
   void doSteps();

   DataSet dataSet;

   void stopMe();
   void initReload(int methodType, int nDimensions);
   void initOpenFile(QString pathname, int methodType, int nDimensions);
   void initEmptyGraph();

   QString statusText;
   QMutex layoutMutex;
   // Here we should introduce an int status variable instead of doingSteps, so we can separate the stages of file loading
   //included the graph load method, in this way one can visualize the statistics before starting everything
   bool doingSteps;
   unsigned int state;
   bool layoutCompleted;

   unsigned int stepsCount;
   unsigned long int elapsedTime;
   Timer runTimer;

private:
   bool mustRandomize;
   bool stop;
   int nDimensions;
   int layoutMethodType;
   int actionType;
   QString pathname;

   void runOpenFile();
   void runReload();

   void updateState(int s);

};

#endif // LAYOUTTHREAD_H
