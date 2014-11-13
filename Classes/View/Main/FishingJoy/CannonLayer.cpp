#include "CannonLayer.h"
#include "./../Classes/GameConfig.h"
#include "./../Classes/Model/StaticData.h"
#include <cstring>
USING_NS_CC;

CannonLayer::CannonLayer():Layer()
{
}

CannonLayer::~CannonLayer()
{
}

bool CannonLayer::init()
{
	if (Layer::init())
	{
		Size winSize = Director::getInstance()->getVisibleSize();
		m_pWeaponNode = FishingNode::create();
		this->addChild(m_pWeaponNode);
		m_pWeaponNode->autorelease();
		auto p = m_pWeaponNode->getCannonNode();
		m_pWeaponNode->setPosition(winSize.width/2,p->getCannonSprite()->getContentSize().height/2);
		std::string temp  = STATIC_DATA_STRING(GameConfig::BUTTON_SUB);
		Sprite * pSub = Sprite::createWithSpriteFrameName(temp);
		m_pSubItem = MenuItemSprite::create(pSub,pSub,CC_CALLBACK_1(CannonLayer::switchCannon,this));

		temp  = STATIC_DATA_STRING(GameConfig::BUTTON_ADD);
		Sprite * pAdd = Sprite::createWithSpriteFrameName(temp);
		m_pAddItem = MenuItemSprite::create(pAdd,pAdd,CC_CALLBACK_1(CannonLayer::switchCannon,this));

		Menu *pMenu = Menu::create(m_pSubItem,m_pAddItem,nullptr);
		this->addChild(pMenu);
		pMenu->setPosition(winSize.width*0.5-3, m_pSubItem->getContentSize().height*0.5);
		pMenu->alignItemsHorizontallyWithPadding(m_pWeaponNode->getCannonNode()->getCannonSprite()->getContentSize().width+10);
		return true;
	}
	return false;
}

void CannonLayer::switchCannon(Ref * sender)
{
	WEAPON_TYPE type = m_pWeaponNode->getCurWeaponType();

	if (sender==m_pAddItem)
	{
		type = static_cast<WEAPON_TYPE>(type+1);
	}
	else if(sender==m_pSubItem)
	{
		type = static_cast<WEAPON_TYPE>(type-1);
	}
	m_pWeaponNode->setCurWeaponType(type);

}

bool CannonLayer::shootTo(cocos2d::Vec2 touchLocation)
{
	return m_pWeaponNode->shootTo(touchLocation);
}
	
void CannonLayer::aimAt(cocos2d::Vec2 target)
{
	m_pWeaponNode->aimAt(target);
}

void CannonLayer::catchFishes(cocos2d::Vector<CollisionBase *> * pCollisionContainers,CollisionBase* pAttacker)
{
	//m_pWeaponNode->attackUnity(pvUnitys,pAttcker);
}