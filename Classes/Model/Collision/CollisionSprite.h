#pragma once

#include "cocos2d.h"
#include "CollisionBase.h"

//extern class CollisionContainer;

//暂时不提供复制构造等函数
class CollisionSprite:public cocos2d::Sprite,public CollisionBase
{
public:
	CollisionSprite(Unity_Clan type = Unity_Clan::k_Normal);
	virtual ~CollisionSprite(void);

	 /**
     * Creates an empty sprite without texture. You can call setTexture method subsequently.
     *
     * @return An autoreleased sprite object.
     */
    static CollisionSprite* create();

    /**
     * Creates a sprite with an image filename.
     *
     * After creation, the rect of sprite will be the size of the image,
     * and the offset will be (0,0).
     *
     * @param   filename A path to image file, e.g., "scene1/monster.png"
     * @return  An autoreleased sprite object.
     */
    static CollisionSprite* create(const std::string& filename);

    /**
     * Creates a sprite with an image filename and a rect.
     *
     * @param   filename A path to image file, e.g., "scene1/monster.png"
     * @param   rect     A subrect of the image file
     * @return  An autoreleased sprite object
     */
    static CollisionSprite* create(const std::string& filename, const cocos2d::Rect& rect);

    /**
     * Creates a sprite with a Texture2D object.
     *
     * After creation, the rect will be the size of the texture, and the offset will be (0,0).
     *
     * @param   texture    A pointer to a Texture2D object.
     * @return  An autoreleased sprite object
     */
    static CollisionSprite* createWithTexture(cocos2d::Texture2D *texture);

    /**
     * Creates a sprite with a texture and a rect.
     *
     * After creation, the offset will be (0,0).
     *
     * @param   texture    A pointer to an existing Texture2D object.
     *                      You can use a Texture2D object for many sprites.
     * @param   rect        Only the contents inside the rect of this texture will be applied for this sprite.
     * @param   rotated     Whether or not the rect is rotated
     * @return  An autoreleased sprite object
     */
    static CollisionSprite* createWithTexture(cocos2d::Texture2D *texture, const cocos2d::Rect& rect, bool rotated=false);

    /**
     * Creates a sprite with an sprite frame.
     *
     * @param   spriteFrame    A sprite frame which involves a texture and a rect
     * @return  An autoreleased sprite object
     */
    static CollisionSprite* createWithSpriteFrame(cocos2d::SpriteFrame *spriteFrame);

    /**
     * Creates a sprite with an sprite frame name.
     *
     * A SpriteFrame will be fetched from the SpriteFrameCache by spriteFrameName param.
     * If the SpriteFrame doesn't exist it will raise an exception.
     *
     * @param   spriteFrameName A null terminated string which indicates the sprite frame name.
     * @return  An autoreleased sprite object
     */
    static CollisionSprite* createWithSpriteFrameName(const std::string& spriteFrameName);

    /// @}  end of creators group


	////// Child correlative  /////

	using Sprite::removeChild;
//	virtual void removeChild(CollisionContainer* child, bool cleanup);
	virtual void removeChild(CollisionBase* child, bool cleanup);
    virtual void removeAllChildrenWithCleanup(bool cleanup) override;

	using Sprite::addChild;
	//virtual void addChild(CollisionContainer *child, int zOrder, int tag);
 //   virtual void addChild(CollisionContainer *child, int zOrder, const std::string &name);
    virtual void addChild(CollisionBase *child, int zOrder, int tag);
    virtual void addChild(CollisionBase *child, int zOrder, const std::string &name);




	//////////CollisionBase /////////////////

	//todo
	virtual bool checkCollison(CollisionBase* other)override
	{
		this->beAttacked(other);
		return true;
	}

	//todo
	virtual void beAttacked(CollisionBase* pActtckter)override{};

	//todo
	virtual cocos2d::Vec2 getCollisonPoint()override{ return cocos2d::Vec2::ZERO;};

	//todo
	virtual cocos2d::Rect getCollisonArea()override{ return cocos2d::Rect::ZERO;};


};

