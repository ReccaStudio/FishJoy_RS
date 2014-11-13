#include "BulletNormal.h"
#include "./../Classes/Model/StaticData.h"
#include "./../Classes/GameConfig.h"

USING_NS_CC;

BulletNormal::BulletNormal(const BULLET_TYPE &type):Bullet(type)
{
	m_pEffect= nullptr;
}

BulletNormal::~BulletNormal()
{
}


BulletNormal* BulletNormal::create(const BULLET_TYPE &type) 
{ 
    BulletNormal *pRet = new BulletNormal(type); 
    if (pRet && pRet->init(type)) 
    { 
        pRet->autorelease(); 
        return pRet; 
    } 
    else 
    { 
        delete pRet; 
        pRet = NULL; 
        return NULL; 
    } 
}

bool BulletNormal::init(const BULLET_TYPE &type)
{ //todo
	switch (type)
	{
	case BULLET_TYPE::k_Normal_1:
		this->initWithSpriteFrameName(STATIC_DATA_STRING(GameConfig::BULLET_1));
		return true;
		break;
	case BULLET_TYPE::k_Normal_2:
		this->initWithSpriteFrameName(STATIC_DATA_STRING(GameConfig::BULLET_2));
		return true;
		break;
	case BULLET_TYPE::k_Normal_3:
		this->initWithSpriteFrameName(STATIC_DATA_STRING(GameConfig::BULLET_3));
		return true;
		break;
	case BULLET_TYPE::k_Normal_End:
		return false;
		break;
	default:
		return false;
		break;
	}

	
}

void BulletNormal::flyTo(cocos2d::Vec2 targetInWorldSpace)
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

void BulletNormal::end()
{
	if (m_pEffect==nullptr||m_pEffect==NULL)
	{
		initEffect(this->getBulletType());
	}
	
	this->stopActionByTag(BULLET_ANCTION::k_Action_1);
	//todo
	//m_pEffect->excuteEffect();
	this->setVisible(false);
	//todo 消息分发
}
