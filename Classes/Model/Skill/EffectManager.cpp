
#include "EffectManager.h"
#include "Effect.h"
#include "EffectNormalFactory.h"



EffectManager::EffectManager()
{
//	m_vUsingEffect.clear();
}

EffectManager::~EffectManager()
{
}

EffectManager * EffectManager::s_EffectManager = nullptr;

EffectManager * EffectManager::getInstance()
{
	if (s_EffectManager == nullptr || s_EffectManager == NULL)
	{
		s_EffectManager = new EffectManager();

	}
	return s_EffectManager;
}

Effect * EffectManager::requstEffect(const BULLET_TYPE &type)
{
	Effect * p= nullptr;
	switch (type)
	{
	case BULLET_TYPE::k_Normal_1:

	case BULLET_TYPE::k_Normal_2:

	case BULLET_TYPE::k_Normal_3:
		p = EffectNormalFactory::getInstance()->requstEffect(type);
		//m_vUsingEffect.pushBack(p);
		break;


	case BULLET_TYPE::k_Bullet_Ball_1:
		p = EffectNormalFactory::getInstance()->requstEffect(type);
		//m_vUsingEffect.pushBack(p);
		break;


	case BULLET_TYPE::k_Bullet_Invalid:
		break;
	default:
		break;
	}
	
	return p;
}

void EffectManager::returnEffect(Effect * pEffect)
{
	/*auto it = m_vUsingEffect.find(pEffect);
	if (it!= m_vUsingEffect.end())
	{
		m_vUsingEffect.erase(it);
	}*/
	auto type = pEffect->getBulletType();
	switch (type)
	{
	case BULLET_TYPE::k_Normal_1:
	case BULLET_TYPE::k_Normal_2:
	case BULLET_TYPE::k_Normal_3:
		EffectNormalFactory::getInstance()->returnEffect(pEffect);
		break;


	case BULLET_TYPE::k_Bullet_Ball_1:
		EffectNormalFactory::getInstance()->returnEffect(pEffect);
		break;

	case BULLET_TYPE::k_Bullet_Invalid:
		break;
	default:
		break;
	}

	
}