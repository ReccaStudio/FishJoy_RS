#pragma once

enum WEAPON_STATUS
{
	k_Ready = 0,
	k_Colding,
	k_Money_Less,
	k_Shooting,
	k_Reloading
};

//�������ӵ������Ͳ���ͳһ�������ӿ�������ͬ��ǹ�������ض������л���ʹ�����ⵯҩ
//�������������Cannon����һ��
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