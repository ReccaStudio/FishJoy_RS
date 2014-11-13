#pragma once


#include "../Collision/CollisionContainer.h"
#include "SkillDelegate.h"
#include "Bullet.h"

class BulletNode :public CollisionContainer,public SkillDelegate
{
public:
	BulletNode();
	virtual~BulletNode();

	virtual bool init(BULLET_TYPE type = BULLET_TYPE::k_Bullet_Ball_1);

	static BulletNode * create();

	void playEffect(cocos2d::Vec2 targetInWorldSpace)override;

	void effectEndCallBack(Bullet * pBullet)override;


protected:
	
};

