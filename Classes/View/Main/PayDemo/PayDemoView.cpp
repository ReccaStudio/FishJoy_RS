//
//  payDemoView.cpp
//  payDemo
//
//  Created by Íõ¾´ÕÜ
//
//

#include "PayDemoView.h"
#include "View/Login/LoginScene.h"
#include "GameConfig.h"
#include "SceneFactory.h"
USING_NS_CC;

//////////////////////////////
// 1. super init first
PayDemoView::PayDemoView()
:Layer()
,m_fTotalTime(0.0f)
,m_pLabel(NULL)
,m_pCloseItem(NULL)
,m_pMenu(NULL)
{
    
}
PayDemoView::~PayDemoView()
{

    
}
bool PayDemoView::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
	Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
	//log("IOS-------------PayDemoView:%d,%d,%d,%d",visibleSize.width,visibleSize.height,origin.x,origin.y);

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.
    


    
    /////////////////////////////
    // 3. add your codes below...
    
    // add a label shows "Hello World"
    // create and initialize a label
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	m_pLabel = Label::createWithTTF("PayDemoScene", "arial.ttf", 24);
#else if(CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 || CC_TARGET_PLATFORM ==  CC_PLATFORM_ANDROID)
	m_pLabel = Label::createWithTTF("PayDemoScene", "fonts/arial.ttf", 24);
#endif

    
    
    // position the label on the center of the screen
    m_pLabel->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - m_pLabel->getContentSize().height));
    
    // add the label as a child to this layer
    this->addChild(m_pLabel, 1);
    
    // add "payDemo" splash screen"
    Sprite* pSprite = Sprite::create("HelloWorld.png");
    
    // position the sprite on the center of the screen
    pSprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    
    // add the sprite as a child to this layer
    this->addChild(pSprite, 0);
    
	 m_pCloseItem = MenuItemImage::create(
                                                          "CloseNormal.png",
                                                          "CloseSelected.png",
                                                          CC_CALLBACK_1(PayDemoView::menuCloseCallback, this));
    
    
    
    // create menu, it's an autorelease object
    m_pMenu = cocos2d::Menu::create(m_pCloseItem, NULL);
	m_pCloseItem->setPosition(Vec2(origin.x + visibleSize.width - m_pCloseItem->getContentSize().width/2 ,origin.y + m_pCloseItem->getContentSize().height/2));
	m_pMenu->setPosition(Vec2::ZERO);


    this->addChild(m_pMenu, 1);

    return true;
}





void PayDemoView::onEnter()
{
	Layer::onEnter();
	this->schedule(schedule_selector(PayDemoView::cleanLogoScene));
}

void PayDemoView::cleanLogoScene(float logoTime)
{
    m_fTotalTime += logoTime;
    if (m_fTotalTime > 3.0f)
    {
		//Çå³þµ¥Àý
		LoginScene::getInstance()->destoyScene();
    }
}


void PayDemoView::menuCloseCallback(Ref* pSender)
{
	/*log("You pressed the close_button");


#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif*/
	Director * pDirector = Director::getInstance();
    pDirector->replaceScene(SceneFactory::create(GameConfig::CHOOSE_TABELVIEW));
}