#ifndef _TollgateScene_H_
#define _TollgateScene_H_

#include"cocos2d.h"
#include"Player.h"
#include "cocos-ext.h"


class TollgateScene:public cocos2d::Scene
{
public:
	TollgateScene();
	~TollgateScene();

	//static TollgateScene * getInstance();

	virtual bool init();

	CREATE_FUNC(TollgateScene);

	virtual void update(float delta);

	// a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

private:
	void initBackground();//初始化关卡背景
	
	void createJumpBtn();
	void jumpEvent(cocos2d::Ref * pSender,cocos2d::extension::ControlButton::EventType event);
	

	void createScoreLab(); //创建分数标签
	void createHPSlider(); //创建血量条

	void addPlayer();



	

private:

	float m_fScore;
	cocos2d::Label * m_pScoreLab;
	cocos2d::extension::ControlSlider * m_pHpSlider;


	cocos2d::Sprite * m_pBgSprite1;
	cocos2d::Sprite * m_pBgSprite2;
	Player * m_pPlayer;
	cocos2d::Size m_visibleSize;

	cocos2d::TMXTiledMap * m_pMap;

	//static TollgateScene * s_pScene;
};

#endif