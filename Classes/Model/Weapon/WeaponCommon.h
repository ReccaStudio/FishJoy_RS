#pragma once

enum WEAPON_STATUS
{
	k_Ready = 0,
	k_Colding,
	k_Money_Less,
	k_Shooting,
	k_Reloading
};

//武器和子弹的类型不必统一，这样子可以允许不同的枪可以做特定场景切换来使用特殊弹药
//武器和武器外观Cannon必须一致
typedef enum WEAPON_TYPE
{
	k_Bullet_1 = 0,
	k_Bullet_2,
	k_Bullet_3,
	k_Ball_1,
	k_Invalid
};


enum SWITCH_OPERATOR
{
	k_Add = 0,
	k_Minus
};