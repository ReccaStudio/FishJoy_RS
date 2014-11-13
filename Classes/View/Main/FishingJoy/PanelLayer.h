#pragma once 

#include "cocos2d.h"

class PanelLayer :public cocos2d::Layer
{
public:
	PanelLayer();
	~PanelLayer();

	bool init() override;

	void pause();

	CREATE_FUNC(PanelLayer);
private:

};