#include "Effect.h"
#include "../Classes/Model/StaticData.h"
#include "../Classes/GameConfig.h"
#include "EffectObserver.h"
USING_NS_CC;




Effect::Effect(const BULLET_TYPE & bulletType,Unity_Clan clanType):CollisionSprite(clanType),m_pBulletType(bulletType)
{
	m_pObvs = new std::list<EffectObserver *>();
}

Effect::~Effect()
{
	if (m_pObvs!=nullptr && m_pObvs!=NULL)
	{
		m_pObvs->clear();
		delete m_pObvs;
		m_pObvs= nullptr;
	}
	
}

bool Effect::init()
{
	this->initWithSpriteFrameName(STATIC_DATA_STRING(GameConfig::FISHING_NET_1));
	this->setVisible(false);
	return true;
}

//todo 只捕捉鱼类,执行技能计算 计算碰撞
void Effect::excuteEffect(cocos2d::Vector<CollisionBase *> *pvUnitys)
{

}

void Effect::resetEffect()
{
	//do something
	this->notify();
}

void Effect::attach(EffectObserver * obv)
{
	m_pObvs->push_back(obv);
}

void Effect::detach(EffectObserver * obv)
{
	if (obv!=nullptr && obv!=NULL)
	{
		m_pObvs->remove(obv);
	}
	
}

void Effect::notify()
{
	for (auto it = m_pObvs->begin(); it != m_pObvs->end(); ++it)
	{
		(*it)->updateEffect();
	}
}