#include "StaticData.h"
USING_NS_CC;
#include "Gameconfig.h"

StaticData::StaticData()
{
	
}

StaticData::~StaticData()
{
	CC_SAFE_RELEASE_NULL(s_pInstance);
}

StaticData* StaticData::s_pInstance = nullptr;



StaticData * StaticData::getInstance(void)
{
	if (s_pInstance==nullptr||s_pInstance==NULL)
	{
		s_pInstance = new StaticData();
		s_pInstance->init();
	}
	return s_pInstance;
}

bool StaticData::init()
{
	m_sDataPath = GameConfig::USER_DATA;
	m_pDict = __Dictionary::createWithContentsOfFile(m_sDataPath.c_str());
	CC_SAFE_RETAIN(m_pDict);

	return true;
}

void StaticData::purge()
{
	this->~StaticData();
}

std::string StaticData::getStringFromKey(std::string key)
{
	return m_pDict->valueForKey(key)->_string;
}

int StaticData::getIntFromKey(std::string key)
{
	return  m_pDict->valueForKey(key)->intValue();
}

float StaticData::getFloatFromKey(std::string key)
{
	return m_pDict->valueForKey(key)->floatValue();
}

double StaticData::getDoubleFromKey(std::string key)
{
	return m_pDict->valueForKey(key)->doubleValue();
}

bool StaticData::getBooleanFromKey(std::string key)
{
	return m_pDict->valueForKey(key)->boolValue();
}


Vec2 StaticData::getVec2FromKey(std::string key)
{
	__String s = __String(m_pDict->valueForKey(key)->getCString());
	__Array *t = s.componentsSeparatedByString(",");
	__String* data1 = static_cast<__String*>(t->getObjectAtIndex(0));
	__String* data2 = static_cast<__String*>(t->getObjectAtIndex(1));
	return Vec2(data1->floatValue(),data2->floatValue());
		
}

//存储方式重新修改，暂时找不到直接api
//todo
Rect StaticData::getRectFromKey(std::string key)
{
	__String s = __String(m_pDict->valueForKey(key)->getCString());
	__Array *t = s.componentsSeparatedByString(",");
	__String* data1 = static_cast<__String*>(t->getObjectAtIndex(0));
	__String* data2 = static_cast<__String*>(t->getObjectAtIndex(1));
	__String* data3 = static_cast<__String*>(t->getObjectAtIndex(2));
	__String* data4 = static_cast<__String*>(t->getObjectAtIndex(3));
	return Rect(data1->floatValue(),data2->floatValue(),data3->floatValue(),data4->floatValue());
}

Size StaticData::getSizeFromKey(std::string key)
{
	__String s = __String(m_pDict->valueForKey(key)->getCString());
	__Array *t = s.componentsSeparatedByString(",");
	__String* data1 = static_cast<__String*>(t->getObjectAtIndex(0));
	__String* data2 = static_cast<__String*>(t->getObjectAtIndex(1));
	return Size(data1->floatValue(),data2->floatValue());
}