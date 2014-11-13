#include "BulletNode.h"
#include "BulletManager.h"

BulletNode::BulletNode()
	:CollisionContainer()
{
	m_pBullet = nullptr;
}

BulletNode::~BulletNode()
{
	if (m_pBullet!=nullptr || m_pBullet!=NULL)
	{
		CC_SAFE_RELEASE_NULL(m_pBullet);
	}
	
}

bool BulletNode::init(BULLET_TYPE type)
{
	CollisionContainer::init();
	this->setCurSkillType(type);

	return true;
}

BulletNode* BulletNode::create() 
{ 
    BulletNode *pRet = new BulletNode(); 
    if (pRet && pRet->init()) 
    { 
        pRet->autorelease(); 
        return pRet; 
    } 
    else 
    { 
        delete pRet; 
        pRet = NULL; 
        return NULL; 
    } 
}

//todo
void BulletNode::playEffect(cocos2d::Vec2 targetInWorldSpace)
{
	if (m_pBullet==nullptr || m_pBullet==NULL)
	{
		m_pBullet = BulletManager::getInstance()->requstBullet(m_eCurType);
	}
	

	this->addChild(m_pBullet);

	m_pBullet->flyTo(targetInWorldSpace);

	setCurSkillType(m_pBullet->getBulletType());
}


void BulletNode::effectEndCallBack(Bullet *pBullet)
{
	//todo 先将信息传递给特效
	this->removeChild(pBullet);
	BulletManager::getInstance()->returnBullet(pBullet);
}

