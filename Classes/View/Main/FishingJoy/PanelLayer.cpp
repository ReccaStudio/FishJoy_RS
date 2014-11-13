#include "PanelLayer.h"
#include <cstring>
#include "./../Classes/Model/StaticData.h"
#include "./../Classes/GameConfig.h"


USING_NS_CC;

#include "GameScene.h"

PanelLayer::PanelLayer():Layer()
{
}

PanelLayer::~PanelLayer()
{
}

bool PanelLayer::init()
{
	if (Layer::init())
	{
		Size winSize = Director::getInstance()->getVisibleSize();

		std::string pauseNormal =  STATIC_DATA_STRING(GameConfig::PAUSE_NORMAL);

		std::string pauseSeleted =  STATIC_DATA_STRING(GameConfig::PAUSE_SELECT);

		MenuItemSprite* pause = MenuItemSprite::create(Sprite::createWithSpriteFrameName(pauseNormal),Sprite::createWithSpriteFrameName(pauseSeleted),CC_CALLBACK_0(PanelLayer::pause,this));
		Menu * pMenu = Menu::create(pause,nullptr);
		pMenu->setPosition(winSize.width-pause->getContentSize().width*0.5,pause->getContentSize().height*0.5);

		this->addChild(pMenu);
		return true;
	}
	return false;
}

void PanelLayer::pause()
{
	GameScene * p = dynamic_cast<GameScene *>(this->getParent());
	p->pause();
}