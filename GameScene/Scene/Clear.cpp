/**
 * @file Clear.cpp
 * @brief
 */
#include "SceneIntegrate.h"
#include "SceneManager.h"

Clear::Clear() {
}
Clear::~Clear() {

}

void Clear::Initialize() {

}

void Clear::Update() {
	if (CheckHitKey(KEY_INPUT_SPACE)) {
		_manager->SetSceneNum(SCE_TITLE);
	}
}

void Clear::Draw() {
	DrawFormatString(200, 60, GetColor(255, 255, 255), "clear");
	DrawFormatString(200, 90, GetColor(255, 255, 255), "PRESS SPACE TO TITLE");
	DrawFormatString(30, 60, GetColor(255, 255, 255), "SCORE : %d", _objects->player->GetScore());
}