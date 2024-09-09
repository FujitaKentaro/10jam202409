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
	if (scoretimer >= SCORE_MAX_TIME) {
		scoretimer = SCORE_MAX_TIME;
	}
	else {
		scoretimer++;
	}

	previewScore = lerpFloat(0, _objects->player->GetScore(), (float)scoretimer/(float)SCORE_MAX_TIME);
}

void Clear::Draw() {
	DrawFormatString(200, 60, GetColor(255, 255, 255), "clear");
	DrawFormatString(200, 90, GetColor(255, 255, 255), "PRESS SPACE TO TITLE");
	DrawFormatString((_objects->GetWindowSize().x/2)-100, _objects->GetWindowSize().y/2, GetColor(255, 255, 255), "SCORE : %d", previewScore);
}