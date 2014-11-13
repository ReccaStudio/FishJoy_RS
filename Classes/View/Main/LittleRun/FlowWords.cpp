#include "FlowWords.h"
USING_NS_CC;


FlowWords::FlowWords():m_pTextLab(NULL)
{

}

FlowWords::~FlowWords()
{

}


bool FlowWords::init()
{

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	m_pTextLab = Label::createWithTTF("", "arial.ttf", 35);
#else if(CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 || CC_TARGET_PLATFORM ==  CC_PLATFORM_ANDROID)
	m_pTextLab = Label::createWithTTF("", "fonts/arial.ttf", 35);
#endif


	m_pTextLab->setColor(Color3B(255,0,0));
	m_pTextLab->setVisible(false);
	this->addChild(m_pTextLab);
	return true;
}

void FlowWords::showWords(const char *text,Vec2 pos,Size contentSize)
{
	m_pTextLab->setString(text);
	pos.y = pos.y + contentSize.height/2;
	m_pTextLab->setPosition(pos);
	m_pTextLab->setVisible(true);

	 ActionInterval *pScaleLarge =  ScaleTo::create(0.3f,3.5f,2.5f);
	 ActionInterval *pScaleSmall =  ScaleTo::create(0.5f,0.5f,0.5f);
	 ActionInterval *pMoveBy =  MoveBy::create(0.8f,Vec2(0,100));



	 CallFunc * pCallFunc =  CallFunc::create(CC_CALLBACK_0(FlowWords::flowEnd,this));

	 ActionInterval * actions =  Sequence::create( Spawn::create(pMoveBy, Sequence::create(pScaleLarge,pScaleSmall,NULL),NULL),pCallFunc,NULL);
	
	m_pTextLab->runAction(actions);

}
void FlowWords::flowEnd()
{
	m_pTextLab->setVisible(false);
	m_pTextLab->removeFromParentAndCleanup(true);
}