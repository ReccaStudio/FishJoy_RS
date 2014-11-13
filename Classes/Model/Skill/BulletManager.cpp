
#include "BulletManager.h"
#include "BulletNormalFactory.h"
#include "BulletBallFactory.h"


BulletManager::BulletManager()
{
//	m_vUsingBullet.clear();
}

BulletManager::~BulletManager()
{
}

BulletManager * BulletManager::s_BulletManager = nullptr;

BulletManager * BulletManager::getInstance()
{
	if (s_BulletManager == nullptr || s_BulletManager == NULL)
	{
		s_BulletManager = new BulletManager();

	}
	return s_BulletManager;
}

Bullet * BulletManager::requstBullet(const BULLET_TYPE &type)
{
	Bullet * p= nullptr;
	switch (type)
	{
	case BULLET_TYPE::k_Normal_1:

	case BULLET_TYPE::k_Normal_2:

	case BULLET_TYPE::k_Normal_3:
		p = BulletNormalFactory::getInstance()->requstBullet(type);
		//m_vUsingBullet.pushBack(p);
		break;


	case BULLET_TYPE::k_Bullet_Ball_1:
		p = BulletBallFactory::getInstance()->requstBullet(type);
		//m_vUsingBullet.pushBack(p);
		break;


	case BULLET_TYPE::k_Bullet_Invalid:
		break;
	default:
		break;
	}
	CCAssert(p!=nullptr && p!=NULL,"Bullet is empty");
	return p;
}

void BulletManager::returnBullet(Bullet * pBullet)
{
	/*auto it = m_vUsingBullet.find(pBullet);
	if (it!= m_vUsingBullet.end())
	{
		m_vUsingBullet.erase(it);
	}*/
	auto type = pBullet->getBulletType();
	switch (type)
	{
	case BULLET_TYPE::k_Normal_1:
	case BULLET_TYPE::k_Normal_2:
	case BULLET_TYPE::k_Normal_3:
		BulletNormalFactory::getInstance()->returnBullet(pBullet);
		break;


	case BULLET_TYPE::k_Bullet_Ball_1:
		BulletBallFactory::getInstance()->returnBullet(pBullet);
		break;

	case BULLET_TYPE::k_Bullet_Invalid:
		break;
	default:
		break;
	}

	
}