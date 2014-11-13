#pragma once 

#include "cocos2d.h"

#include "./../Classes/Model/Weapon/FishingNode.h"

class CannonLayer :public cocos2d::Layer
{
public:
	CannonLayer();
	~CannonLayer();

	bool init() override;



	CREATE_FUNC(CannonLayer);



	CC_SYNTHESIZE_READONLY(FishingNode *,m_pWeaponNode,WeaponNode);

	bool shootTo(cocos2d::Vec2 touchLocation);
	void aimAt(cocos2d::Vec2 target);

	void catchFishes(cocos2d::Vector<CollisionBase *> * pCollisionContainers,CollisionBase* pAttacker);

protected:
	void switchCannon(cocos2d::Ref * sender);

	cocos2d::MenuItemSprite * m_pSubItem;
	cocos2d::MenuItemSprite * m_pAddItem;

private:

};
