#include "LoginScene.h"
#include "Gameconfig.h"
#include "SceneFactory.h"
#include "LoginView.h"
USING_NS_CC;



LoginScene::LoginScene()
:m_pLayer(NULL)
{
}

LoginScene *LoginScene::s_pLoginScene(NULL);

LoginScene::~LoginScene()
{
    
}

// on "init" you need to initialize your instance
bool LoginScene::init()
{
	Scene::init();
	m_pLayer = LoginView::create();
    this->addChild(m_pLayer);
	return true;
}


void LoginScene::onEnter()
{
    Scene::onEnter();
}




void LoginScene::onExit()
{
    Scene::onExit();
}

LoginScene * LoginScene::getInstance()
{
    if(!s_pLoginScene)
    {
        s_pLoginScene = LoginScene::create();
        CC_SAFE_RETAIN(s_pLoginScene);
    }
    
    return s_pLoginScene;
}


void LoginScene::destoyScene()
{
	CC_SAFE_RELEASE(s_pLoginScene);
}