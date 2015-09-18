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


#include "EntityAttributeUrl.h"



EntityAttributeUrl::EntityAttributeUrl()
{  type = EntityAttribute::TypeUrl;
   valueString.assign("");
   toStringReady = true; // always ready.
}


EntityAttributeUrl::~EntityAttributeUrl()
{

}

string *EntityAttributeUrl::toString()
{

   return &valueString;
}

void EntityAttributeUrl::setValue(string s)
{  valueString.assign(s);
}

void EntityAttributeUrl::setValue(unsigned char *s)
{  valueString.assign((const char *)s);
}
