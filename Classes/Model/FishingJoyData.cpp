#include "FishingJoyData.h"
#include "StaticData.h"
#include "GameConfig.h"

USING_NS_CC;

FishingJoy* FishingJoy::s_pInstance = nullptr;

FishingJoy::FishingJoy():m_bIsBeginner(true)
{
}

FishingJoy::~FishingJoy()
{
	CC_SAFE_RELEASE_NULL(s_pInstance);
}

FishingJoy * FishingJoy::getInstance(void)
{
	if (s_pInstance==nullptr||s_pInstance==NULL)
	{
		s_pInstance = new FishingJoy();
		s_pInstance->init();
	}
	return s_pInstance;
}

bool FishingJoy::init()
{
	m_bIsBeginner = UserDefault::getInstance()->getBoolForKey("beginner",true);
	if (m_bIsBeginner)
	{
		this->reset();
		this->flush();
		this->setIsBeginner(false);
	}
	else
	{
		m_bIsBeginner = false;
		m_fSoundVolume = UserDefault::getInstance()->getFloatForKey(GameConfig::SOUND_VALUME.c_str());
		m_fMusicVolume = UserDefault::getInstance()->getFloatForKey(GameConfig::MUSIC_VALUME.c_str());
		m_iGold = UserDefault::getInstance()->getIntegerForKey(GameConfig::GOLD.c_str());
		UserDefault::getInstance()->destroyInstance();
	}
	return true;
}

void FishingJoy::purge()
{
	this->~FishingJoy();
}

void FishingJoy::reset()
{
	int gold = STATIC_DATA_INT(GameConfig::GOLD);
	this->setGold(gold);

	this->setSoundVolume(STATIC_DATA_FLOAT(GameConfig::SOUND_VALUME));

	this->setMusicVolume(STATIC_DATA_FLOAT(GameConfig::MUSIC_VALUME));

	this->flush();
}

void FishingJoy::updateGold(int delta)
{
	this->setGold(this->m_iGold+delta);
}

void FishingJoy::flush()
{
	UserDefault::getInstance()->setBoolForKey(GameConfig::IS_BEGINNER.c_str(),m_bIsBeginner);
	UserDefault::getInstance()->setIntegerForKey(GameConfig::GOLD.c_str(),m_iGold);
	UserDefault::getInstance()->setFloatForKey(GameConfig::SOUND_VALUME.c_str(),m_fSoundVolume);
	UserDefault::getInstance()->setFloatForKey(GameConfig::MUSIC_VALUME.c_str(),m_fMusicVolume);
	UserDefault::getInstance()->flush();
	UserDefault::getInstance()->destroyInstance();
}