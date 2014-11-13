//
//  LoginView.h
//  payDemo
//
//  Created by Íõ¾´ÕÜ on 13-12-2.
//
//public Layer,

#ifndef __payDemo__LoginView__
#define __payDemo__LoginView__

#include "cocos2d.h"
#include "extensions/cocos-ext.h"

const static float DELTA = 20.0f;


class LoginView:public cocos2d::Layer,public cocos2d::extension::EditBoxDelegate
{
public:
    LoginView();
    virtual ~LoginView();
    bool init();
    
    CREATE_FUNC(LoginView);
    
    static LoginView*getInstance();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    /**
     * This method is called when an edit box gains focus after keyboard is shown.
     * @param editBox The edit box object that generated the event.
     */
    virtual void editBoxEditingDidBegin(cocos2d::extension::EditBox* editBox);
    
    
    /**
     * This method is called when an edit box loses focus after keyboard is hidden.
     * @param editBox The edit box object that generated the event.
     */
    virtual void editBoxEditingDidEnd(cocos2d::extension::EditBox* editBox);
    
    /**
     * This method is called when the edit box text was changed.
     * @param editBox The edit box object that generated the event.
     * @param text The new text.
     */
    virtual void editBoxTextChanged(cocos2d::extension::EditBox* editBox, const std::string& text);
    
    /**
     * This method is called when the return button was pressed or the outside area of keyboard was touched.
     * @param editBox The edit box object that generated the event.
     */
    virtual void editBoxReturn(cocos2d::extension::EditBox* editBox);

protected:
	void LoginToMainView(cocos2d::Ref*,cocos2d::extension::ControlButton::EventType);
    
private:
    cocos2d::Sprite* m_pLogoSprite;
	cocos2d::extension::ControlButton * m_pLoginButton;

    cocos2d::Label * m_pCCText_account;
    cocos2d::Label * m_pCCText_key;
    cocos2d::extension::EditBox* m_pEditName;
    cocos2d::extension::EditBox* m_pEditPassword;
    std::string m_sNameInputText;
    std::string m_sPasswordInputText;

	cocos2d::Label *m_pLabel;

};

#endif /* defined(__payDemo__LoginView__) */


