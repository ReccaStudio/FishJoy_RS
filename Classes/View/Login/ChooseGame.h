#pragma once

#include "cocos2d.h"
#include "cocos/ui/UIPageView.h"

class ChooseGame:public cocos2d::Layer
{
public:
	ChooseGame();
	~ChooseGame();

	static ChooseGame * getInstance();

	void pageViewEvent(cocos2d::Ref* pSender, cocos2d::ui::PageView::EventType type);

protected:

	bool init();

	static ChooseGame * create();


private:
	static ChooseGame * s_pChooseGame;
};
