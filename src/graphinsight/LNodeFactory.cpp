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

#include "LNodeFactory.h"

LNodeFactory::LNodeFactory(MainWindow *m)
{
    this->mainWinPtr = m;
}

/**
 * @brief LNodeFactory::create A factory method that can create wrappers for LNodeWrapper
 * @param name
 * @param ptr
 * @return
 */
// A factory that can create wrappers for LNode
QObject* LNodeFactory::create(const QByteArray& name, void *ptr)
{
    if (name == "LNode")
    {  LNodeWrapper *lnodeWrapper =  new LNodeWrapper(static_cast<LNode*>(ptr),this->mainWinPtr);
        return lnodeWrapper;
    }
    return NULL;
}

