#ifndef _Player_H_
#define _Player_H_
#include "cocos2d.h"
#include "Entity.h"



class Player:public Entity
{
public:
	Player();
	~Player();

	CREATE_FUNC(Player);

	virtual bool init();

public:
	void jump();
	void jumpEnd();

	void hit();
	int getHP()
	{
		return m_iHP;
	}
	cocos2d::Rect getBoundingBox(); //»ñÈ¡Åö×²·¶Î§

	void resetData();

	void hitEnd()
	{
		m_bIsHitting = false;
	}

private:
	bool m_bIsJumping;
	bool m_bIsHitting;
	int m_iHP; 
};


#endif