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
	StopMusic();
	PlayMusic("Resources/mp3/result01.mp3", DX_PLAYTYPE_LOOP);
}

void Clear::Update() {

	if ((GetMouseInput() & MOUSE_INPUT_RIGHT) != 0) {
		_manager->SetSceneNum(SCE_TITLE);

	}
	if (scoretimer >= SCORE_MAX_TIME) {
		scoretimer = SCORE_MAX_TIME;
	}
	else {
		scoretimer++;
	}

	previewScore = lerpFloat(0, _objects->flower->Life2Score().y, (float)scoretimer / (float)SCORE_MAX_TIME);

	if (isExp == false) {
		isExp = true;
		ParticleManager::GetInstance()->SetAnyExp(
			Vec2(_objects->GetWindowSize().x / 2, _objects->GetWindowSize().y / 2),Vec2(-10, 10),
			_objects->flower->Life2Score().y, 100, 10,
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

	DrawFormatString(250, 300, GetColor(255, 255, 255), "clear");
	DrawFormatString(200, 600, GetColor(255, 255, 255), "CLICK MOUSE RIGHT TO TITLE");
	DrawFormatString((_objects->GetWindowSize().x / 2) - 100, _objects->GetWindowSize().y / 2, GetColor(255, 255, 255), "SCORE : %d", previewScore);
}