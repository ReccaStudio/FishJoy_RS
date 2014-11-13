#include "Fish.h"
#include "StaticData.h"
#include "GameConfig.h"
#include "Collision/CollisionSprite.h"
USING_NS_CC;


enum{
    k_Action_Animate = 0,
};

Fish::Fish()
{
}

Fish::~Fish()
{
}

Fish * Fish::create(FishType type)
{
	Fish * fish = new Fish();
	if (fish && fish->init(type))
	{
		fish->autorelease();
		return fish;
	}
	delete fish;
	fish = nullptr;
	return fish;
}
	
bool Fish::init(FishType type)
{
	m_Type = type;
	std::string animationName = STATIC_DATA_STRING(GameConfig::FISH_ANIMATION.c_str());
	std::string temp = StringUtils::format(animationName.c_str(),int(type));
	
	Animation * fishAnimation = AnimationCache::getInstance()->getAnimation(temp);

	Animate * fishAnimate = Animate::create(fishAnimation);
	fishAnimate->setTag(k_Action_Animate);
	m_pFishSpritre = CollisionSprite::create();
	m_pFishSpritre->setUnityClan(Unity_Clan::k_Fish_Type);
	this->addChild(m_pFishSpritre);
	m_pFishSpritre->runAction(CCRepeatForever::create(fishAnimate));
	return true;

}