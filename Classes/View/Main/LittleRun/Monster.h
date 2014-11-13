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
	void show(); //��ʾ����
	void hide(); //���ع���
	void reset(); //���ù�������
	bool isAlive(); //�Ƿ�״̬

	bool isCollideWithPlayer(Player * pPlayer);

private:
	bool m_bIsAlive;
};



#endif