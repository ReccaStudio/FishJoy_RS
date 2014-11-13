#pragma once

#include "cocos2d.h"
#include "../Weapon/WeaponCommon.h"



class AbstractCannon:public cocos2d::Sprite
{
public:
	AbstractCannon():Sprite(){};
	virtual ~AbstractCannon(){};

	virtual bool init(WEAPON_TYPE type = WEAPON_TYPE::k_Bullet_1) = 0;

	CC_SYNTHESIZE(WEAPON_TYPE,m_eCannonType,CannonType);
	
	virtual void aimAt(cocos2d::Vec2 worldTarget) = 0;



protected:
};