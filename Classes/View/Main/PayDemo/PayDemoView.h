//
//  payDemoView.h
//  payDemo
//
//  Created by Íõ¾´ÕÜ
//
//

#ifndef __PayDemo__LgPayDemoView__
#define __PayDemo__LgPayDemoView__

#include <iostream>
#include "cocos2d.h"
class PayDemoView:public cocos2d::Layer
{
public:
    PayDemoView();
    virtual ~PayDemoView();
    bool init();
    
    CREATE_FUNC(PayDemoView);
    
  
	// a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    

	virtual void onEnter();

	void cleanLogoScene(float loginTime);
    
private:
	float m_fTotalTime;
	cocos2d::MenuItemImage *m_pCloseItem;
    cocos2d::Menu* m_pMenu;
    cocos2d::Label* m_pLabel;
};

#endif /* defined(__lgpayDemo__LgPayDemoView__) */


