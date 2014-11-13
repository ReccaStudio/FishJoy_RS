#ifndef __STATIC_DATA_H_
#define __STATIC_DATA_H_

#include"cocos2d.h"
#include <vector>

#define STATIC_DATA_STRING(key) StaticData::getInstance()->getStringFromKey(key)
#define STATIC_DATA_INT(key) StaticData::getInstance()->getIntFromKey(key)
#define STATIC_DATA_FLOAT(key) StaticData::getInstance()->getFloatFromKey(key)
#define STATIC_DATA_DOUBLE(key) StaticData::getInstance()->getDoubleFromKey(key)
#define STATIC_DATA_BOOL(key) StaticData::getInstance()->getBooleanFromKey(key)
#define STATIC_DATA_VEC2(key) StaticData::getInstance()->getVec2FromKey(key)
#define STATIC_DATA_RECT(key) StaticData::getInstance()->getRectFromKey(key)
#define STATIC_DATA_SIZE(key) StaticData::getInstance()->getSizeFromKey(key)




class StaticData:public cocos2d::Ref 
{
public:
	
	bool init();
	static StaticData*getInstance(void);
	
	void purge();

	std::string getStringFromKey(std::string key);
	int getIntFromKey(std::string key);
	float getFloatFromKey(std::string key);
	double getDoubleFromKey(std::string key);
	bool getBooleanFromKey(std::string key);
	cocos2d::Vec2 getVec2FromKey(std::string key);
	cocos2d::Rect getRectFromKey(std::string key);
	cocos2d::Size getSizeFromKey(std::string key);


	CC_SYNTHESIZE_READONLY(std::string,m_sDataPath,DataPath);

private:
	StaticData();
	~StaticData();

private:
	static StaticData* s_pInstance;
	cocos2d::__Dictionary * m_pDict;

};



#endif