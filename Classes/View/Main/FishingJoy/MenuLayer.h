#pragma once 

#include "cocos2d.h"

class MenuLayer :public cocos2d::Layer
{
public:
	MenuLayer();
	~MenuLayer();

	bool init() override;

	void createMenu();

	void createBackground();

	void setSoundAndMusicVolume(float soundVolume,float musicVolume);

	CREATE_FUNC(MenuLayer);

	void resume(cocos2d::Ref * pSender);

	void transToMainMenu(cocos2d::Ref * pSender);

	void switchSound();

	void switchMusic();

	void reset(cocos2d::Ref * pSender);

protected:
	cocos2d::MenuItemToggle * m_pSound;

	cocos2d::MenuItemToggle * m_pMusic;

private:
	
};