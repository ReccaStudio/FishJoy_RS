#pragma once

#include "cocos2d.h"

typedef enum class Unity_Clan
{
	k_Bullet = 1,
	k_Fishing_Net = 1<<1,
	k_Fish_Type = 1|1<<1,
	//����δ������ײ��ռλ����
	k_Cannon_Type = 1<<3, 
	k_Weapon = 1<<4,
	k_Container = 1<<5,
	k_Normal = 0x00000000
};

class CollisionBase: virtual public cocos2d::Node
{

protected:
	Unity_Clan m_eUnityClan;
	
public:
	CollisionBase(Unity_Clan type = Unity_Clan::k_Normal):m_eUnityClan(type){};
	virtual ~CollisionBase(void) {};


	virtual Unity_Clan getUnityClan(void) const { return m_eUnityClan; }

	virtual void setUnityClan(Unity_Clan type) {m_eUnityClan = type; }

		//��ײ���
	virtual bool checkCollison(CollisionBase* other) = 0 ;

	virtual void beAttacked(CollisionBase* pActtckter) = 0;

	//����ʹ��ê��
	virtual cocos2d::Vec2 getCollisonPoint() = 0;

	//���Ի�ȡ����ģ�ͣ�ʧ����ʹ������߿�
	virtual cocos2d::Rect getCollisonArea() = 0;


};
