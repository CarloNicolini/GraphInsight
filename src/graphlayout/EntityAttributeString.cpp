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


#include "EntityAttributeString.h"

EntityAttributeString::EntityAttributeString()
{  type = EntityAttribute::TypeString;
    valueString.assign("");
    toStringReady = true; // always ready.
}

EntityAttributeString::EntityAttributeString(const string &val)
{
    type = EntityAttribute::TypeString;
    valueString.assign(val);
    toStringReady = true; // always ready.
}

EntityAttributeString::~EntityAttributeString()
{

}


string *EntityAttributeString::toString()
{
    return &valueString;
}

void EntityAttributeString::setValue(string s)
{  valueString.assign(s);
}

void EntityAttributeString::setValue(unsigned char *s)
{  valueString.assign((const char *)s);
}
