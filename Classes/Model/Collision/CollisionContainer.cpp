#include "CollisionContainer.h"
USING_NS_CC;
#include "CollisionBaseManager.h"
#include "CollisionBase.h"

CollisionContainer::CollisionContainer():Node()
{

}

CollisionContainer::~CollisionContainer(void)
{

}

void CollisionContainer::addChild(CollisionBase * child)
{

	Node * pNode = transToNode(child);
	this->addChild(pNode, pNode->getLocalZOrder(), pNode->getName());

	CollisionBaseManager::getInstance()->push_back(child);
	
}
    
void CollisionContainer::addChild(CollisionBase * child, int localZOrder)
{
	Node * pNode = transToNode(child);
	this->addChild(pNode, localZOrder, pNode->getName());
	CollisionBaseManager::getInstance()->push_back(child);
}
    
void CollisionContainer::addChild(CollisionBase* child, int localZOrder, int tag)
{
	Node * pNode = transToNode(child);
	this->addChild(pNode, localZOrder, tag);
	CollisionBaseManager::getInstance()->push_back(child);
}
    
void CollisionContainer::addChild(CollisionBase* child, int localZOrder, const std::string &name)
{
	Node * pNode = transToNode(child);
	this->addChild(pNode, localZOrder, name);
	CollisionBaseManager::getInstance()->push_back(child);
}
	
bool CollisionContainer::init()
{
	return Node::init();
}



	 ////// REMOVES //////

    
void CollisionContainer::removeFromParent()
{
	//CollisionBaseManager::getInstance()->remove(this);
	Node::removeFromParent();
	
}
    
void CollisionContainer::removeFromParentAndCleanup(bool cleanup)
{
	//CollisionBaseManager::getInstance()->remove(this);
	Node::removeFromParentAndCleanup(cleanup);
}

    
void CollisionContainer::removeChild(CollisionBase* child, bool cleanup)
{
	CollisionBaseManager::getInstance()->remove(child);
	Node * pNode = transToNode(child);
	Node::removeChild(pNode,cleanup);
}

    
void CollisionContainer::removeChildByTag(int tag, bool cleanup)
{
	CollisionBaseManager::getInstance()->findUnityByTag(tag);
	Node::removeChildByTag(tag,cleanup);
}


void CollisionContainer::removeChildByName(const std::string &name, bool cleanup)
{
	CollisionBaseManager::getInstance()->remove(dynamic_cast<CollisionBase*>(this->getChildByName(name)));
	
	Node::removeChildByName(name,cleanup);
}
   
void CollisionContainer::removeAllChildren()
{
	CollisionBaseManager::getInstance()->remove(this->getChildren());
	Node::removeAllChildren();
}
    
void CollisionContainer::removeAllChildrenWithCleanup(bool cleanup)
{
	CollisionBaseManager::getInstance()->remove(this->getChildren());
	Node::removeAllChildrenWithCleanup(cleanup);
}


Node * CollisionContainer::transToNode(CollisionBase* child)
{
	Node * pNode;
	try
	{
		pNode= static_cast<Node * >(child);
	}
	catch(std::runtime_error )
	{

	}
	CCAssert(pNode!=nullptr,"please use CollisionContainer or CollisionBase");
	return pNode;
}