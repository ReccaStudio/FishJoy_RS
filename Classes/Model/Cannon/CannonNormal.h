#pragma once

#include "cocos2d.h"
#include "../Weapon/WeaponCommon.h"
#include "AbstractCannon.h"


class CannonNormal:public AbstractCannon
{
public:
	CannonNormal();
	~CannonNormal();
	
	bool init(WEAPON_TYPE type = WEAPON_TYPE::k_Bullet_1)override;

	static CannonNormal * create(WEAPON_TYPE type = WEAPON_TYPE::k_Bullet_1);
	
	void aimAt(cocos2d::Vec2 worldTarget)override;

};