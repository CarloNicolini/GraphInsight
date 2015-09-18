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


#ifndef ENTITYATTRIBUTE_H
#define ENTITYATTRIBUTE_H

#include <string>
#include "Common.h"

using namespace std;

class EntityAttribute
{
public:
   EntityAttribute();
   virtual ~EntityAttribute();
   int type; // 1 str, 2 int, 3 double, 4 float, 5 image, 6 url
   std::string valueString;

   bool toStringReady;
   virtual string *toString() = 0;

   static const int TypeString = 1;
   static const int TypeInt = 2;
   static const int TypeDouble = 3;
   static const int TypeFloat = 4;
   static const int TypeImage = 5;
   static const int TypeUrl = 6;

};

#endif // ENTITYATTRIBUTE_H
