#ifndef _Monster_Manager_H_
#define _Monster_Manager_H_

#include "cocos2d.h"
#include "Player.h"


class MonsterManager:public cocos2d::CCNode
{
public:
	MonsterManager();
	~MonsterManager();

	static MonsterManager * getInstance();

	

	virtual bool init();
	virtual void update(float dt);

	cocos2d::Sprite * getMonsterBatchNode()
	{
		return m_pBatchNode;
	}


	void bindPlayer( Player* pPlayer );

	void pure()
	{
		if (m_pMonsterManager)
		{
			m_MonstersArr.clear();
			m_pMonsterManager->release();
			m_pMonsterManager = nullptr;
		}
	}

private:
	void createMonster();
	CREATE_FUNC(MonsterManager);

private:
	cocos2d::Vector<cocos2d::Ref*>m_MonstersArr;
	cocos2d::Sprite *m_pBatchNode;
	static MonsterManager * m_pMonsterManager;
	Player * m_pPlayer;
};



#endif