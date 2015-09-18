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

#include "BackgroundLayoutThread.h"

/**
 * @brief Worker::Worker
 * @param _glWidget
 * @param _nsteps
 */
BackgroundLayoutThread::BackgroundLayoutThread(GLWidget *_glWidget, int _nsteps) : stopRequested(false)
{  glWidget=_glWidget;
    nsteps=_nsteps;
    //qDebug() << "stepper created";
}

/**
 * @brief Worker::~Worker
 */
BackgroundLayoutThread::~BackgroundLayoutThread()
{
    //qDebug() << "calling delete on BackgroundLayoutThread " << this;
}

/**
 * @brief BackgroundLayoutThread::requestStop
 */
void BackgroundLayoutThread::requestStop()
{
    //qDebug() << "Requesting stop";
    QMutexLocker lock(&stepsMutex);
    this->stopRequested = true;
    emit finished();
}

/**
 * @brief Worker::process
 */
void BackgroundLayoutThread::process()
{
    //stepsMutex.lock();
    for (int i=0; i<nsteps; i++)
    {  glWidget->layoutThread.dataSet.graphGL->steps(nsteps);
        emit stepsDone(i);
        QMutexLocker lock(&stepsMutex);
        if (stopRequested)
        {
            //emit isRunning(false);
            break;
        }
    }

    //stepsMutex.unlock();
    emit isRunning(false);
    emit finished();
}
