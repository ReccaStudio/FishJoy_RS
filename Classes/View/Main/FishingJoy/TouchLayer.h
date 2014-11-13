#pragma once

#include "cocos2d.h"

class GameScene;

class TouchLayer:public cocos2d::Layer
{
public:
	TouchLayer();
	~TouchLayer();
	CREATE_FUNC(TouchLayer);
	bool init(void);

	virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event); 
    virtual void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unused_event); 
    virtual void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event); 

	virtual void onEnter() override;

	virtual void onExit() override;

protected:
	
	GameScene * getGameScene();

	cocos2d::Vec2 locationtFromTouch(cocos2d::Touch * pTouch);

private:

};

