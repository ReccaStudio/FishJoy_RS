//
//  GameConfig.h
//  paydemo
//
//  Created by 王敬哲 on 14-10-30.
//  share data betweeen different scenes
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//

#ifndef paydemo_GameConfig_h
#define paydemo_GameConfig_h

#include "cocos2d.h"
#include <string>


namespace GameConfig
{
	enum SceneIndex
    {
        LOGO_SCENE = 0,
        LOGIN_SCENE,
		CHOOSE_TABELVIEW,
        LITTLE_RUN_SCENE,
		PAY_DEMO_SCENE,
		FISHING_JOY_SCENE
		
    };

	const std::string SceneNames[6] = {
		"LOGO_SCENE",
        "LOGIN_SCENE",
		"CHOOSE_TABELVIEW",
        "LITTLE_RUN_SCENE",
		"PAY_DEMO_SCENE",
		"FISHING_JOY_SCENE"
	};


const std::string USER_DATA = "static_data.plist";  
const std::string GOLD = "default_gold";
const std::string SOUND_VALUME = "sound_value";
const std::string MUSIC_VALUME = "music_value";
const std::string IS_BEGINNER = "is_beginner";
const std::string SPRITE_FRAME_LIST = "fishingjoy_resource.plist";
const std::string FISH_FRAME_COUNT = "fish_frame_count";
const std::string FISH_ANIMATION = "fish_animation";
const std::string FISH_FRAME_NAME_FORMAT = "fish_frame_name_format";
const std::string FISH_FRAME_DELAY = "fish_frame_delay";
const std::string GAME_BACKGROUND_FILENAME = "background";


const std::string BULLET_1 = "bullet";
const std::string BULLET_2 = "bullet";
const std::string BULLET_3 = "bullet";

const std::string FISHING_NET_1 = "fishing_net";
const std::string CANNON_LEVEL_NAME = "cannon_level_name_format";
const std::string BUTTON_SUB = "button_sub";
const std::string BUTTON_ADD = "button_add";
const std::string PAUSE_NORMAL = "pause_normal";
const std::string PAUSE_SELECT = "pause_selected";
const std::string BULLET_SPEED_NORMAL = "bullet_speed_normal";
const std::string FISH_PROBABILITY = "fish_percentage_format";
const std::string WEAPON_PROBABILITY = "weapon_percentage_format";





class RealseCache
{
public:
	RealseCache();
	~RealseCache();

	static void releaseSomeCache();

private:

};





}//ns_game_config


#endif
