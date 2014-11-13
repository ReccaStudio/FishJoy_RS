/*
* //Jingz
* Actually,this manger just remember which unity had been added into screen. 
* And so on, it never changed the data of the unitys'
*/


#pragma once;
#include <vector>
#include "cocos2d.h"
extern class CollisionBase;

//only the CollisionBase can use this mechanism//机制

/*
* 只有CollisionContainer->addChild(CollisionBase*)类似函数才会触发此机制
* 此碰撞筛选机制的目的是清理不必要的碰撞实体，只保留碰撞容器下的碰撞精灵CollisionBase
* 向其他模块提供检测接口，检测与目标CollisionBase * p 产生碰撞的精灵Vector。
*/


class CollisionBaseManager
{
public:
	CollisionBaseManager();
	~CollisionBaseManager();

	static CollisionBaseManager * getInstance();

	void push_back(CollisionBase * p);

	void remove(CollisionBase * p);


	void remove(cocos2d::Vector<cocos2d::Node*> nodesArray);

	CollisionBase * findUnityByTag(int tag);

	bool IsExisted(CollisionBase * p);

	//todo 同族不检测碰撞
	void countCrashedUnitys(CollisionBase * p ,cocos2d::Vector<CollisionBase *> *pTargetUnitys);



private:
	static CollisionBaseManager * s_pCollisionBaseManager;

	cocos2d::Vector<CollisionBase *> * m_pv_CollisionBase;
};

