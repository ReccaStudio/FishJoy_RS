#include "EffectNormal.h"
#include "../Classes/Model/StaticData.h"
#include "../Classes/GameConfig.h"

USING_NS_CC;



EffectNormal::EffectNormal(const BULLET_TYPE &type):Effect(type)
{
}

EffectNormal::~EffectNormal()
{
}

bool EffectNormal::init(const BULLET_TYPE &type)
{
	this->initWithSpriteFrameName(STATIC_DATA_STRING(GameConfig::FISHING_NET_1));
	this->setVisible(false);
	return true;
}

//todo ÷ª≤∂◊Ω”„¿‡
void EffectNormal::excuteEffect(cocos2d::Vector<CollisionBase *> *pvUnitys)
{

}

void EffectNormal::resetEffect()
{
	//todo
	//do something
	this->notify();
}

EffectNormal * EffectNormal::create(const BULLET_TYPE & type)
{
	auto pRet = new EffectNormal(type);
	if (pRet&&pRet->init(type))
	{
		return pRet;
	}
	else
	{
		delete pRet;
		pRet = nullptr;
		return nullptr;
	}
}