#ifndef __LG_PAY_LOGIN_SCENE_H__
#define __LG_PAY_LOGIN_SCENE_H__

#include "cocos2d.h"


class LoginScene : public cocos2d::Scene
{
public:
    LoginScene();
    virtual ~ LoginScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  


    
    // implement the "static node()" method manually
    CREATE_FUNC(LoginScene);
    
    /** callback that is called every time the CCNode enters the 'stage'.
     If the CCNode enters the 'stage' with a transition, this callback is called when the transition starts.
     During onEnter you can't a "sister/brother" node.
     */
    virtual void onEnter();
    
    
    /** callback that is called every time the CCNode leaves the 'stage'.
     If the CCNode leaves the 'stage' with a transition, this callback is called when the transition finishes.
     During onExit you can't access a sibling node.
     */
    virtual void onExit();
    
    
    static LoginScene * getInstance();

	void destoyScene();
    

private:
    
    static LoginScene * s_pLoginScene;
	
	CC_SYNTHESIZE_READONLY(cocos2d::Layer *,m_pLayer,LogoLayer);
};

#endif // __LG_PAY_LOGIN_SCENE_H__
