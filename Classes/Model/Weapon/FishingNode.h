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
	//炮台
	void aimAt(cocos2d::Vec2 worldTarget) override;

	//子弹
	bool shootTo(cocos2d::Vec2 touchLocation) override;

	////渔网
	////使用碰撞的一定是精灵，所以计算所有精灵的分数，然后返回容器的指针，在分数计算类中计算。
	//void capture(cocos2d::Vector<CollisionSprite *> * pv_Unitys) override;



protected:
	
	FishingNode():WeaponStrategy(){};
	

private:

};

