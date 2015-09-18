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


#ifndef ENTITYATTRIBUTEINT_H
#define ENTITYATTRIBUTEINT_H

#include "EntityAttribute.h"

class EntityAttributeInt : public EntityAttribute
{
public:
   EntityAttributeInt();
   ~EntityAttributeInt();
   void setValue(int value);
   std::string *toString();
   int value;
};

#endif // ENTITYATTRIBUTEINT_H
