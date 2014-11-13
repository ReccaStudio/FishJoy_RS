#pragma once
#include "cocos2d.h"
#include "../Collision/CollisionContainer.h"

#include "WeaponCommon.h"

#include "../Cannon/CannonNode.h"
#include "../Skill/BulletNode.h"


extern class WeaponManager;
extern class CollisionSprite;

class WeaponStrategy:public cocos2d::Node
{
	//暂时不适用buff
	CC_SYNTHESIZE_READONLY(float,m_fColdDownRemain,ColdDownRemain);

	CC_SYNTHESIZE(float,m_fColdDownTime,ColdDownTime);


	protected: CannonNode * m_pCannonNode;
	public: virtual CannonNode * getCannonNode(void) const { return m_pCannonNode; }

	protected: BulletNode * m_pBulletNode;
	public: virtual BulletNode * getBulletNode(void) const { return m_pBulletNode; }

public:
	WeaponStrategy():Node(),m_fColdDownTime(0.5f),m_fColdDownRemain(0.0f)
	{
		m_pCannonNode = CannonNode::create();
		this->addChild(m_pCannonNode);

		m_pBulletNode = BulletNode::create();
		this->addChild(m_pBulletNode);

	};
	virtual ~WeaponStrategy()
	{
		
	};

	

	virtual void update(float delta)override
	{
		m_fColdDownRemain-=delta;
		if (isInColdDown())
		{
			this->unscheduleUpdate();
		}
	}

	virtual int getWeaponStatus()
	{
		if (isInColdDown())
		{
			return WEAPON_STATUS::k_Colding;
		}
		else
		{
			return WEAPON_STATUS::k_Ready;
		}
	}

	////渔网
	////使用碰撞的一定是精灵，所以计算所有精灵的分数，然后返回容器的指针，在分数计算类中计算。
	//virtual void capture(cocos2d::Vector<CollisionSprite *> * pv_Unitys) = 0;

	

	virtual  bool isInColdDown()
	{
		return m_fColdDownRemain>0.0f;
	}

	virtual bool canShootAble()
	{
		if(getWeaponStatus()==WEAPON_STATUS::k_Ready)
			return true;
		else
		{
			return false;
		}
	}

	friend WeaponManager;


	//炮台
	virtual void aimAt(cocos2d::Vec2 worldTarget) = 0;

	//子弹
	virtual bool shootTo(cocos2d::Vec2 touchLocation) = 0;

	void switchWeapon(SWITCH_OPERATOR oper)
	{
		switch (oper)
		{
		case k_Add:
			setCurWeaponType(WEAPON_TYPE(m_pCannonNode->getCannonType()+1));

			break;
		case k_Minus:
			setCurWeaponType(WEAPON_TYPE(m_pCannonNode->getCannonType()-1));

			break;
		default:
			break;
		}
	}

	virtual void setCurWeaponType(WEAPON_TYPE type)
	{
		m_pCannonNode->setCannonType(type);
		
		//todo
		m_pBulletNode->setCurSkillType(BULLET_TYPE::k_Normal_1);
	}

	virtual WEAPON_TYPE getCurWeaponType()
	{
		return m_pCannonNode->getCannonType();
	}

	
protected:
	

private:
	void create();
};

