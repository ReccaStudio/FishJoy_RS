#pragma once

#include "cocos2d.h"
#include "../Collision/CollisionSprite.h"
#include "EffectObserver.h"
#include "BulletCommon.h"


extern class SkillDelegate;


class Bullet:public CollisionSprite,public EffectObserver
{
public:
	
	virtual ~Bullet();

	virtual  void flyTo(cocos2d::Vec2 targetInWorldSpace) = 0;

	virtual  void end();

	virtual bool initEffect(const BULLET_TYPE & type);

	virtual void updateEffect()override;

	CC_SYNTHESIZE(BULLET_TYPE,m_eBulletType,BulletType);

	CC_SYNTHESIZE(SkillDelegate *,m_pSkillDelegate,SkillDelegate);

	//每个技能对精灵的设置都要回归初始化状态
	virtual void reset();

protected:
	Bullet(const BULLET_TYPE & type,const Unity_Clan & clanType = Unity_Clan::k_Bullet);

};

