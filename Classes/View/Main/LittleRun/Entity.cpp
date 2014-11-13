#include "Entity.h"
USING_NS_CC;

Entity::Entity()
{
	m_pSprite = NULL;
}

Entity::~Entity()
{
}

Sprite* Entity::getSprite()
{
	return this->m_pSprite;
}
	
void Entity::blindSprite(Sprite * pSprite)
{
	this->removeChildByTag(999);
	m_pSprite = pSprite;
	this->addChild(m_pSprite,1,999);
}