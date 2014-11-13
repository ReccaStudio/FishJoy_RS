#include "BackgroundLayer.h"
USING_NS_CC;
#include "./../Classes/Model/StaticData.h"
#include "GameConfig.h"


BackgroundLayer::BackgroundLayer():Layer()
{

}

BackgroundLayer::~BackgroundLayer()
{
}

bool BackgroundLayer::init()
{
	if (Layer::init())
	{
		Sprite *pBack = Sprite::createWithSpriteFrameName(STATIC_DATA_STRING(GameConfig::GAME_BACKGROUND_FILENAME));

		Size visibleSize = Director::getInstance()->getVisibleSize();
		Vec2 origin = Director::getInstance()->getVisibleOrigin();

		pBack->setPosition(origin.x+visibleSize.width/2,origin.y+visibleSize.height/2);
		pBack->setScale(visibleSize.width/pBack->getContentSize().width,visibleSize.height/pBack->getContentSize().height);


		this->addChild(pBack);
		return true;
	}
	return false;
}