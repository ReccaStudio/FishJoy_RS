//
//  LoginView.cpp
//  payDemo
//
//  Created by Íõ¾´ÕÜ on 13-12-2.
//
//

#include "LoginView.h"
#include "Gameconfig.h"
#include "SceneFactory.h"
#include  "extensions/GUI/CCEditBox/CCEditBox.h"
#include  "extensions/GUI/CCControlExtension/CCScale9Sprite.h"
USING_NS_CC;
USING_NS_CC_EXT;


//////////////////////////////
// 1. super init first
LoginView::LoginView()
:Layer()
,m_pLoginButton(NULL)
,m_pLogoSprite(NULL)
,m_pCCText_account(NULL)
,m_pCCText_key(NULL)
,m_sNameInputText("")
,m_sPasswordInputText("")
,m_pEditName(NULL)
,m_pEditPassword(NULL)
{
    
}


LoginView::~LoginView()
{

   
}
bool LoginView::init()
{
    if ( !Layer::init() )
    {
        return false;
    }


    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 visibleOrigin = Director::getInstance()->getVisibleOrigin();
	//log("IOS---------------LoginScene:%d,%d,%d,%d",visibleSize.width,visibleSize.height,visibleOrigin.x,visibleOrigin.y);

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    m_pLabel = Label::createWithTTF("LoginScene", "Paint Boy.ttf", 24);
#else if(CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 || CC_TARGET_PLATFORM ==  CC_PLATFORM_ANDROID)
	m_pLabel = Label::createWithTTF("LoginScene", "fonts/Paint Boy.ttf", 24);
#endif

    
    // position the label on the center of the screen
    m_pLabel->setPosition(Vec2(visibleOrigin.x + visibleSize.width/2,
                            visibleOrigin.y + visibleSize.height - m_pLabel->getContentSize().height));
    
    // add the label as a child to this layer
    this->addChild(m_pLabel, 1);

    
	Sprite* pBg = Sprite::create("HelloWorld.png");
    pBg->setPosition(Vec2(visibleOrigin.x+visibleSize.width/2,visibleOrigin.y+visibleSize.height/2));
	this->addChild(pBg);

    Size editBoxSize = Size(visibleSize.width/5*3, visibleSize.height/7);

    // top
	auto tempS9Spr = Scale9Sprite::create("green_edit.png");
	CCASSERT(tempS9Spr!=nullptr && tempS9Spr !=NULL,"green_edit.png S9Spr failed");
    m_pEditName = EditBox::create(editBoxSize,tempS9Spr );

    m_pEditName->setPosition(Vec2(visibleOrigin.x+visibleSize.width/2, visibleOrigin.y+visibleSize.height*3/4));

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    m_pEditName->setFontName("Paint Boy.ttf");
#else if(CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 || CC_TARGET_PLATFORM ==  CC_PLATFORM_ANDROID)
	m_pEditName->setFontName("fonts/Paint Boy.ttf");
#endif
    m_pEditName->setFontSize(25);
	m_pEditName->setFontColor(Color3B::RED);
    m_pEditName->setPlaceHolder("Account");
	m_pEditName->setPlaceholderFontColor(Color3B::WHITE);
    m_pEditName->setMaxLength(20);
	m_pEditName->setReturnType(EditBox::KeyboardReturnType::DONE);
    m_pEditName->setDelegate(this);
    this->addChild(m_pEditName);
    
    // middle
    m_pEditPassword = EditBox::create(editBoxSize, Scale9Sprite::create("green_edit.png"));
    m_pEditPassword->setPosition(Vec2(visibleOrigin.x+visibleSize.width/2, visibleOrigin.y+visibleSize.height/2));
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	m_pEditPassword->setFont("arial.ttf", 30);
#else if(CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 || CC_TARGET_PLATFORM ==  CC_PLATFORM_ANDROID)
	m_pEditPassword->setFont("fonts/arial.ttf", 30);
#endif
	m_pEditPassword->setFontColor(Color3B::GREEN);
    m_pEditPassword->setPlaceHolder("Password:");
    m_pEditPassword->setMaxLength(20);
	m_pEditPassword->setInputFlag(EditBox::InputFlag::PASSWORD);
	m_pEditPassword->setInputMode(EditBox::InputMode::SINGLE_LINE);
    m_pEditPassword->setDelegate(this);
    this->addChild(m_pEditPassword);
        

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    Label* pLabel = Label::createWithTTF("Login", "arial.ttf", 30);
#else if(CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 || CC_TARGET_PLATFORM ==  CC_PLATFORM_ANDROID)
	Label* pLabel = Label::createWithTTF("Login", "fonts/arial.ttf", 30);
#endif
	
	

	CCAssert(pLabel,"Login Label is NULL");


	m_pLoginButton =ControlButton::create(pLabel,Scale9Sprite::create("green_edit.png"));
	m_pLoginButton->setPosition(Vec2(visibleOrigin.x+visibleSize.width/2,
								visibleOrigin.y+visibleSize.height*1/4 - pLabel->getContentSize().height));
	

	m_pLoginButton->addTargetWithActionForControlEvents(this,cccontrol_selector(LoginView::LoginToMainView), ControlButton::EventType::TOUCH_DOWN);

    this->addChild(m_pLoginButton);



#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	m_pCCText_account = Label::createWithTTF("Login", "arial.ttf", 30);
#else if(CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 || CC_TARGET_PLATFORM ==  CC_PLATFORM_ANDROID)
	m_pCCText_account = Label::createWithTTF("Login", "fonts/arial.ttf", 30);
#endif
  
	m_pCCText_account->setVisible(false);
	m_pCCText_account->setPosition(Vec2(visibleOrigin.x+visibleSize.width/3,
								visibleOrigin.y + pLabel->getContentSize().height));
	this->addChild(m_pCCText_account);

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	m_pCCText_key = Label::createWithTTF("Login", "arial.ttf", 30);
#else if(CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 || CC_TARGET_PLATFORM ==  CC_PLATFORM_ANDROID)
	m_pCCText_key = Label::createWithTTF("Login", "fonts/arial.ttf", 30);
#endif

	m_pCCText_key->setVisible(false);
	m_pCCText_key->setPosition(Vec2(visibleOrigin.x+visibleSize.width*2/3,
								visibleOrigin.y + pLabel->getContentSize().height));
	this->addChild(m_pCCText_key);
    
    return true;
}




void LoginView::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}


/**
 * This method is called when an edit box gains focus after keyboard is shown.
 * @param editBox The edit box object that generated the event.
 */
void LoginView::editBoxEditingDidBegin(EditBox* editBox)
{
    
}


/**
 * This method is called when an edit box loses focus after keyboard is hidden.
 * @param editBox The edit box object that generated the event.
 */
void LoginView::editBoxEditingDidEnd(EditBox* editBox)
{

}

/**
 * This method is called when the edit box text was changed.
 * @param editBox The edit box object that generated the event.
 * @param text The new text.
 */
void LoginView::editBoxTextChanged(EditBox* editBox, const std::string& text)
{

}

/**
 * This method is called when the return button was pressed or the outside area of keyboard was touched.
 * @param editBox The edit box object that generated the event.
 */
void LoginView::editBoxReturn(EditBox* editBox)
{
    log("editBox %p was returned !",editBox);
	std::string temp;
    
    if (m_pEditName == editBox)
    {
		m_sNameInputText = m_pEditName->getText();
		if (!m_sNameInputText.empty())
		{
			temp = std::string("Account:");
		}
		
		temp.append(m_sNameInputText);
		m_pCCText_account->setString(temp.c_str());
		m_pCCText_account->setVisible(true);
    }
    else if (m_pEditPassword == editBox)
    {
		m_sPasswordInputText = m_pEditPassword->getText();
		if (!m_sNameInputText.empty())
		{
			temp = std::string("PW:");
		}
		temp.append(m_sPasswordInputText);
		m_pCCText_key->setString(temp.c_str());
		m_pCCText_key->setVisible(true);
    }

	
}


void LoginView::LoginToMainView(Ref*, ControlButton::EventType)
{
	Director * pDirector = Director::getInstance();
    pDirector->replaceScene(SceneFactory::create(GameConfig::CHOOSE_TABELVIEW));

}