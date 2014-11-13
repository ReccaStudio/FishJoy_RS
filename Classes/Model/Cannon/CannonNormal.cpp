#include "CannonNormal.h"
#include "../Classes/Model/StaticData.h"
#include "../Classes/GameConfig.h"
USING_NS_CC;
#include <algorithm>

CannonNormal::CannonNormal()
{
}

CannonNormal::~CannonNormal()
{

}



bool CannonNormal::init(WEAPON_TYPE type)
{
	std::string temp;
	temp = StringUtils::format(STATIC_DATA_STRING(GameConfig::CANNON_LEVEL_NAME).c_str(),type+1);
	this->initWithSpriteFrameName(temp);
	this->setCannonType(type);
	return true;
}

CannonNormal * CannonNormal::create(WEAPON_TYPE type)
{
	CannonNormal *pRet = new CannonNormal(); 
	if (pRet!=nullptr && pRet!=NULL&&pRet->init(type))
	{
		pRet->autorelease();
		return pRet;
	}
	else
	{
		delete pRet;
		pRet = nullptr;
		return nullptr;
	}
}




void CannonNormal::aimAt(cocos2d::Vec2 worldTarget)
{
	Vec2 location = this->getParent()->convertToWorldSpace(this->getPosition());

	Vec2 normalLizePoint  = worldTarget -location;
	//todo 为什么是0,1为起始参照点？ ---水平方位偏角
	float angle = normalLizePoint.getAngle(Vec2(0,1));
	this->setRotation(CC_RADIANS_TO_DEGREES(angle));
}