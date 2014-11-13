#include "CollisionBaseManager.h"
#include "CollisionBase.h"
#include <algorithm>


CollisionBaseManager::CollisionBaseManager():m_pv_CollisionBase(new cocos2d::Vector<CollisionBase *>(40))
{
	
}

CollisionBaseManager::~CollisionBaseManager()
{
	m_pv_CollisionBase->clear();
	delete m_pv_CollisionBase;
	m_pv_CollisionBase = nullptr;
}

CollisionBaseManager * CollisionBaseManager::s_pCollisionBaseManager = nullptr;

CollisionBaseManager * CollisionBaseManager::getInstance()
{
	if(s_pCollisionBaseManager == nullptr|| s_pCollisionBaseManager == NULL)
	{
		s_pCollisionBaseManager = new CollisionBaseManager();
	}
	return s_pCollisionBaseManager;
}

void CollisionBaseManager::push_back(CollisionBase * p)
{
	//dynamic_cast<cocos2d::Ref *>(p)->retain();
	m_pv_CollisionBase->pushBack(p);
	
}

void CollisionBaseManager::remove(CollisionBase * p)
{
	if(m_pv_CollisionBase->contains(p))
	{
		m_pv_CollisionBase->erase(m_pv_CollisionBase->getIndex(p));
	}
	
	
	/*std::vector<CollisionBase *>::iterator it = std::find(m_pv_CollisionBase->begin(),m_pv_CollisionBase->end(),p);
	if (it!=m_pv_CollisionBase->end())
	{
		this->remove(*it);
		dynamic_cast<cocos2d::Ref *>((*it))->release();
	}*/

}

void CollisionBaseManager::remove(cocos2d::Vector<cocos2d::Node*> nodesArray)
{
	//todo
	for (auto it = nodesArray.begin(); it != nodesArray.end(); it++)
	{
		remove(reinterpret_cast<CollisionBase*>(*it));
	}
}

void CollisionBaseManager::countCrashedUnitys(CollisionBase * p ,cocos2d::Vector<CollisionBase *> * pTargetUnitys)
{
	pTargetUnitys->clear();
	std::for_each(m_pv_CollisionBase->begin(),m_pv_CollisionBase->end(),[p,pTargetUnitys](CollisionBase * q)
	{
		int unityClan1 = static_cast<int>(p->getUnityClan());
		int unityClan2 = static_cast<int>(q->getUnityClan());
		if ( (unityClan1!=unityClan2) && (unityClan1 & unityClan2))
		{
			if (q->checkCollison(p))
			{
				pTargetUnitys->pushBack(q);
			}
			
		}
	});

	return ;
}

CollisionBase * CollisionBaseManager::findUnityByTag(int tag)
{
	for (auto it = m_pv_CollisionBase->begin(); it != m_pv_CollisionBase->end(); ++it)
	{
		//todo
		auto p = reinterpret_cast<CollisionBase*>(*it);
		if(tag == p->getTag())
		{
			return p;
		}
	}
}

bool CollisionBaseManager::IsExisted(CollisionBase * p)
{
	return m_pv_CollisionBase->contains(p);
}