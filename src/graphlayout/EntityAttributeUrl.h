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


#ifndef ENTITYATTRIBUTEURL_H
#define ENTITYATTRIBUTEURL_H

#include"EntityAttribute.h"

class EntityAttributeUrl : public EntityAttribute
{
public:
   EntityAttributeUrl();
   ~EntityAttributeUrl();

   string *toString();

   void setValue(unsigned char *s);
   void setValue(string s);
};

#endif // ENTITYATTRIBUTEURL_H
