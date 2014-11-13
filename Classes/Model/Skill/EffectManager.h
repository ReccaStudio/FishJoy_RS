#pragma once

#include "Effect.h"



class EffectManager
{
public:
	EffectManager();
	~EffectManager();

	static EffectManager * getInstance();

	Effect * requstEffect(const BULLET_TYPE &type);

	void returnEffect(Effect * pEffect);

	/*inline cocos2d::Vector<Effect*> & getUsingEffect()
	{
		return m_vUsingEffect;
	}*/


private:
	static EffectManager * s_EffectManager;
	//cocos2d::Vector<Effect*> m_vUsingEffect;
};

