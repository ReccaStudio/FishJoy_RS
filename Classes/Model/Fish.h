#pragma once

#include "cocos2d.h"
#include "Collision/CollisionContainer.h"

typedef enum FishType
{
	k_Red = 0,
	k_Yellow,
	k_Count
};

extern class CollisionSprite;

class Fish:public CollisionContainer
{
public:
	Fish();
	~Fish();

	static Fish * create(FishType type = FishType::k_Red);
	bool init(FishType type = FishType::k_Red);

	//do nothing
	virtual void beAttacked(CollisionBase* pActtckter){};

	CC_SYNTHESIZE_READONLY(CollisionSprite * ,m_pFishSpritre,FishSprite);
	CC_SYNTHESIZE_READONLY(FishType,m_Type,Type);

private:
	
};

