#include "CollisionSpriteBatch.h"
#include "CollisionBaseManager.h"
#include "CollisionBase.h"
#include "CollisionSprite.h"

USING_NS_CC;
CollisionSpriteBatch::CollisionSpriteBatch():SpriteBatchNode()
{
}

CollisionSpriteBatch::~CollisionSpriteBatch()
{
}

/** creates a SpriteBatchNode with a texture2d and capacity of children.
    The capacity will be increased in 33% in runtime if it run out of space.
    */
CollisionSpriteBatch* CollisionSpriteBatch::createWithTexture(cocos2d::Texture2D* tex, ssize_t capacity)
{
	CollisionSpriteBatch *batchNode = new CollisionSpriteBatch();
    batchNode->initWithTexture(tex, capacity);
    batchNode->autorelease();

    return batchNode;
}

/** creates a SpriteBatchNode with a file image (.png, .jpeg, .pvr, etc) and capacity of children.
    The capacity will be increased in 33% in runtime if it run out of space.
    The file will be loaded using the TextureMgr.
    */
CollisionSpriteBatch* CollisionSpriteBatch::create(const std::string& fileImage, ssize_t capacity)
{
	 CollisionSpriteBatch *batchNode = new CollisionSpriteBatch();
    batchNode->initWithFile(fileImage, capacity);
    batchNode->autorelease();

    return batchNode;
}



void CollisionSpriteBatch::addChild(CollisionSprite * child, int zOrder, int tag) 
{
	SpriteBatchNode::addChild(child,zOrder,tag);
	CollisionBaseManager::getInstance()->push_back(child);
}

void CollisionSpriteBatch::addChild(CollisionSprite * child, int zOrder, const std::string &name)
{
	SpriteBatchNode::addChild(child,zOrder,name);
	CollisionBaseManager::getInstance()->push_back(child);
}
void CollisionSpriteBatch::reorderChild(CollisionSprite *child, int zOrder)
{
	if(CollisionBaseManager::getInstance()->IsExisted(child))
	{
		SpriteBatchNode::reorderChild(child,zOrder);
	}
}
        
void CollisionSpriteBatch::removeChild(CollisionSprite *child, bool cleanup)
{
	CollisionBaseManager::getInstance()->remove(child);
	SpriteBatchNode::removeChild(child,cleanup);
}

void CollisionSpriteBatch::removeAllChildrenWithCleanup(bool cleanup)
{
	CollisionBaseManager::getInstance()->remove(this->getChildren());
	SpriteBatchNode::removeAllChildrenWithCleanup(cleanup);
}
