#include "FishingNode.h"
#include "./../Classes/Model/StaticData.h"
#include "./../Classes/GameConfig.h"
#include "../Cannon/CannonNode.h"
#include "../Skill/BulletNode.h"

USING_NS_CC;

 FishingNode * FishingNode::create(WEAPON_TYPE type)
 {
	 FishingNode * pRet = new FishingNode();
	 if (pRet&&pRet->init(type))
	 {
		 return pRet;
	 }
	 else
	 {
		 delete pRet;
		 pRet = nullptr;
		 return pRet;
	 }
 }
	
 bool FishingNode::init(WEAPON_TYPE type)
 {

	 return true;
 }


//���ֵ���
void FishingNode::aimAt(cocos2d::Vec2 worldTarget)
{
	m_pCannonNode->aimAt(worldTarget);
}

bool FishingNode::shootTo(cocos2d::Vec2 touchLocation)
{
	//todo ÿ���ӵ����Ƽ���һ�����䶳ʱ�䣬������Ҫ���ӵ�ʵ�ֵ������֮������cd
	
	if (this->canShootAble())
	{
		float distance = 180 * (m_pCannonNode->getCannonType()+1);
		Vec2 normal = touchLocation-this->getParent()->convertToWorldSpace(this->getPosition());
		Vec2 target = this->getPosition()+normal.getNormalized()*distance;
		m_pBulletNode->playEffect(target);
		m_fColdDownRemain = m_fColdDownTime;

		//todo ������ʱ��		
		return true;
	
	}
	else
	{
		return false;
	}
}
	

//void FishingNode::capture(Vector<CollisionSprite *> *pvUnitys)
//{
//	std::string tempKey;
//	for (auto it = pvUnitys->begin(); it != pvUnitys->end();)
//	{
//		if ((*it)->getUnityClan()==Unity_Clan::k_Fish_Type)
//		{
//			std::string tempString = STATIC_DATA_STRING(GameConfig::FISH_PROBABILITY);
//			tempKey = StringUtils::format(tempString.c_str(),static_cast<int>(type));
//			float fishProbability = STATIC_DATA_FLOAT(tempKey);
//
//			tempString = STATIC_DATA_STRING(GameConfig::WEAPON_PROBABILITY);
//			tempKey = StringUtils::format(tempString.c_str(),static_cast<int>(type));
//			float weaponProbability = STATIC_DATA_FLOAT(temp);
//
//			float percentage = fishProbability*weaponProbability;
//			if (CCRANDOM_0_1()<percentage)
//			{
//				(*it)->beAttacked(this);
//				++it;
//				continue;
//			}
//			else
//			{
//				pvUnitys->erase(it);
//				continue;
//			}//if_else_random
//		}
//		else
//		{
//			pvUnitys->erase(it);
//			continue;
//		}//if_else_fish
//	}
//}
