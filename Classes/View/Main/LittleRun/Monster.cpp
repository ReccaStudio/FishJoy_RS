#include"Monster.h"

USING_NS_CC;
//USING_NS_CC_EXT;

Monster::Monster()
{
	m_bIsAlive = false;
}

Monster::~Monster()
{
}

bool Monster::init()
{
	return true;
}

void Monster::show() //显示怪物
{
	if (this->getSprite()!=NULL)
	{
		this->setVisible(true);
		m_bIsAlive = true;
	}
}
	
void Monster::hide() //隐藏怪物
{
	if (this->getSprite()!=NULL)
	{
		this->setVisible(false);
		reset();
		m_bIsAlive = false;
	}
}
	
void Monster::reset() //重置怪物数据
{
	if (this->getSprite()!=NULL)
	{
		this->setPosition(Vec2(800+CCRANDOM_0_1()*2000,200-CCRANDOM_0_1()*100));
	}
}
	
bool Monster::isAlive() //是否活动状态
{
	return m_bIsAlive;
}

bool Monster::isCollideWithPlayer(Player * pPlayer)
{
	Rect entityRect = pPlayer->getBoundingBox();
	Vec2 monsterPos = this->getPosition();

	return entityRect.containsPoint(monsterPos);
}