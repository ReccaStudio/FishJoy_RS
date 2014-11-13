#include "TollgateScene.h"
#include "MonsterManager.h"
#include "GameConfig.h"
#include "SceneFactory.h"
USING_NS_CC;
USING_NS_CC_EXT;

//TollgateScene * TollgateScene::s_pScene = nullptr;

TollgateScene::TollgateScene():Scene(),m_pBgSprite1(NULL),m_pBgSprite2(NULL),m_pPlayer(NULL),m_fScore(0),m_pScoreLab(NULL),m_pHpSlider(NULL),m_pMap(NULL)
{
	
}

TollgateScene::~TollgateScene()
{
	
}

// TollgateScene * TollgateScene::getInstance()
//{
//	if (s_pScene==nullptr||s_pScene==NULL)
//	{
//		do
//		{
//
//			s_pScene = TollgateScene::create();
//			CC_BREAK_IF(!s_pScene);
//
//		} while (0);
//	
//	}
//	
//	return s_pScene;
//}

bool TollgateScene::init()
{
	m_visibleSize = Director::getInstance()->getVisibleSize();
	bool bRet = false;
	do
	{


#if (CC_TARGET_PLATFORM ==CC_PLATFORM_IOS)
		Label * pTitleSprite = Label::createWithTTF("RuningDemo","arial.ttf",34);
#else
		Label * pTitleSprite = Label::createWithTTF("RuningDemo","fonts/arial.ttf",34);
#endif
		pTitleSprite->setPosition(Vec2(m_visibleSize.width/2,m_visibleSize.height-50));
		
		this->addChild(pTitleSprite,2);


		//m_pMap = TMXTiledMap::create("level01.tmx");

		//TMXLayer * pGroundLayer = m_pMap->layerNamed("ground");
		//this->addChild(m_pMap);
		//addPlayer();

		




		//创建主角

		m_pPlayer = Player::create();
		m_pPlayer->blindSprite(Sprite::create("sprite.png"));
		m_pPlayer->getSprite()->setPosition(Vec2(200,m_visibleSize.height/4));
		this->addChild(m_pPlayer,1);

		//初始化背景图片
		initBackground();

		createJumpBtn();

		this->scheduleUpdate();

		//this->addChild(MonsterManager::getInstance()->getMonsterBatchNode());
		MonsterManager::getInstance()->bindPlayer(m_pPlayer);
		this->addChild(MonsterManager::getInstance());

		createScoreLab(); //创建分数标签
		createHPSlider(); //创建血量条


		auto m_pCloseItem = MenuItemImage::create(
                                                          "CloseNormal.png",
                                                          "CloseSelected.png",
                                                          CC_CALLBACK_1(TollgateScene::menuCloseCallback, this));
    
    
    
    // create menu, it's an autorelease object
    auto m_pMenu = cocos2d::Menu::create(m_pCloseItem, NULL);
	m_pCloseItem->setPosition(Vec2(m_visibleSize.width - m_pCloseItem->getContentSize().width/2 ,m_pCloseItem->getContentSize().height/2));
	m_pMenu->setPosition(Vec2::ZERO);


    this->addChild(m_pMenu, 1);


		bRet = true;
	} while (0);
	return bRet;
}

void TollgateScene::initBackground() //初始化关卡背景
{
	
	m_visibleSize = Director::getInstance()->getVisibleSize();
	m_pBgSprite1 = Sprite::create("tollgateBG.jpg");
	m_pBgSprite1->setPosition(Vec2(m_visibleSize.width/2,m_visibleSize.height/2));
	m_pBgSprite1->setScale(1.2,1.8);
	this->addChild(m_pBgSprite1,0);

	m_pBgSprite2 = Sprite::create("tollgateBG.jpg");
	m_pBgSprite2->setPosition(Vec2(m_visibleSize.width+m_visibleSize.width/2,m_visibleSize.height/2));
	m_pBgSprite2->setFlippedX(true);//水平翻精灵？？？
	m_pBgSprite2->setScale(1.2,1.8);
	this->addChild(m_pBgSprite2,0);

	
}

void TollgateScene::update(float delta)
{
	int posX1 = m_pBgSprite1->getPositionX();    //背景地图1的X坐标
	int posX2 = m_pBgSprite2->getPositionX();    //背景地图2的X坐标

	int iSpeed = 1; //地图滚动幅度

	//两张地图向左滚动（两张地图是相邻的，所以要一起滚动）
	posX1-=iSpeed;
	posX2-=iSpeed;


	Size mapSize = m_visibleSize; // 和使用visibleSize同样效果

	if(posX1<-mapSize.width/2) //map1全部离开屏幕
	{
		posX2 = mapSize.width/2;
		posX1 = mapSize.width+mapSize.width/2;
	}
	
	if(posX2<-mapSize.width/2) //map2全部离开屏幕
	{
		posX1 = mapSize.width/2;
		posX2 = mapSize.width+mapSize.width/2; 
	}




	m_pBgSprite1->setPositionX(posX1);
	m_pBgSprite2->setPositionX(posX2);

	m_fScore+=0.2f;

	m_pScoreLab->setString(CCString::createWithFormat("Score:%.0f",m_fScore)->getCString());

	m_pHpSlider->setValue(m_pPlayer->getHP());
}


void TollgateScene::createJumpBtn()
{
	m_visibleSize = Director::getInstance()->getVisibleSize();
//按钮标题
#if (CC_TARGET_PLATFORM ==CC_PLATFORM_IOS)
		Label * pJumpText = Label::createWithTTF("Jump","arial.ttf",35);
#else
		Label * pJumpText = Label::createWithTTF("Jump","fonts/arial.ttf",35);
#endif


	//按钮普通状态
	extension::Scale9Sprite *pNormBG = extension::Scale9Sprite::create("button.png");

	//按钮高亮状态
	extension::Scale9Sprite * pLightBG = extension::Scale9Sprite::create("buttonHighlighted.png");

	//创建按钮

	extension::ControlButton *pJumpBtn = extension::ControlButton::create(pJumpText,pNormBG);
	pJumpBtn->setPosition(Vec2(m_visibleSize.width-80,50));
	pJumpBtn->setBackgroundSpriteForState(pLightBG,extension::Control::State::HIGH_LIGHTED);

	//添加按钮事件
	pJumpBtn->addTargetWithActionForControlEvents(this,cccontrol_selector(TollgateScene::jumpEvent),ControlButton::EventType::TOUCH_DOWN);

	this->addChild(pJumpBtn);
}
	
void TollgateScene::jumpEvent(Ref * pSender,ControlButton::EventType event)
{
	m_pPlayer->jump();
}

void TollgateScene::createScoreLab() //创建分数标签
{
	m_fScore = 0;


#if (CC_TARGET_PLATFORM ==CC_PLATFORM_IOS)
		m_pScoreLab = Label::createWithTTF("Score:0","arial.ttf",35);
#else
		m_pScoreLab = Label::createWithTTF("Score:0","fonts/arial.ttf",35);
#endif

	CCAssert(m_pScoreLab!=NULL && m_pScoreLab!=nullptr,"label failed to create!");
	m_pScoreLab->setPosition(Vec2(0,m_visibleSize.height));
	m_pScoreLab->setAnchorPoint(Vec2(0,1));
	this->addChild(m_pScoreLab);
}

void TollgateScene::createHPSlider() //创建血量条
{
	m_pHpSlider = ControlSlider::create(
		Sprite::create("progress_background.png"),
		Sprite::create("progress.png"),
		Sprite::create("sliderThumb.png")
		);

	m_pHpSlider->setPosition(Vec2(
		m_pHpSlider->getContentSize().width/2,
		m_visibleSize.height-m_pHpSlider->getContentSize().height-m_pScoreLab->getContentSize().height
		));


	m_pHpSlider->setMaximumValue(1000);

	m_pHpSlider->setMinimumValue(0);

	m_pHpSlider->setValue(1000);
	this->addChild(m_pHpSlider,3);
}

void TollgateScene::addPlayer()
{
	 TMXObjectGroup * pObjGroup = m_pMap->getObjectGroup("objects");

	 ValueMap pPlayerPointDic = pObjGroup->getObject("PlayerPoint");

	 float playerX = (pPlayerPointDic.find("x")->second).asFloat();
		//	->valueForKey("x");
		float playerY = (pPlayerPointDic.find("y")->second).asFloat();

	Sprite *pSprite = Sprite::create("player.png");
	pSprite->setPosition(Vec2(playerX,playerY));
	m_pPlayer = Player::create();
	m_pPlayer->blindSprite(pSprite);
	m_pMap->addChild(m_pPlayer);
}

void TollgateScene::menuCloseCallback(Ref* pSender)
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
	MonsterManager::getInstance()->pure();
    pDirector->replaceScene(SceneFactory::create(GameConfig::CHOOSE_TABELVIEW));
}