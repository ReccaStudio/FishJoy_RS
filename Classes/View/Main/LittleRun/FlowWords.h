#ifndef _FlowWords_H_
#define _FlowWords_H_

#include "cocos2d.h"

class FlowWords:public cocos2d:: Node
{
public:
	FlowWords();
	~FlowWords();


	virtual bool init();

	CREATE_FUNC(FlowWords);

	void showWords(const char *text,cocos2d::Vec2 pos,cocos2d::Size contentSize);

private:
	void flowEnd();

private:
	cocos2d::Label * m_pTextLab;
};


#endif _FlowWords_H_