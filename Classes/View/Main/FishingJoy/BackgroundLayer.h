#pragma once 
#include "cocos2d.h"

class BackgroundLayer:public cocos2d::Layer
{
public:
	BackgroundLayer();
	~BackgroundLayer();

	bool init();

	CREATE_FUNC(BackgroundLayer);

private:

};

