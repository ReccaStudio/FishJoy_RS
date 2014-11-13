//Entity.h
#ifndef _Entity_H_
#define _Entity_H_

#include "cocos2d.h"


class Entity:public cocos2d::Node
{
public:
	Entity();
	~Entity();

	cocos2d::Sprite *getSprite();
	void blindSprite(cocos2d::Sprite * pSprite);

private:
	cocos2d::Sprite *m_pSprite;
};




#endif