#include "GameScene.h"
#include "GameConfig.h"
#include "SceneFactory.h"
#include "Model/StaticData.h"
#include "./Model/FishingJoyData.h"
#include "Model/Fish.h"


#include "./Model/Collision/CollisionBaseManager.h"

USING_NS_CC;

GameScene::GameScene()
{

}

GameScene::~GameScene()
{
	CC_SAFE_RELEASE_NULL(m_pMenuLayer);
}

bool GameScene::init()
{
	preloadResources();
	if(Scene::init())
	{
		
		m_pBackgroundLayer = BackgroundLayer::create();
		this->addChild(m_pBackgroundLayer);
		
		m_pFishLayer = FishLayer::create();
		this->addChild(m_pFishLayer);

		m_pTouchLayer = TouchLayer::create();
		this->addChild(m_pTouchLayer);

		m_pCannonLayer = CannonLayer::create();
		this->addChild(m_pCannonLayer);

		m_pPanelLayer = PanelLayer::create();
		this->addChild(m_pPanelLayer);

		m_pMenuLayer = MenuLayer::create();
		CC_SAFE_RETAIN(m_pMenuLayer);

		

		this->scheduleUpdate();

		return true;
	}
	return false;
}


void GameScene::pause()
{
	this->operatorAllSchedulerAndAction(this,OperateFlag::k_Pause);
	this->addChild(m_pMenuLayer);
}

void GameScene::resume()
{
	this->operatorAllSchedulerAndAction(this,OperateFlag::k_Resume);
	this->removeChild(m_pMenuLayer);
}

void GameScene::switchSound()
{

}

void GameScene::switchMusic()
{

}

void GameScene::reset()
{

}

void GameScene::transToMainMenu()
{
	Director * pDirector = Director::getInstance();
    pDirector->replaceScene(SceneFactory::create(GameConfig::CHOOSE_TABELVIEW));
}


	
void GameScene::operatorAllSchedulerAndAction(cocos2d::Node * pNode,OperateFlag flag)
{
	if (pNode->isRunning())
	{
		switch (flag)
		{
		case OperateFlag::k_Pause:
			pNode->pause();
			break;
		case OperateFlag::k_Resume:
			pNode->resume();
			break;
		default:
			break;
		}//switch

		Vector<Node*> children= pNode->getChildren();
		std::for_each
		(
			children.begin(),
			children.end(),
			[this,flag](Node * child)
			{
				this->operatorAllSchedulerAndAction(child,flag);
			}
		);
		

	}//if


}

//todo
void GameScene::preloadResources()
{
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile(GameConfig::SPRITE_FRAME_LIST);

	int frameCount = STATIC_DATA_INT(GameConfig::FISH_FRAME_COUNT);
	Vector<SpriteFrame *> spriteArray;
	std::string temp;
	for (std::size_t type = FishType::k_Red; type < FishType::k_Count; ++type)
	{
		spriteArray.clear();
		
		for (int i = 0; i < frameCount; ++i)
		{
			std::string filename = STATIC_DATA_STRING(GameConfig::FISH_FRAME_NAME_FORMAT);
			temp = StringUtils::format(filename.c_str(),type,i);
			SpriteFrame * spriteFrame = SpriteFrameCache::getInstance()->getSpriteFrameByName(temp);
			spriteArray.pushBack(spriteFrame);
		}

		Animation *fishAnimation = Animation::createWithSpriteFrames(spriteArray);
		fishAnimation->setDelayPerUnit(STATIC_DATA_FLOAT(GameConfig::FISH_FRAME_DELAY.c_str()));
		std::string animationName = STATIC_DATA_STRING(GameConfig::FISH_ANIMATION.c_str());
		temp = StringUtils::format(animationName.c_str(),type);
		AnimationCache::getInstance()->addAnimation(fishAnimation,temp);
	}
}

void GameScene::cannnonAimAt(cocos2d::Vec2 target)
{
	m_pCannonLayer->aimAt(target);
}

void GameScene::cannnonShootTo(cocos2d::Vec2 target)
{
	m_pCannonLayer->shootTo(target);
}

void GameScene::update(float delta)
{
	this->checkOutCollision();
}

void GameScene::checkOutCollision()
{
	//只有子弹和其他物体碰撞，才有击中目标的后续操作，所以只需要通过子弹状态进行跟踪

		//todo 限制同时检测的子弹数，采用缓存vector循环使用
		cocos2d::Vector<CollisionBase *> * pCollisionContainers = new cocos2d::Vector<CollisionBase *> (20);
		Bullet * pBullet = m_pCannonLayer->getWeaponNode()->getBulletNode()->getBullet();
		CollisionBaseManager::getInstance()->countCrashedUnitys(pBullet,pCollisionContainers);
		if (!pCollisionContainers->empty())
		{
			//todo
		//	this->checkOutCollisionByAttacker(pCollisionContainers,m_pCannonLayer->getWeaponNode()->get());

		}
		pCollisionContainers->clear();

}

bool GameScene::checkOutCollisionByAttacker(cocos2d::Vector<CollisionBase *> * pCollisionContainers,CollisionBase* pAttacker)
{
	pCollisionContainers->clear();

	CollisionBaseManager::getInstance()->countCrashedUnitys(pAttacker,pCollisionContainers);

	/*std::for_each(m_pCollisionContainers->begin(),m_pCollisionContainers->end(),[this](CollisionContainer * p)
	{
		this->unityWillBeCaught(p);
	});*/

	this->catchFishes(pCollisionContainers,pAttacker);

	return true;
}

void GameScene::catchFishes(cocos2d::Vector<CollisionBase *> * pCollisionContainers,CollisionBase* pAttacker)
{
	
	m_pCannonLayer->catchFishes(pCollisionContainers,pAttacker);
}