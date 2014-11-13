#ifndef __FISHING_JOY_DATA_H_
#define __FISHING_JOY_DATA_H_

#include "cocos2d.h"


class FishingJoy:public cocos2d::Ref
{
public:
	
	bool init();
	static FishingJoy*getInstance(void);
	
	void purge();

	void reset();

	void updateGold(int delta);

	/**
     *	@brief	 将数据从内存保存到外部文件中
     */
    void flush();

	CC_SYNTHESIZE(int,m_iGold,Gold);
	CC_SYNTHESIZE(bool,m_bIsBeginner,IsBeginner);
	CC_SYNTHESIZE(float,m_fSoundVolume,SoundVolume);
	CC_SYNTHESIZE(float,m_fMusicVolume,MusicVolume);



private:
	FishingJoy();
	~FishingJoy();

private:
	static FishingJoy* s_pInstance;
	std::vector <cocos2d::Ref *> m_vDict;
};



#endif