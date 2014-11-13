#pragma once

#include "Effect.h"

#include <map>


class AbstractEffectFactory
{
public:

	virtual Effect * requstEffect(const BULLET_TYPE &type)
	{
		Effect * tartget= nullptr;
		auto pMap = m_Pools.at(type);
			for (auto it = pMap->begin(); it != pMap->end(); ++it)
			{
				if ((it->second==false))
				{
					it->second=true;
					tartget = it->first;
					break;
				}
				if (it==pMap->end())
				{
					increaseEffects(pMap,type);
				}
			}

	
		CCAssert(tartget,"Can't get Effect from factory");

		return tartget;
	}

	virtual void returnEffect(Effect * pEffect)
	{
		pEffect->resetEffect();
		setTrue(m_Pools.at(pEffect->getBulletType()),pEffect);
	}

protected:
	virtual void setTrue(std::map<Effect*,bool> * pMap,Effect * pEffect)
	{
		auto it = pMap->find(pEffect);
		if (it!= pMap->end())
		{
			(*it).second = true;
		}
	}

	virtual void increaseEffects(std::map<Effect*,bool> * pEffectPool,BULLET_TYPE type) = 0;


protected:

	std::map<BULLET_TYPE,std::map<Effect*,bool>* > m_Pools;
};










