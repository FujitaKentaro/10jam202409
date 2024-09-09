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

	previewScore = lerpFloat(0, _objects->player->GetScore(), (float)scoretimer / (float)SCORE_MAX_TIME);

	if (isExp == false) {
		isExp = true;
		ParticleManager::GetInstance()->SetAnyExp(
			Vec2(_objects->GetWindowSize().x / 2, _objects->GetWindowSize().y / 2),Vec2(-10, 10),
			_objects->player->GetScore(), 100, 10,
			GetColor(
				(int)RandomFloat(128, 0, 128),
				(int)RandomFloat(128, 0, 128),
				(int)RandomFloat(128, 0, 128))
		);
	}
	else {

	}
}

void Clear::Draw() {
	ParticleManager::GetInstance()->Draw();

	DrawFormatString(200, 60, GetColor(255, 255, 255), L"clear");
	DrawFormatString(200, 90, GetColor(255, 255, 255), L"PRESS SPACE TO TITLE");
	DrawFormatString((_objects->GetWindowSize().x / 2) - 100, _objects->GetWindowSize().y / 2, GetColor(255, 255, 255), L"SCORE : %d", previewScore);
}