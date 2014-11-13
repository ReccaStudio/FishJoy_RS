#pragma once;
#include "cocos2d.h"
extern class CollisionBase;


class CollisionContainer:public cocos2d::Node
{
	
	
public:
	CollisionContainer();
	virtual ~CollisionContainer(void);

	bool init()override;

	CREATE_FUNC(CollisionContainer);

	/////// addChild ////////

	using Node::addChild;

    virtual void addChild( CollisionBase * child);
    
    virtual void addChild( CollisionBase * child, int localZOrder);
    
     virtual void addChild( CollisionBase* child, int localZOrder, int tag);
    
    virtual void addChild( CollisionBase* child, int localZOrder, const std::string &name);
    
	
	


	 ////// REMOVES //////

    
    virtual void removeFromParent()override;
    
    virtual void removeFromParentAndCleanup(bool cleanup)override;

	using Node::removeChild;
    virtual void removeChild( CollisionBase* child, bool cleanup = true);

    
    virtual void removeChildByTag(int tag, bool cleanup = true)override;
    
    virtual void removeChildByName(const std::string &name, bool cleanup = true)override;
   
    virtual void removeAllChildren()override;
    
    virtual void removeAllChildrenWithCleanup(bool cleanup)override;

protected:

	cocos2d::Node * transToNode(CollisionBase* child);

};


