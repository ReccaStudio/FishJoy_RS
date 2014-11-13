#pragma once

/*
* 目前遗留一个缓冲池只增不减的问题
*
*
*
*
*/

#include "cocos2d.h"
#include "Bullet.h"
#include <map>

class AbstractBulletFactory
{
public:
	AbstractBulletFactory(){};
	virtual ~AbstractBulletFactory()
	{
		destroyPools();
	};

	virtual Bullet * requstBullet(const BULLET_TYPE &type)
	{
		Bullet * tartget= nullptr;
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
					increaseBullets(pMap,type);
				}
			}

	
		CCAssert(tartget,"Can't get bullet from factory");

		return tartget;
	}

	virtual void returnBullet(Bullet * pBullet)
	{
		pBullet->reset();
		setTrue(m_Pools.at(pBullet->getBulletType()),pBullet);

	}

protected:
	void setTrue(std::map<Bullet*,bool> * pMap,Bullet * pBullet)
	{
		auto it = pMap->find(pBullet);
		if (it!= pMap->end())
		{
			(*it).second = true;
		}
	}

	void increaseBullets(std::map<Bullet*,bool> * pBulletPool,BULLET_TYPE type)
	{
		for (int i = 0; i < INC; ++i)
		{
			auto pTartget = this->createBullet(type);
			CCAssert(pTartget!=nullptr && pTartget != NULL,"failed to create Bullet");
			CC_SAFE_RETAIN(pTartget);
			pBulletPool->insert(std::make_pair(pTartget,false));
		}
	}
	
	void eraseBullet(std::map<Bullet*,bool> * pBulletPool,Bullet* pTartget)
	{

	}

	virtual void addPool(BULLET_TYPE type)
	{
		auto p = new std::map<Bullet*,bool>();
		p->clear();
		m_Pools.insert(std::make_pair(type,p));
		increaseBullets(p,type);
	}

	virtual void destroyPools()
	{
		for (auto it = m_Pools.begin(); it !=m_Pools.end(); )
		{
			auto  pMap= (*it).second;
			for (auto jit = pMap->begin(); jit != pMap->end(); ++jit)
			{
				CC_SAFE_RELEASE(jit->first);
			}
			pMap->clear();
			delete pMap;
			m_Pools.erase(it);
		}
	}

	virtual Bullet * createBullet(BULLET_TYPE type) = 0;

protected:

	std::map<BULLET_TYPE,std::map<Bullet*,bool>* > m_Pools;
	static const int COUNT = 10;
	static const int INC = 10;
};

