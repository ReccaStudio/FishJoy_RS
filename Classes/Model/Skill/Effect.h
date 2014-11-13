#pragma once

#include "cocos2d.h"
#include "../Collision/CollisionSprite.h"
#include <list>
#include "BulletCommon.h"


extern class EffectObserver;

class Effect:public CollisionSprite
{
public:
	
	virtual ~Effect();
	
	virtual bool init()override;
	
	//todo 只捕捉鱼类,执行技能计算 计算碰撞
	virtual void excuteEffect(cocos2d::Vector<CollisionBase *> *pvUnitys) = 0;

	//updateState
	virtual void resetEffect() = 0;

	CC_SYNTHESIZE_READONLY(BULLET_TYPE,m_pBulletType,BulletType);

	virtual void attach(EffectObserver * obv);

	virtual void detach(EffectObserver * obv);

	virtual void notify();

protected:
	Effect(const BULLET_TYPE & bulletType,Unity_Clan clanType = Unity_Clan::k_Fishing_Net);

private:
	std::list<EffectObserver *> *  m_pObvs;

};