#include "CannonNode.h"
#include "CannonNormal.h"

CannonNode::CannonNode():m_eCannonType(WEAPON_TYPE::k_Invalid)
{
}

CannonNode::~CannonNode()
{
}

//todo
bool CannonNode::init()
{
	m_vPools.clear();
	m_vPools.pushBack(CannonNormal::create(WEAPON_TYPE::k_Bullet_1));
	m_vPools.pushBack(CannonNormal::create(WEAPON_TYPE::k_Bullet_2));
	this->setCannonType(WEAPON_TYPE::k_Bullet_1);
	return true;
}


//todo 
WEAPON_TYPE CannonNode::getCannonType()
{
	return m_eCannonType;
}

//todo 
void CannonNode::setCannonType(WEAPON_TYPE type)
{
	if (type!=m_eCannonType)
	{
		if (type>=WEAPON_TYPE::k_Invalid)
		{
			type = WEAPON_TYPE::k_Bullet_1;
		}
		else if (type<WEAPON_TYPE::k_Bullet_1)
		{
			type =WEAPON_TYPE(WEAPON_TYPE::k_Invalid-1);
		}
		if ( m_eCannonType>=WEAPON_TYPE(0) && m_eCannonType<=WEAPON_TYPE::k_Invalid)
		{
			this->removeChildByTag(m_eCannonType);
		}
		
		AbstractCannon * newCannonNormal = dynamic_cast<AbstractCannon*>(m_vPools.at(type));
		this->addChild(newCannonNormal,0, (int)type);
		m_eCannonType = type;
	}
	

	
}

void CannonNode::aimAt(cocos2d::Vec2 worldTarget)
{
	AbstractCannon * newCannonNormal = getCannonSprite();
	newCannonNormal->aimAt(worldTarget);
}
