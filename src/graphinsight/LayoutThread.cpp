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

#include <stdexcept>
#include <QEventLoop>
#include "LayoutThread.h"
#include "Common.h"
#include <errno.h>

using namespace std;
/**
 * @brief LayoutThread::LayoutThread
 */
LayoutThread::LayoutThread()
{  state = 0;
    elapsedTime = 0;
    stepsCount = 0;
    // By default no predetermined number of steps to do
    mustRandomize=false;
    initEmptyGraph();
    runTimer.start();
}

/**
 * @brief LayoutThread::run
 */
void LayoutThread::run()
{
    runTimer.start();
    updateState(0);
    stepsCount = 0;

    switch(actionType)
    {  case LayoutThread::ActionReload:
        runReload();
        break;
    case LayoutThread::ActionOpenFile:
        runOpenFile();
        break;
    default:
        throw std::runtime_error("2nd thread: unknown action");
        break;
    }
}

/**
 * @brief LayoutThread::updateState
 * @param s
 */
void LayoutThread::updateState(int s)
{  elapsedTime = runTimer.getElapsedTimeInMicroSec();

    switch(s)
    {  case 0:
        statusText = "Loading data";
        break;
    case 1:
        layoutCompleted = false;
        statusText = "Init method";
        break;
    case 2:
        statusText = "Improving";
        break;
    case 3:
        layoutCompleted = true;
        statusText = "Completed";
        break;
    case 4:
        if(state != 3)
            statusText = "Interrupted";
        break;
    case 5:
        statusText = "LoadFile failed";
        break;
    }

    state = s;
}
#include <QMessageBox>
/**
 * @brief LayoutThread::runOpenFile
 */
void LayoutThread::runOpenFile()
{  stop = false;
    doingSteps = false;

    layoutMutex.lock();
    dataSet.initEmpty();

    if(pathname == "empty")
    {  updateState(1);
        layoutMutex.unlock();
        doSteps();
        return;
    }

    QFileInfo fi(pathname);

    bool ret = false;
    //dataSet.errorMessage = "Unknown file extension\n";

    if(fi.suffix().compare(QString("net"),Qt::CaseInsensitive) == 0)
    {  ret = dataSet.loadPajek(fi.absoluteFilePath());
    }
    if(fi.suffix().compare(QString("dimacs"),Qt::CaseInsensitive) == 0)
    {  ret = dataSet.loadDimacs(pathname.toUtf8().constData());
    }
    if(fi.suffix().compare(QString("cnf"),Qt::CaseInsensitive) == 0)
    {  ret = dataSet.loadCNF(pathname.toUtf8().constData(),false);
    }
    if(fi.suffix().compare(QString("cnf2"),Qt::CaseInsensitive) == 0)
    {  ret = dataSet.loadCNF(pathname.toUtf8().constData(),true);
    }
    if(ret)
    {  if(dataSet.graphGL->statsNodesCount == 0)
        {  dataSet.errorMessage = "The graph is empty (0 nodes)\n";
            ret = false;
        }
        if(dataSet.graphGL->statsEdgesCount == 0)
        {  dataSet.errorMessage = "The graph has no edges\n";
            ret = false;
        }
    }

    if(ret == false)
    {  dataSet.initEmpty();
        updateState(5);
        layoutMutex.unlock();
        return;
    }

    dataSet.graphGL->pathName.assign(fi.baseName().toUtf8().constData());
    dataSet.graphGL->updateStaticStats();

    updateState(1);
    layoutMutex.unlock();
    bool random=false;

    if(! dataSet.graphGL->nodesRand.empty() )
    {
        LNode *lnode = static_cast<LNode*>(dataSet.graphGL->nodesRand.front() );
        if(lnode->px == 0)           // if x of first node != 0 don't randomize
        {  random = true;
        }
        else
        {  random = false;
        }

        if(lnode->pz == 0)
        {  nDimensions = 2;
        }
        else
        {  nDimensions = 3;
        }
    }

    layoutMutex.lock();

    if(random)
    {
        dataSet.graphGL->init(layoutMethodType, nDimensions, true, false);
    }
    else
    {  dataSet.graphGL->init(GraphLayout::MethodNothing, nDimensions, false, false);
    }
    layoutMutex.unlock();
    doSteps();
}

/**
 * @brief LayoutThread::runReload
 */
void LayoutThread::runReload()
{
    updateState(1);
    stop = false;
    doingSteps = false;
    layoutMutex.lock();
    bool shake;
    bool randomize=mustRandomize;
    if(layoutMethodType == GraphLayout::MethodNothing)
    {  shake = false;
    }
    else
    {  shake = true;
    }
    dataSet.graphGL->init(layoutMethodType, nDimensions, randomize, shake);
    layoutMutex.unlock();
    doSteps();
}

/**
 * @brief LayoutThread::stopMe
 */
void LayoutThread::stopMe()
{
    stop = true;
}

/**
 * @brief LayoutThread::doSteps
 */
void LayoutThread::doSteps()
{  //assert(this->isRunning());
    doingSteps = true;
    updateState(2);

    int reachedOptimum = 0;

    while(!stop && !reachedOptimum)
    {
        //  m.lock();
        reachedOptimum =  dataSet.graphGL->steps(1);
        dataSet.graphGL->g->updateDynamicStats();
        if(
                layoutMethodType == GraphLayout::MethodFruchtermanReingoldMultilevel ||
                layoutMethodType == GraphLayout::MethodFruchtermanReingoldProportionalMultilevel ||
                layoutMethodType == GraphLayout::MethodLinLogModelMultilevel ||
                layoutMethodType == GraphLayout::MethodBinaryStressMultilevel)
        {  dataSet.graphGL->g->updateStaticStats();
        }
        //  m.unlock();
        stepsCount++;
        //elapsedTime = myElapsedTime(&elapsedTimeBegin, &elapsedTimeEnd, false);
        elapsedTime = runTimer.getElapsedTimeInMicroSec();
    }

    if(reachedOptimum)
    {  updateState(3);
    }
    updateState(4);
}

/**
 * @brief LayoutThread::initReload
 * @param layoutMethodType
 * @param nDimensions
 */
void LayoutThread::initReload(int _layoutMethodType, int _nDimensions)
{
    this->nDimensions = _nDimensions;
    if (this->layoutMethodType != _layoutMethodType)
        mustRandomize=true;
    else
        mustRandomize=false;
    this->layoutMethodType = _layoutMethodType;
    actionType = LayoutThread::ActionReload;
    doingSteps = false;
}

/**
 * @brief LayoutThread::initOpenFile
 * @param pathname
 * @param layoutMethodType
 * @param nDimensions
 */
void LayoutThread::initOpenFile(QString pathname, int layoutMethodType,  int nDimensions)
{  this->nDimensions = nDimensions;
    this->layoutMethodType = layoutMethodType;
    this->pathname = pathname;
    actionType = LayoutThread::ActionOpenFile;
    doingSteps = false;
}

/**
 * @brief LayoutThread::initEmptyGraph
 */
void LayoutThread::initEmptyGraph()
{  dataSet.initEmpty();
    updateState(3);
}
