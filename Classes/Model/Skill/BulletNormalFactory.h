#pragma once

#include "cocos2d.h"
#include "AbstractBulletFactory.h"


class BulletNormalFactory:public AbstractBulletFactory
{
public:
	BulletNormalFactory();
	~BulletNormalFactory();

	static BulletNormalFactory * getInstance();

protected:
	virtual Bullet * createBullet(BULLET_TYPE type)override;

private:
	static BulletNormalFactory * s_BulletNormalFactory;




};

