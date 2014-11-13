//
//  LogoView.cpp
//  payDemo
//
//  Created by 王敬哲 on 13-12-2.
//
//

#include "LogoView.h"
USING_NS_CC;
#include "Tools/AnimationUtil.h"

//////////////////////////////
// 1. super init first
LogoView::LogoView()
:Layer()
,m_CCNode(NULL)
,m_logoSprite(NULL)
{
    
}
LogoView::~LogoView()
{

}
bool LogoView::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
	Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    //载入资源0.X秒白屏，即第三方LOGO前用2.X秒白屏

    m_CCNode = LayerColor::create(Color4B(255, 255, 255, 255),visibleSize.width,visibleSize.height);
	CCAssert(m_CCNode!=NULL,"白屏创建失败");
	this->addChild(m_CCNode);
    m_CCNode->ignoreAnchorPointForPosition(false);
	m_CCNode->setAnchorPoint(Vec2(0.0f, 0.0f));
    m_CCNode->setPosition(Vec2(0,0));
    
	m_logoSprite = Sprite::create("CloseNormal.png");
	this->addChild(m_logoSprite);
    m_logoSprite->ignoreAnchorPointForPosition(false);
    m_logoSprite->setAnchorPoint(Vec2(0.0f, 0.0f));
    m_logoSprite->setPosition(Vec2(0,0));

	Animate * ani = Animate::create(AnimationUtil::createAnimWithSingleFrameN("run",0.05,4));
	TextureCache::getInstance()->addImage("player.png");
	Sprite *pSprite = Sprite::createWithTexture(TextureCache::getInstance()->getTextureForKey("player.png"));
	//Sprite *pSprite = Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("player.png"));
	pSprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
	pSprite->runAction(ani);
	this->addChild(pSprite);
    return true;
}


void LogoView::menuCloseCallback(Ref* pSender)
{
	Director::getInstance()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

