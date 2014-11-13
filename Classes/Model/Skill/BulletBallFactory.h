#pragma once

#include "cocos2d.h"
#include "AbstractBulletFactory.h"


class BulletBallFactory:public AbstractBulletFactory
{
public:
	BulletBallFactory();
	~BulletBallFactory();

	static BulletBallFactory * getInstance();

protected:
	virtual Bullet * createBullet(BULLET_TYPE type)override;;

private:
	static BulletBallFactory * s_BulletBallFactory;


};