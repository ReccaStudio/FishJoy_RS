//
//  SceneFactory.cpp
//  payDemo
//
//  Created by Íõ¾´ÕÜ on 13-12-1.
//
//

#include "SceneFactory.h"
#include "Gameconfig.h"
#include "View/Logo/LogoScene.h"
#include "View/Login/LoginScene.h"
#include "View/Login/ChooseTableView.h"
#include "View/Main/PayDemo/PayDemoScene.h"
#include "View/Main/LittleRun/TollgateScene.h"
#include "View/Main/PayDemo/PayDemoScene.h"
#include "View/Main/FishingJoy/GameScene.h"

USING_NS_CC;

Scene* SceneFactory::create(int type)
{
    switch (type) {
        case GameConfig::LOGO_SCENE:
            return LogoScene::create();
            break;
            
        case GameConfig::LOGIN_SCENE:
            return LoginScene::getInstance();
            break;

		case GameConfig::CHOOSE_TABELVIEW:
			return ChooseTableView::getInstance();
			break;
            
        case GameConfig::LITTLE_RUN_SCENE:
			return TollgateScene::create();
            break;

        case GameConfig::PAY_DEMO_SCENE:
			return PayDemoScene::getInstance();
            break; 

		case GameConfig::FISHING_JOY_SCENE:
			return GameScene::create();
            break; 
		
        default:
            return NULL;
            break;
    }
}
