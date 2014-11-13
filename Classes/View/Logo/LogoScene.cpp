#include "LogoScene.h"
#include "Gameconfig.h"
#include "SceneFactory.h"
#include "LogoView.h"
USING_NS_CC;

#define WHITE_BACKGROUND_TIME 0.0F
#define LGYOO_LOGO_TIME 3.0F
#define THIRD_LOGO_TIME 2.0F
LogoScene::LogoScene()
:m_fTotalTime(NULL)
,m_pLayer(NULL)
{
    
}
LogoScene::~LogoScene()
{
    
}

// on "init" you need to initialize your instance
bool LogoScene::init()
{ 
	Scene::init();
	m_pLayer = LogoView::create();
    this->addChild(m_pLayer);
	return true;
}


void LogoScene::onEnter()
{
    Scene::onEnter();
    this->schedule(schedule_selector(LogoScene::logoUI));
}
void LogoScene::logoUI(float logoTime)
{
    m_fTotalTime += logoTime;
    if (m_fTotalTime > LGYOO_LOGO_TIME)
    {
        this->unschedule(schedule_selector(LogoScene::logoUI));
        m_fTotalTime = 0.0F;
        Director* pDirector = Director::getInstance();
      //  log("IOS----LogoScene1");
		pDirector->replaceScene(TransitionProgressOutIn::create(0.5,SceneFactory::create(GameConfig::LOGIN_SCENE)));
     //   log("IOS----LogoScene2");
        
    }
}
void LogoScene::onExit()
{
	//log("IOS----LogoScene3");
    Scene::onExit();
}


