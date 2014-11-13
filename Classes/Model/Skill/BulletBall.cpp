#include "BulletBall.h"
#include "./../Classes/Model/StaticData.h"
#include "./../Classes/GameConfig.h"

USING_NS_CC;

BulletBall::BulletBall(const BULLET_TYPE &type):Bullet(type)
{

}

BulletBall::~BulletBall()
{
}


BulletBall* BulletBall::create(const BULLET_TYPE &type) 
{ 
    BulletBall *pRet = new BulletBall(type); 
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
bool BulletBall::init(const BULLET_TYPE &type)
{ 
	this->initWithSpriteFrameName(STATIC_DATA_STRING(GameConfig::BULLET_1));
	return true;
	//todo
	/*switch (type)
	{
	case BULLET_TYPE::k_Bullet_Ball_1:
		
		break;
	case BULLET_TYPE::k_Bullet_Invalid:
		break;
	default:
		break;
	}
	
	return false;*/
}

void BulletBall::flyTo(cocos2d::Vec2 targetInWorldSpace)
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

void BulletBall::end()
{
	this->stopActionByTag(BULLET_ANCTION::k_Action_1);
	this->setVisible(false);
	//todo 消息分发
}
