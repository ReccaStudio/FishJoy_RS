#pragma once
#include "cocos2d.h"

#include "../Cannon/AbstractCannon.h"

class CannonNode:public cocos2d::Node
{
public:
	
	virtual~CannonNode();

	virtual bool init();

	CREATE_FUNC(CannonNode);

	CC_PROPERTY(WEAPON_TYPE,m_eCannonType,CannonType);

	AbstractCannon * getCannonSprite()const
	{
		return dynamic_cast<AbstractCannon*>(m_vPools.at(m_eCannonType));
	}
	void aimAt(cocos2d::Vec2 worldTarget);

protected:
	CannonNode();
	cocos2d::Vector<AbstractCannon *>m_vPools;
};

