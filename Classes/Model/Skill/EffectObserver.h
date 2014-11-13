#pragma once

extern class Effect;

class EffectObserver
{
public:
	
	virtual ~EffectObserver(){};

	virtual void updateEffect() = 0;


protected:

	EffectObserver():m_pEffect(nullptr){};


protected:

	Effect * m_pEffect;
};
