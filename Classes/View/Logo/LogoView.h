//
//  LogoView.h
//  
//
//  Created by Íõ¾´ÕÜ
//
//

#ifndef __LogoView__
#define __LogoView__

#include "cocos2d.h"
class LogoView:public cocos2d::Layer
{
public:
    LogoView();
    virtual ~LogoView();
    bool init();
    
    CREATE_FUNC(LogoView);
    
    // a selector callback
	void menuCloseCallback(cocos2d::Ref* pSender);
    
private:
    cocos2d::Sprite* m_logoSprite;
    cocos2d::LayerColor* m_CCNode;
};

#endif /* defined(__payDemo__LogoView__) */
