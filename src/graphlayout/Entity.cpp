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

#include <algorithm>
#include "Entity.h"
/**
 * @brief Entity::Entity
 */
Entity::Entity()
{
}

/**
 * @brief Entity::~Entity
 */
Entity::~Entity()
{
    //DEBUG_PRINT("Entity destructor: " );
    for(vector<EntityAttribute*>::iterator iter = attributes.begin(); iter != attributes.end() ; ++iter)
    {  EntityAttribute *entAttr = *iter;
        if (entAttr)
        {  delete entAttr;
        }
    }
}

/**
 * @brief Entity::toString
 * @return
 */
std::string Entity::toString()
{
    std::string ret;
    if ( !attributes.empty() )
    {
        for (unsigned int i=0; i<attributes.size(); i++)
        {
            ret += attributes.at(i)->valueString + ";" ;
        }
    }
    return ret;
}

bool Entity::removeEntityAttribute(int index)
{
    std::vector<EntityAttribute*>::iterator iter =   std::find(attributes.begin(),attributes.end(),attributes[index]);
	if ( iter!= attributes.end() )
	{
		delete (*iter);
		attributes.erase(iter);
		return true;
	}
	else
		return false;
}
