#include "CollisionSprite.h"
//#include "CollisionContainer.h"

USING_NS_CC;
#include "CollisionBaseManager.h"


CollisionSprite::CollisionSprite(Unity_Clan type)
	:Node(),CollisionBase(type),Sprite()	
{
}

CollisionSprite::~CollisionSprite()
{
}



CollisionSprite* CollisionSprite::create()
{
	CollisionSprite *sprite = new (std::nothrow) CollisionSprite();
    if (sprite && sprite->init())
    {
        sprite->autorelease();
        return sprite;
    }
    CC_SAFE_DELETE(sprite);
    return nullptr;
}


CollisionSprite* CollisionSprite::create(const std::string& filename)
{
	CollisionSprite *sprite = new (std::nothrow) CollisionSprite();
    if (sprite && sprite->initWithFile(filename))
    {
        sprite->autorelease();
        return sprite;
    }
    CC_SAFE_DELETE(sprite);
    return nullptr;
}


CollisionSprite* CollisionSprite::create(const std::string& filename, const Rect& rect)
{
	CollisionSprite *sprite = new (std::nothrow) CollisionSprite();
    if (sprite && sprite->initWithFile(filename, rect))
    {
        sprite->autorelease();
        return sprite;
    }
    CC_SAFE_DELETE(sprite);
    return nullptr;
}


CollisionSprite* CollisionSprite::createWithTexture(Texture2D *texture)
{
	CollisionSprite *sprite = new (std::nothrow) CollisionSprite();
    if (sprite && sprite->initWithTexture(texture))
    {
        sprite->autorelease();
        return sprite;
    }
    CC_SAFE_DELETE(sprite);
    return nullptr;
}


CollisionSprite* CollisionSprite::createWithTexture(Texture2D *texture, const Rect& rect, bool rotated)
{
	CollisionSprite *sprite = new (std::nothrow) CollisionSprite();
    if (sprite && sprite->initWithTexture(texture, rect, rotated))
    {
        sprite->autorelease();
        return sprite;
    }
    CC_SAFE_DELETE(sprite);
    return nullptr;
}


CollisionSprite* CollisionSprite::createWithSpriteFrame(SpriteFrame *spriteFrame)
{
	CollisionSprite *sprite = new (std::nothrow) CollisionSprite();
    if (sprite && spriteFrame && sprite->initWithSpriteFrame(spriteFrame))
    {
        sprite->autorelease();
        return sprite;
    }
    CC_SAFE_DELETE(sprite);
    return nullptr;
}


CollisionSprite* CollisionSprite::createWithSpriteFrameName(const std::string& spriteFrameName)
{
	SpriteFrame *frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(spriteFrameName);
    
#if COCOS2D_DEBUG > 0
    char msg[256] = {0};
    sprintf(msg, "Invalid spriteFrameName: %s", spriteFrameName.c_str());
    CCASSERT(frame != nullptr, msg);
#endif
    
    return createWithSpriteFrame(frame);
}

/// @}  end of creators group


	////// Child correlative  /////


//void CollisionSprite::removeChild(CollisionContainer* child, bool cleanup)
//{
//	CollisionBaseManager::getInstance()->remove(child);
//	Sprite::removeChild(child,cleanup);
//}

void CollisionSprite::removeChild(CollisionBase* child, bool cleanup)
{
	CollisionBaseManager::getInstance()->remove(child);
	Sprite::removeChild(child,cleanup);
}

void CollisionSprite::removeAllChildrenWithCleanup(bool cleanup)
{
	CollisionBaseManager::getInstance()->remove(this->getChildren());
	Sprite::removeAllChildrenWithCleanup(cleanup);
}


//void CollisionSprite::addChild(CollisionContainer *child, int zOrder, int tag)
//{
//	Sprite::addChild(child,zOrder,tag);
//	CollisionBaseManager::getInstance()->push_back(child);
//}
//
//void CollisionSprite::addChild(CollisionContainer *child, int zOrder, const std::string &name)
//{
//	Sprite::addChild(child,zOrder,name);
//	CollisionBaseManager::getInstance()->push_back(child);
//}

void CollisionSprite::addChild(CollisionBase *child, int zOrder, int tag)
{
	Sprite::addChild(child,zOrder,tag);
	CollisionBaseManager::getInstance()->push_back(child);
}

void CollisionSprite::addChild(CollisionBase *child, int zOrder, const std::string &name)
{
	Sprite::addChild(child,zOrder,name);
	CollisionBaseManager::getInstance()->push_back(child);
}