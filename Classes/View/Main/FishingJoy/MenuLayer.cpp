#include "MenuLayer.h"
#include "GameScene.h"
USING_NS_CC;

MenuLayer::MenuLayer():Layer()
{
}

MenuLayer::~MenuLayer()
{
}

bool MenuLayer::init()
{
	if (Layer::init())
	{
		this->createBackground();
		this->createMenu();
		return true;
	}
	return false;
}

void MenuLayer::createMenu()
{
	int fontSize = 32;
	std::string fontName = std::string("Thronburi");

	MenuItemLabel * pResume = MenuItemLabel::create(Label::createWithSystemFont("Resume",fontName,fontSize),CC_CALLBACK_1(MenuLayer::resume,this));

	MenuItemLabel * pMainMenu = MenuItemLabel::create(Label::createWithSystemFont("MainMenu",fontName,fontSize),CC_CALLBACK_1(MenuLayer::transToMainMenu,this));

	MenuItemLabel * pSoundOn = MenuItemLabel::create(Label::createWithSystemFont("Sound On",fontName,fontSize));
	MenuItemLabel * pSoundOff = MenuItemLabel::create(Label::createWithSystemFont("Sound Off",fontName,fontSize));

	m_pSound = MenuItemToggle::createWithCallback(CC_CALLBACK_0(MenuLayer::switchSound,this),pSoundOn,pSoundOff,nullptr);


	MenuItemLabel * pMusicOn = MenuItemLabel::create(Label::createWithSystemFont("Music On",fontName,fontSize));
	MenuItemLabel * pMusicOff = MenuItemLabel::create(Label::createWithSystemFont("Music Off",fontName,fontSize));

	m_pMusic = MenuItemToggle::createWithCallback(CC_CALLBACK_0(MenuLayer::switchMusic,this),pMusicOn,pMusicOff,nullptr);

	MenuItemLabel * pReset = MenuItemLabel::create(Label::createWithSystemFont("Reset",fontName,fontSize),CC_CALLBACK_1(MenuLayer::reset,this));



	CCAssert(pSoundOn!=NULL && pSoundOn!=nullptr,"pSoundOn is nullptr");
	CCAssert(pSoundOff!=NULL && pSoundOff!=nullptr,"pSoundOff is nullptr");
	CCAssert(pMusicOn!=NULL && pMusicOn!=nullptr,"pMusicOn is nullptr");
	CCAssert(pMusicOff!=NULL && pMusicOff!=nullptr,"pMusicOff is nullptr");


	CCAssert(pResume!=NULL && pResume!=nullptr,"pResume is nullptr");
	CCAssert(pMainMenu!=NULL && pMainMenu!=nullptr,"pMainMenu is nullptr");
	CCAssert(m_pSound!=NULL && m_pSound!=nullptr,"m_pSound is nullptr");
	CCAssert(m_pMusic!=NULL && m_pMusic!=nullptr,"m_pMusic is nullptr");
	CCAssert(pReset!=NULL && pReset!=nullptr,"pReset is nullptr");

	Menu * pMenu = Menu::create(pResume,pMainMenu,m_pSound,m_pMusic,pReset,nullptr);

	CCAssert(pMenu!=NULL && pMenu!=nullptr,"pMenu is nullptr");

	this->addChild(pMenu);

	pMenu->alignItemsVerticallyWithPadding(10);
}

void MenuLayer::createBackground()
{
	this->addChild(LayerColor::create(Color4B(0,0,0,128)));

}

void MenuLayer::setSoundAndMusicVolume(float soundVolume,float musicVolume)
{
	bool soundFlag = soundVolume>0;
	bool musicFlag = musicVolume>0;
	
	m_pSound->setSelectedIndex(soundFlag);
	m_pMusic->setSelectedIndex(musicFlag);

}

void MenuLayer::resume(cocos2d::Ref * pSender)
{
	GameScene * p = dynamic_cast<GameScene *>(this->getParent());
	p->resume();
}


void MenuLayer::transToMainMenu(cocos2d::Ref * pSender)
{
	GameScene * p = dynamic_cast<GameScene *>(this->getParent());
	p->transToMainMenu();
}

void MenuLayer::switchSound()
{
	GameScene * p = dynamic_cast<GameScene *>(this->getParent());
	p->switchSound();
}

void MenuLayer::switchMusic()
{
	GameScene * p = dynamic_cast<GameScene *>(this->getParent());
	p->switchMusic();
}

void MenuLayer::reset(cocos2d::Ref * pSender)
{
	GameScene * p = dynamic_cast<GameScene *>(this->getParent());
	p->reset();
}

