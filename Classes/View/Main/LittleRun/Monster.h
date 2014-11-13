#ifndef _Monster_H_
#define _Monster_H_

#include "cocos2d.h"
#include "Entity.h"
#include "Player.h"
class Monster:public Entity
{
public:
	Monster();
	~Monster();

	CREATE_FUNC(Monster);
	virtual bool init();

public:
	void show(); //显示怪物
	void hide(); //隐藏怪物
	void reset(); //重置怪物数据
	bool isAlive(); //是否活动状态

	bool isCollideWithPlayer(Player * pPlayer);

private:
	bool m_bIsAlive;
};



#endif