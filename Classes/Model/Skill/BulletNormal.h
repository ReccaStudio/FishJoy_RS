#pragma once

#include "cocos2d.h"
#include "Bullet.h"


class BulletNormal:public Bullet
{
public:
	BulletNormal(const BULLET_TYPE &type);
	virtual ~BulletNormal();
	
	static BulletNormal* create(const BULLET_TYPE & type);

	bool init(const BULLET_TYPE &type);

	void flyTo(cocos2d::Vec2 targetInWorldSpace)override;

	void end()override;

	//碰撞相关
	virtual bool checkCollison(CollisionBase* other)override {return true;}

	virtual void beAttacked(CollisionBase* pActtckter)override { };

	//优先使用锚点
	virtual cocos2d::Vec2 getCollisonPoint()override
	{
		return this->getParent()->convertToWorldSpace(this->getPosition());
	}

	//todo
	//尝试获取物理模型，失败则使用纹理边框
	virtual cocos2d::Rect getCollisonArea()override 
	{
		cocos2d::Size temp =  this->getContentSize();
		return cocos2d::Rect(this->getPosition().x,this->getPosition().y,temp.width,temp.height);
	}

};