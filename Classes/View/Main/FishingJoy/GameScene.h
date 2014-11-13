#pragma once

#include "cocos2d.h"
#include "BackgroundLayer.h"
#include "FishLayer.h"
#include "CannonLayer.h"
#include "PanelLayer.h"
#include "MenuLayer.h"
#include "TouchLayer.h"

//强枚举，不支持int默认转化
typedef enum class OperateFlag
{
	k_Pause,
	k_Resume
};


class GameScene:public cocos2d::Scene
{
public:
	GameScene();
	~GameScene();

	bool init();

	CREATE_FUNC(GameScene);


	void pause();

	void resume();

	void switchSound();

	void switchMusic();

	void reset();

	void transToMainMenu();
	
	void cannnonAimAt(cocos2d::Vec2 target);

	void cannnonShootTo(cocos2d::Vec2 target);

	virtual void update(float delta);

protected:
	
	void operatorAllSchedulerAndAction(cocos2d::Node * pNode,OperateFlag flag);

	//todo
	void preloadResources();

	//碰撞检测相关
	void checkOutCollision();

	bool checkOutCollisionByAttacker(cocos2d::Vector<CollisionBase *> * pCollisionContainers,CollisionBase* pAttacker);

	void catchFishes(cocos2d::Vector<CollisionBase *> * pCollisionContainers,CollisionBase* pAttacker);

protected:

	BackgroundLayer * m_pBackgroundLayer;
	FishLayer* m_pFishLayer;
	CannonLayer * m_pCannonLayer;
	PanelLayer * m_pPanelLayer;
	MenuLayer * m_pMenuLayer;
	TouchLayer * m_pTouchLayer;


private:

};

