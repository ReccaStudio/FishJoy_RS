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
	//todo 只捕捉鱼类,执行技能计算 计算碰撞
	void excuteEffect(cocos2d::Vector<CollisionBase *> *pvUnitys)override;

	void resetEffect()override;

	static EffectNormal * create(const BULLET_TYPE & type);



	//碰撞相关
	virtual bool checkCollison(CollisionBase* other) {return true;}

	virtual void beAttacked(CollisionBase* pActtckter) { };

	//优先使用锚点
	virtual cocos2d::Vec2 getCollisonPoint() {return this->getAnchorPoint();};

	//尝试获取物理模型，失败则使用纹理边框
	virtual cocos2d::Rect getCollisonArea() 
	{
		cocos2d::Size temp =  this->getContentSize();
		return cocos2d::Rect(this->getPosition().x,this->getPosition().y,temp.width,temp.height);
	}

protected:

};
