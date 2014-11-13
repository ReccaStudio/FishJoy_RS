#pragma once
#include "cocos2d.h"

extern class CollisionSprite;

class CollisionSpriteBatch:public cocos2d::SpriteBatchNode
{
public:
	CollisionSpriteBatch();
	~CollisionSpriteBatch();

	/** creates a SpriteBatchNode with a texture2d and capacity of children.
     The capacity will be increased in 33% in runtime if it run out of space.
     */
    static CollisionSpriteBatch* createWithTexture(cocos2d::Texture2D* tex, ssize_t capacity = DEFAULT_CAPACITY);

    /** creates a SpriteBatchNode with a file image (.png, .jpeg, .pvr, etc) and capacity of children.
     The capacity will be increased in 33% in runtime if it run out of space.
     The file will be loaded using the TextureMgr.
     */
    static CollisionSpriteBatch* create(const std::string& fileImage, ssize_t capacity = DEFAULT_CAPACITY);

    void addChild(CollisionSprite * child, int zOrder, int tag) ;
    void addChild(CollisionSprite * child, int zOrder, const std::string &name);
    void reorderChild(CollisionSprite *child, int zOrder);
        
    void removeChild(CollisionSprite *child, bool cleanup);
    void removeAllChildrenWithCleanup(bool cleanup) override;

	
private:

};
