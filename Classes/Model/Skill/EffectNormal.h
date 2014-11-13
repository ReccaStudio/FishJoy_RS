#pragma once

#include "cocos2d.h"
#include "Effect.h"

extern class Bullet;

class EffectNormal:public Effect
{
public:
	EffectNormal(const BULLET_TYPE &type);
	virtual ~EffectNormal();
	
	bool init(const BULLET_TYPE &type);
	//todo ֻ��׽����,ִ�м��ܼ��� ������ײ
	void excuteEffect(cocos2d::Vector<CollisionBase *> *pvUnitys)override;

	void resetEffect()override;

	static EffectNormal * create(const BULLET_TYPE & type);



	//��ײ���
	virtual bool checkCollison(CollisionBase* other) {return true;}

	virtual void beAttacked(CollisionBase* pActtckter) { };

	//����ʹ��ê��
	virtual cocos2d::Vec2 getCollisonPoint() {return this->getAnchorPoint();};

	//���Ի�ȡ����ģ�ͣ�ʧ����ʹ������߿�
	virtual cocos2d::Rect getCollisonArea() 
	{
		cocos2d::Size temp =  this->getContentSize();
		return cocos2d::Rect(this->getPosition().x,this->getPosition().y,temp.width,temp.height);
	}

protected:

};
