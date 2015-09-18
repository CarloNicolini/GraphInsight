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


#include "EntityAttributeInt.h"


#include <string>
using namespace std;

EntityAttributeInt::EntityAttributeInt()
{  type = EntityAttribute::TypeInt;
   value = 0;
   toStringReady = false;

}


EntityAttributeInt::~EntityAttributeInt()
{  //DEBUG_PRINT("EntityAttributeInt destructor");
}

void EntityAttributeInt::setValue(int value)
{  toStringReady = false;
   this->value = value;
}

std::string *EntityAttributeInt::toString()
{  if(toStringReady)
      return &valueString;

   char s[16];
   sprintf(s, "%d", value); // XXX usare snprintf...

   valueString.assign(s);

   toStringReady = true;
   cerr << s << endl;
   return &valueString;
}
