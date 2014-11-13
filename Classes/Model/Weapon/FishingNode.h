#pragma once
#include "cocos2d.h"
#include "WeaponStrategy.h"

extern class Cannon;
extern class Bullet;
extern class NetNormal;
extern class CollisionBase;


class FishingNode :public WeaponStrategy
{
public:
	virtual~FishingNode(){};
	static FishingNode * create(WEAPON_TYPE type = WEAPON_TYPE::k_Bullet_1);
	bool init(WEAPON_TYPE type = WEAPON_TYPE::k_Bullet_1);

	//WeaponStrategy
	//��̨
	void aimAt(cocos2d::Vec2 worldTarget) override;

	//�ӵ�
	bool shootTo(cocos2d::Vec2 touchLocation) override;

	////����
	////ʹ����ײ��һ���Ǿ��飬���Լ������о���ķ�����Ȼ�󷵻�������ָ�룬�ڷ����������м��㡣
	//void capture(cocos2d::Vector<CollisionSprite *> * pv_Unitys) override;



protected:
	
	FishingNode():WeaponStrategy(){};
	

private:

};

