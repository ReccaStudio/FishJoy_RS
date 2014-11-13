#include "Bullet.h"
#include "./../Classes/Model/StaticData.h"
#include "./../Classes/GameConfig.h"
#include "SkillDelegate.h"
#include "EffectManager.h"
#include "Effect.h"

USING_NS_CC;

Bullet::Bullet(const BULLET_TYPE & bulletType,const Unity_Clan & unityType):CollisionSprite(unityType),m_eBulletType(bulletType),EffectObserver()
{
}

Bullet::~Bullet()
{
}


void Bullet::flyTo(cocos2d::Vec2 targetInWorldSpace)
{
	this->setVisible(true);
	//设置方向
	Vec2 startInNodeSpace = Vec2::ZERO;
	Vec2 startInWorldSpace = this->getParent()->convertToWorldSpace(startInNodeSpace);
	Vec2 targetInNodeSpace = this->getParent()->convertToNodeSpace(targetInWorldSpace);
	Vec2 normal = targetInWorldSpace-startInWorldSpace;

	float angle = normal.getNormalized().getAngle(Vec2(0,1));
	this->setRotation(CC_RADIANS_TO_DEGREES(angle));

	this->setPosition(startInNodeSpace);
	this->setVisible(true);

	float speed = STATIC_DATA_FLOAT(GameConfig::BULLET_SPEED_NORMAL);
	float duration = startInNodeSpace.getDistance(targetInNodeSpace)/speed;


	MoveTo * pMove = MoveTo::create(duration,targetInNodeSpace);
	
	FiniteTimeAction * pSeq = Sequence::create(pMove,CallFunc::create(CC_CALLBACK_0(Bullet::end,this)),nullptr);
	pSeq->setTag(BULLET_ANCTION::k_Action_1);
	this->runAction(pSeq);

}

void Bullet::end()
{
	this->stopActionByTag(BULLET_ANCTION::k_Action_1);
	this->setVisible(false);
	
}

void Bullet::reset()
{
	this->setVisible(false);
	this->setPosition(0.0f,0.0f);
	this->setScale(1.0f);

}

void Bullet::updateEffect()
{
	this->reset();
	m_pSkillDelegate->effectEndCallBack(this);
	//todo 消息分发
};

bool Bullet::initEffect(const BULLET_TYPE & type)
{
	auto temp = EffectManager::getInstance()->requstEffect(type);
	CC_SAFE_RETAIN(temp);
	if (m_pEffect!=nullptr && m_pEffect !=NULL)
	{
		CC_SAFE_RELEASE(m_pEffect);
	}
	m_pEffect = EffectManager::getInstance()->requstEffect(type);
	
	m_pEffect->attach(this);
	return true;
}