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

#ifndef LNODEFACTORY_H
#define LNODEFACTORY_H

#include "PythonQt.h"
#include "PythonQtCppWrapperFactory.h"
#include "LNodeWrapper.h"
// A factory that can create wrappers for LNode
class LNodeFactory : public PythonQtCppWrapperFactory
{
public:
    LNodeFactory(MainWindow *m);

    MainWindow *mainWinPtr;
    virtual QObject* create(const QByteArray& name, void *ptr);
};
#endif
