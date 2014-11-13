#ifndef _AnimationUtil_H_
#define _AnimationUtil_H_

#include "cocos2d.h"

class AnimationUtil
{
public:
	AnimationUtil();
	~AnimationUtil();

	static cocos2d::Animation * createAnimWithSingleFrameN(const char * pName,float delay,unsigned int iLoops,bool bRestoreOriginalFrame = false);

	static cocos2d::Animation * createAnimWithSingleFrameNameAndNum(const char * pName,int iNum,float delay,unsigned int iLoops,bool bRestoreOriginalFrame = false);

private:

};

#endif