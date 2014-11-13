#pragma once

#include "Bullet.h"



class BulletManager
{
public:
	BulletManager();
	~BulletManager();

	static BulletManager * getInstance();

	Bullet * requstBullet(const BULLET_TYPE &type);

	void returnBullet(Bullet * pBullet);

	/*inline cocos2d::Vector<Bullet*> & getUsingBullet()
	{
		return m_vUsingBullet;
	}*/


private:
	static BulletManager * s_BulletManager;
	//cocos2d::Vector<Bullet*> m_vUsingBullet;
};

