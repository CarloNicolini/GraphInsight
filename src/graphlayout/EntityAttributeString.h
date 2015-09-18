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

#ifndef ENTITYATTRIBUTESTRING_H
#define ENTITYATTRIBUTESTRING_H

#include "EntityAttribute.h"
#include <string>

using namespace std;

class EntityAttributeString : public EntityAttribute
{
public:
   EntityAttributeString();
   EntityAttributeString(const std::string &val);
   ~EntityAttributeString();

   string *toString();


   void setValue(unsigned char *s);
   void setValue(string s);

};

#endif // ENTITYATTRIBUTESTRING_H
