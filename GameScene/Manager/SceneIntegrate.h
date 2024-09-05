
#pragma once
/**
 * @file SceneIntegrate
 * @brief シーンを選択しやすいようにシーンの一括インクルード
 */

// 要らないなら消しておk
#include "DxLib.h"

#include "TitleScene.h"
#include "PauseScene.h"
#include "SelectScene.h"
#include "Clear.h"

#include "TransitionsScene.h"
#include "MainGameScene.h"

// チェンジシーン用のenum
enum _SCENE_ {
	SCE_TITLE = 1,
	SCE_CLEAR ,
	SCE_PAUSE ,
	SCE_SELECT,
	SCE_TRANS ,
	SCE_TUTO  ,
	SCE_GAME1 ,
	SCE_GAME2 ,
	SCE_GAME3 ,
};
enum _TUTOSCENE_ {
	TUTO_PAUSE,
	TUTO_1 ,
	TUTO_2 ,
	TUTO_3 ,
	TUTO_4 ,
	TUTO_5 ,
	TUTO_6 ,
	TUTO_7 ,
	TUTO_8 ,
};

enum LEVELS
{
	LV_TITLE,
	LV_TUTRIAL,
	LV_STAGE1,
	LV_STAGE2,
	LV_TUTRIAL_1,
	LV_TUTRIAL_2,
	LV_TUTRIAL_3,
	LV_TUTRIAL_4,
};