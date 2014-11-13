/*
* //Jingz
* Actually,this manger just remember which unity had been added into screen. 
* And so on, it never changed the data of the unitys'
*/


#pragma once;
#include <vector>
#include "cocos2d.h"
extern class CollisionBase;

//only the CollisionBase can use this mechanism//����

/*
* ֻ��CollisionContainer->addChild(CollisionBase*)���ƺ����Żᴥ���˻���
* ����ײɸѡ���Ƶ�Ŀ����������Ҫ����ײʵ�壬ֻ������ײ�����µ���ײ����CollisionBase
* ������ģ���ṩ���ӿڣ������Ŀ��CollisionBase * p ������ײ�ľ���Vector��
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

	//todo ͬ�岻�����ײ
	void countCrashedUnitys(CollisionBase * p ,cocos2d::Vector<CollisionBase *> *pTargetUnitys);



private:
	static CollisionBaseManager * s_pCollisionBaseManager;

	cocos2d::Vector<CollisionBase *> * m_pv_CollisionBase;
};

