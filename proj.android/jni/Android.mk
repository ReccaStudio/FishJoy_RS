LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

$(call import-add-path,$(LOCAL_PATH)/../../cocos2d)
$(call import-add-path,$(LOCAL_PATH)/../../cocos2d/external)
$(call import-add-path,$(LOCAL_PATH)/../../cocos2d/cocos)

LOCAL_MODULE := cocos2dcpp_shared

LOCAL_MODULE_FILENAME := libcocos2dcpp

LOCAL_SRC_FILES := hellocpp/main.cpp \
                   ../../Classes/AppDelegate.cpp \
                   ../../Classes/HelloWorldScene.cpp \
				   ../../Classes/GameConfig.cpp \
				   ../../Classes/SceneFactory.cpp \
				   ../../Classes/View/Main/PayDemo/PayDemoScene.cpp \
				   ../../Classes/View/Main/PayDemo/PayDemoView.cpp \
				   \
				   ../../Classes/View/Main/FishingJoy/PanelLayer.cpp \
				   ../../Classes/View/Main/FishingJoy/TouchLayer..cpp \
				   ../../Classes/View/Main/FishingJoy/MenuLayer.cpp \
				   ../../Classes/View/Main/FishingJoy/GameScene.cpp \
				   ../../Classes/View/Main/FishingJoy/FishLayer.cpp \
				   ../../Classes/View/Main/FishingJoy/CannonLayer.cpp \
				   ../../Classes/View/Main/FishingJoy/BackgroundLayer.cpp \
					\
				   ../../Classes/View/Main/LittleRun/TollgateScene.cpp \
				   ../../Classes/View/Main/LittleRun/Player.cpp \
				   ../../Classes/View/Main/LittleRun/MonsterManager.cpp \
				   ../../Classes/View/Main/LittleRun/Monster.cpp \
				   ../../Classes/View/Main/LittleRun/FlowWords.cpp \
				   ../../Classes/View/Main/LittleRun/Entity.cpp \
				   \
				   ../../Classes/View/logo/LogoScene.cpp \
				   ../../Classes/View/logo/LogoView.cpp \
				   \
				   ../../Classes/View/login/LoginScene.cpp \
				   ../../Classes/View/login/LoginView.cpp \
				   ../../Classes/View/login/ChooseTableView.cpp\
				   \
				   ../../Classes/Model/Fish.cpp \
				   ../../Classes/Model/FishingJoyData.cpp \
				   ../../Classes/Model/StaticData.cpp \
				   \
				   ../../Classes/Model/Cannon/CannonNode.cpp \
				   ../../Classes/Model/Cannon/CannonNormal.cpp \
				   \
				   ../../Classes/Model/Collision/CollisionBaseManager.cpp \
				   ../../Classes/Model/Collision/CollisionContainer.cpp \
				   ../../Classes/Model/Collision/CollisionSprite.cpp \
				   ../../Classes/Model/Collision/CollisionSpriteBatch.cpp \
				   \
				   ../../Classes/Model/Skill/BulletNode.cpp \
				   ../../Classes/Model/Skill/BulletBatchNode.cpp \
				   ../../Classes/Model/Skill/Effect.cpp \
				   ../../Classes/Model/Skill/EffectManager.cpp \
				   ../../Classes/Model/Skill/EffectNormal.cpp \
				   ../../Classes/Model/Skill/EffectNormalFactory.cpp \
				   ../../Classes/Model/Skill/Bullet.cpp \
				   ../../Classes/Model/Skill/BulletBall.cpp \
				   ../../Classes/Model/Skill/BulletBallFactory.cpp \
				   ../../Classes/Model/Skill/BulletManager.cpp \
				   ../../Classes/Model/Skill/BulletNormal.cpp \
				   ../../Classes/Model/Skill/BulletNormalFactory.cpp \
				   \
				   ../../Classes/Model/Weapon/FishingNode.cpp \
				   \
				   ../../Classes/Tools/AnimationUtil.cpp \

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes \
					$(LOCAL_PATH)/../../cocos2d/extensions

LOCAL_WHOLE_STATIC_LIBRARIES := cocos2dx_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocosdenshion_static

# LOCAL_WHOLE_STATIC_LIBRARIES += box2d_static
# LOCAL_WHOLE_STATIC_LIBRARIES += cocosbuilder_static
# LOCAL_WHOLE_STATIC_LIBRARIES += spine_static
# LOCAL_WHOLE_STATIC_LIBRARIES += cocostudio_static
# LOCAL_WHOLE_STATIC_LIBRARIES += cocos_network_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocos_extension_static


include $(BUILD_SHARED_LIBRARY)

$(call import-module,.)
$(call import-module,audio/android)

# $(call import-module,Box2D)
# $(call import-module,editor-support/cocosbuilder)
# $(call import-module,editor-support/spine)
# $(call import-module,editor-support/cocostudio)
# $(call import-module,network)
$(call import-module,extensions)
