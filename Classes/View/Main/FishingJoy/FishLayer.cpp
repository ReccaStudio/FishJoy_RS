#include "FishLayer.h"

USING_NS_CC;

FishLayer::FishLayer():Layer()
{
}

FishLayer::~FishLayer()
{
	m_vFishes.clear();
}

bool FishLayer::init()
{
	if (Layer::init())
	{
		m_vFishes.clear();
		m_iCapscity = 50;
		for (int i = 0; i < m_iCapscity; ++i)
		{
			int type = CCRANDOM_0_1()*2;
			Fish *pFish = Fish::create(FishType(type));
			m_vFishes.pushBack(pFish);

		}
		this->schedule(schedule_selector(FishLayer::addFish),3.0);
		return true;
	}
	return false;
}

void FishLayer::addFish(float dt)
{

	Size winSize = Director::getInstance()->getVisibleSize();
	int countTOAdd =CCRANDOM_0_1()*10-1;
	int countHasAdded = 0;
	if (countHasAdded>=countTOAdd)
	{
		return;
	}
	for( Vector<Fish*>::iterator it= m_vFishes.begin();it!=m_vFishes.end();++it)
	{
		if ((*it)->isRunning()==false)
		{//todp

			this->addChild((*it));
			int randomX = CCRANDOM_0_1()*winSize.width;
			int randomY = CCRANDOM_0_1()*winSize.height;
			(*it)->setPosition(randomX,randomY);
			++countHasAdded;
			if (countHasAdded==countTOAdd)
			{
				return;
			}
		}
		
	};

	return;
	
}