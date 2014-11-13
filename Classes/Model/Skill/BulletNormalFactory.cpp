#include "BulletNormalFactory.h"
#include "Bullet.h"
#include "BulletNormal.h"
USING_NS_CC;




BulletNormalFactory::BulletNormalFactory()
{

	m_Pools.clear();

	for (int i = BULLET_TYPE::k_Normal_1; i < BULLET_TYPE::k_Normal_End; ++i)
	{
		addPool(BULLET_TYPE(i));
	}
}

BulletNormalFactory::~BulletNormalFactory()
{
	
}

BulletNormalFactory * BulletNormalFactory::s_BulletNormalFactory = nullptr;

BulletNormalFactory * BulletNormalFactory::getInstance()
{
	if (s_BulletNormalFactory == nullptr || s_BulletNormalFactory == NULL)
	{
		s_BulletNormalFactory = new BulletNormalFactory();

	}
	return s_BulletNormalFactory;
}

Bullet * BulletNormalFactory::createBullet(BULLET_TYPE type)
{
	return BulletNormal::create(type);
}