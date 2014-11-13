#include "MonsterManager.h"
USING_NS_CC;
#include "Monster.h"
#define MAX_MONSTER_NUM 10

MonsterManager * MonsterManager::m_pMonsterManager = NULL;



MonsterManager::MonsterManager():m_pBatchNode(NULL),m_pPlayer(NULL)
{
	m_MonstersArr.clear();
}

MonsterManager::~MonsterManager()
{
	CC_SAFE_RELEASE(m_pPlayer);

	m_MonstersArr.clear();

	if (m_pBatchNode)
	{
		CC_SAFE_RELEASE_NULL(m_pBatchNode);
	}
}

MonsterManager * MonsterManager::getInstance()
{
	if(m_pMonsterManager==NULL)
	{
		m_pMonsterManager = MonsterManager::create();
		m_pMonsterManager->retain();
	}
	return m_pMonsterManager;
}

bool MonsterManager::init()
{
	bool bRet = false;

	do
	{
		createMonster();
		this->scheduleUpdate();
		bRet = true;
	} while (0);
	return bRet;
}


void MonsterManager::createMonster()
{
	m_MonstersArr.clear();


	Monster *pMonster = NULL;
	Sprite * pSprite = NULL;

	auto temp = Sprite::create();
	CC_SAFE_RETAIN(temp);
	if (m_pBatchNode)
	{
		CC_SAFE_RELEASE(m_pBatchNode);
	}
	m_pBatchNode = temp;
	

	for (int i = 0; i < MAX_MONSTER_NUM; ++i)
	{
		pMonster = Monster::create();

		pMonster->blindSprite(Sprite::create("monster.png"));
		pMonster->reset();

		//m_pBatchNode->addChild(pMonster);
		this->addChild(pMonster);
		m_MonstersArr.pushBack(pMonster);
	}
}

void MonsterManager::update(float dt)
{
	Monster* pMonster = NULL;
	
	for (Vector<Ref*>::iterator t = m_MonstersArr.begin(); t != m_MonstersArr.end();++t)
	{
		Ref *pObj = *(t);
		pMonster = dynamic_cast<Monster*>(pObj);

		if (pMonster->isAlive())
		{
			pMonster->setPositionX(pMonster->getPositionX()-4);

			if (pMonster->getPositionX()<0)
			{
				pMonster->hide();
			}
			else if (pMonster->isCollideWithPlayer(m_pPlayer))
			{
				m_pPlayer->hit();
				pMonster->hide();
			}
		}
		else
		{
			pMonster->show();
		}
	}
}

void MonsterManager::bindPlayer( Player* pPlayer ) 
{
    this->m_pPlayer = pPlayer;
    this->m_pPlayer->retain();
}