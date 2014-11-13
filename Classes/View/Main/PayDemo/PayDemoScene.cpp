#include "PayDemoScene.h"

USING_NS_CC;
//Scene* payDemo::scene()
//{
//    // 'scene' is an autorelease object
//    Scene *scene = Scene::create();
//    
//    // 'layer' is an autorelease object
//    payDemo *layer = payDemo::create();
//
//    // add layer as a child to scene
//    scene->addChild(layer);
//
//    // return the scene
//    return scene;
//}

PayDemoScene::PayDemoScene()
{
    
}
PayDemoScene::~PayDemoScene()
{
    
}

// on "init" you need to initialize your instance
bool PayDemoScene::init()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	CCAssert(Scene::init(),"Scene should be inited yet");
	m_pLayer = PayDemoView::create();
    this->addChild(m_pLayer);

	    // add a "close" icon to exit the progress. it's an autorelease object


	return true;
}


void PayDemoScene::onEnter()
{
    Scene::onEnter();

}

void PayDemoScene::onExit()
{
    Scene::onExit();
}

PayDemoScene * PayDemoScene::s_pPayDemoScene(NULL);

void PayDemoScene::destoyScene()
{
	CC_SAFE_RELEASE(s_pPayDemoScene);
}

PayDemoScene * PayDemoScene::getInstance()
{
    if(!s_pPayDemoScene)
    {
        s_pPayDemoScene = PayDemoScene::create();
        CC_SAFE_RETAIN(s_pPayDemoScene);
    }
    
    return s_pPayDemoScene;
}


