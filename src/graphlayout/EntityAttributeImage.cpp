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


#include "EntityAttributeImage.h"


EntityAttributeImage::EntityAttributeImage()
{  type = EntityAttribute::TypeImage;
   valueString.assign("");
   toStringReady = true; // always ready.
}


EntityAttributeImage::~EntityAttributeImage()
{  //DEBUG_PRINT("EntityAttributeImage destructor");
}


string *EntityAttributeImage::toString()
{

   return &valueString;
}

void EntityAttributeImage::setValue(string s)
{  valueString.assign(s);
}

