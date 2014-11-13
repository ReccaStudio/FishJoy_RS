#include "TouchLayer.h"
#include "GameScene.h"
USING_NS_CC;

TouchLayer::TouchLayer():Layer()
{
}

TouchLayer::~TouchLayer()
{
}

bool TouchLayer::init(void)
{
	Layer::init();

	//此处可以使用auto缩短书写，但是要熟悉api就自己敲打
	EventListenerTouchOneByOne * listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);
	listener->onTouchBegan = CC_CALLBACK_2(TouchLayer::onTouchBegan,this);
	listener->onTouchMoved = CC_CALLBACK_2(TouchLayer::onTouchMoved,this);
	listener->onTouchEnded = CC_CALLBACK_2(TouchLayer::onTouchEnded,this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener,this);


	/*EventListenerTouchOneByOne * listener = EventListenerTouchOneByOne::create();

	 listener->onTouchBegan = [](Touch* touch, Event* event){ 
                         auto target = dynamic_cast<Sprite*>(event->getCurrentTarget());
                         if(target == nullptr) 
                                  log("111111111111"); 
                         else 
                                  log("tag = %d", target->getTag());
                          return true;
                 }; 
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener,this);*/
	return true;
}

bool TouchLayer::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event)
{
	this->getGameScene()->cannnonAimAt(this->locationtFromTouch(touch));

	return true;
}

void TouchLayer::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unused_event)
{
	this->getGameScene()->cannnonAimAt(this->locationtFromTouch(touch));
}
void TouchLayer::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event)
{
	this->getGameScene()->cannnonShootTo(this->locationtFromTouch(touch));
}



GameScene * TouchLayer::getGameScene()
{
	return dynamic_cast<GameScene*>(this->getParent());
}

cocos2d::Vec2 TouchLayer::locationtFromTouch(cocos2d::Touch * pTouch)
{
	return Director::getInstance()->convertToGL(pTouch->getLocationInView());
}

void TouchLayer::onEnter()
{
	Layer::onEnter();
}

void TouchLayer::onExit()
{
	Layer::onExit();
}