#pragma once

#include "cocos2d.h"
#include "AbstractEffectFactory.h"


class EffectNormalFactory:public AbstractEffectFactory
{
public:
	EffectNormalFactory();
	~EffectNormalFactory();

	static EffectNormalFactory * getInstance();

protected:
	void increaseEffects(std::map<Effect*,bool> * pEffectPool,BULLET_TYPE type);

private:
	static EffectNormalFactory * s_EffectNormalFactory;

	static const int COUNT = 10;
static const int INC = 10;


};