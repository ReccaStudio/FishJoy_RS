#pragma once;
#include "cocos2d.h"
#include "Bullet.h"
#include "BulletManager.h"

class SkillDelegate
{
public:

	CC_SYNTHESIZE_READONLY(Bullet *,m_pBullet,Bullet);

	virtual void setCurSkillType(BULLET_TYPE type)
	{
		auto temp = BulletManager::getInstance()->requstBullet(type);
		CC_SAFE_RETAIN(temp);
		if (m_pBullet!=nullptr || m_pBullet!=NULL)
		{
			CC_SAFE_RELEASE(m_pBullet);
		}
		m_eCurType = type;
		m_pBullet = temp;

	}

	virtual BULLET_TYPE getCurSkillType()
	{
		return m_pBullet->getBulletType();
	}

	virtual void playEffect(cocos2d::Vec2 targetInWorldSpace) = 0;

	virtual void effectEndCallBack(Bullet *) = 0;

	virtual ~SkillDelegate(){};


protected:
	SkillDelegate(){};

protected:
	BULLET_TYPE m_eCurType;
};


