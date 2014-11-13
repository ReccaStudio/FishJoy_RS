#ifndef __PAY_DEMO_SCENE_H__
#define __PAY_DEMO_SCENE_H__

#include "cocos2d.h"
#include "PayDemoView.h"

class PayDemoScene : public cocos2d::Scene
{
public:
    PayDemoScene();
    virtual ~ PayDemoScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

//    // there's no 'id' in cpp, so we recommend returning the class instance pointer
//    static cocos2d::Scene* scene();
    
    // implement the "static node()" method manually
    CREATE_FUNC(PayDemoScene);
    
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

	static PayDemoScene*getInstance();

    void destoyScene();

    
    CC_SYNTHESIZE_READONLY(cocos2d::Layer* ,m_pLayer,LogoLayer)


private:
	static PayDemoScene * s_pPayDemoScene;
};

#endif // __LG_PAY_DEMO_SCENE_H__
