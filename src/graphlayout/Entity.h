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


#ifndef ENTITY_H
#define ENTITY_H

#include <vector>
#include <string>
#include "EntityAttribute.h"

using namespace std;
class Entity
{
public:
    Entity();
    ~Entity();
    bool removeEntityAttribute(int index);

    vector<EntityAttribute*> attributes;
    //QString toQString();
    std::string toString();
};

#endif // ENTITY_H
