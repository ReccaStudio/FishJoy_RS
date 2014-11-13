#include "EffectNormalFactory.h"
#include "Effect.h"
#include "EffectNormal.h"
USING_NS_CC;




EffectNormalFactory::EffectNormalFactory()
{

	m_Pools.clear();

	

	for (int i = BULLET_TYPE::k_Normal_1; i < BULLET_TYPE::k_Normal_End; ++i)
	{
		auto p = new std::map<Effect*,bool>();
		p->clear();
		m_Pools.insert(std::make_pair(BULLET_TYPE(i),p));
		for (int j = 0; j < COUNT; ++j)
		{
			auto temp = EffectNormal::create(BULLET_TYPE(j));
			CCAssert(temp!=nullptr && temp != NULL,"failed to create BulletNormal");
			p->insert(std::make_pair(temp,false));
		}
	}

	


}

EffectNormalFactory::~EffectNormalFactory()
{
	for (auto it = m_Pools.begin(); it !=m_Pools.end(); )
	{
		auto  pMap= (*it).second;
		pMap->clear();
		delete pMap;
		m_Pools.erase(it);
	}
}

EffectNormalFactory * EffectNormalFactory::s_EffectNormalFactory = nullptr;

EffectNormalFactory * EffectNormalFactory::getInstance()
{
	if (s_EffectNormalFactory == nullptr || s_EffectNormalFactory == NULL)
	{
		s_EffectNormalFactory = new EffectNormalFactory();

	}
	return s_EffectNormalFactory;
}

void EffectNormalFactory::increaseEffects(std::map<Effect*,bool> * pEffectPool,BULLET_TYPE type)
{
	for (int i = 0; i < INC; ++i)
	{
		pEffectPool->insert(std::make_pair(EffectNormal::create(type),false));
	}
	
}