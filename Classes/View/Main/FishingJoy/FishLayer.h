#pragma once 
#include "./../Classes/Model/Fish.h"
#include "cocos2d.h"

class FishLayer :public cocos2d::Layer
{
public:
	FishLayer();
	~FishLayer();

	bool init() override;

	void addFish(float dt);

	CREATE_FUNC(FishLayer);

	CC_SYNTHESIZE_READONLY(int,m_iCapscity,Capscity);
private:
	cocos2d::Vector<Fish*> m_vFishes;
};

