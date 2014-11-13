#include "BulletBallFactory.h"
#include "Bullet.h"
#include "BulletBall.h"
USING_NS_CC;




BulletBallFactory::BulletBallFactory()
{

	m_Pools.clear();


	for (int i = BULLET_TYPE::k_Bullet_Ball_1; i < BULLET_TYPE::k_Bullet_Ball_End; ++i)
	{
		addPool(BULLET_TYPE(i));
	}


}

BulletBallFactory::~BulletBallFactory()
{

}

BulletBallFactory * BulletBallFactory::s_BulletBallFactory = nullptr;

BulletBallFactory * BulletBallFactory::getInstance()
{
	if (s_BulletBallFactory == nullptr || s_BulletBallFactory == NULL)
	{
		s_BulletBallFactory = new BulletBallFactory();

	}
	return s_BulletBallFactory;
}


Bullet * BulletBallFactory::createBullet(BULLET_TYPE type)
{
	return BulletBall::create(type);
}