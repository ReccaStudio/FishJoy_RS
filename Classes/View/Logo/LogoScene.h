#ifndef __LOGO_SCENE_H__
#define __LOGO_SCENE_H__

#include "cocos2d.h"


class LogoScene : public cocos2d::Scene
{
public:
    LogoScene();
    virtual ~ LogoScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

//    // there's no 'id' in cpp, so we recommend returning the class instance pointer
//    static cocos2d::Scene* scene();
    
    // implement the "static node()" method manually
    CREATE_FUNC(LogoScene);
    
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
    
    void logoUI(float logoTime);
    
    
private:
    cocos2d::Layer *m_pLayer;
    float m_fTotalTime;
};

#endif // __LG_PAY_LOGO_SCENE_H__
