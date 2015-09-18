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


#ifndef ENTITYATTRIBUTEIMAGE_H
#define ENTITYATTRIBUTEIMAGE_H

#include "EntityAttribute.h"

class EntityAttributeImage : EntityAttribute
{
public:

   EntityAttributeImage();
   ~EntityAttributeImage();

   std::string *toString();

   void setValue(string s);
};

#endif // ENTITYATTRIBUTEIMAGE_H
