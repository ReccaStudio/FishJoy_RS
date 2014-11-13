#include "AnimationUtil.h"

USING_NS_CC;

AnimationUtil::AnimationUtil()
{
}

AnimationUtil::~AnimationUtil()
{
}

Animation * AnimationUtil::createAnimWithSingleFrameN(const char * pName,float delay,unsigned int iLoops,bool bRestoreOriginalFrame)
{
	SpriteFrameCache * pCache = SpriteFrameCache::getInstance();
	Vector<SpriteFrame *>pFramesArray;
	pCache->addSpriteFramesWithFile(std::string(pName).append(".plist"));
	SpriteFrame * pFrame = NULL;
	int i = 0;
	std::string temp;
	while (true)
	{
		temp = StringUtils::format("%s%d.png",pName,++i);

		pFrame = pCache->getSpriteFrameByName(temp);
		if (pFrame==NULL)
		{
			break;
		}
		else
		{
			pFramesArray.pushBack(pFrame);
		}
	}

	cocos2d::Animation * pAnimation = cocos2d::Animation::createWithSpriteFrames(pFramesArray);

	pAnimation->setLoops(iLoops);
	pAnimation->setRestoreOriginalFrame(bRestoreOriginalFrame);
	pAnimation->setDelayPerUnit(delay);
	

	return pAnimation;
}

cocos2d::Animation * AnimationUtil::createAnimWithSingleFrameNameAndNum(const char * pName,int iNum,float delay,unsigned int iLoops,bool bRestoreOriginalFrame)
{
	cocos2d::SpriteFrameCache * pCache = cocos2d::SpriteFrameCache::getInstance();
	Vector<SpriteFrame *> pFramesArray ;
	cocos2d::SpriteFrame * pFrame = NULL;
	pCache->addSpriteFramesWithFile(std::string(pName).append(".plist"));

	std::string temp;

	for (int i = 1; i < iNum; ++i)
	{

		temp = StringUtils::format("%s%d.png",pName,i);
		pFrame = pCache->getSpriteFrameByName(temp);
		if (pFrame==NULL)
		{
			break;
		}
		else
		{
			pFramesArray.pushBack(pFrame);
		}
	}
	

	cocos2d::Animation * pAnimation = cocos2d::Animation::createWithSpriteFrames(pFramesArray);

	pAnimation->setLoops(iLoops);
	pAnimation->setRestoreOriginalFrame(bRestoreOriginalFrame);
	pAnimation->setDelayPerUnit(delay);
	

	return pAnimation;
}