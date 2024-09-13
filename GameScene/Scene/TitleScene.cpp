/**
 * @file TitleScene.cpp
 * @brief
 */
#include "SceneIntegrate.h"

TitleScene::TitleScene() {
}
TitleScene::~TitleScene() {

}

void TitleScene::Initialize() {
	StopMusic();
	PlayMusic(L"Resources/mp3/title03.mp3", DX_PLAYTYPE_LOOP);
}

void TitleScene::Update() {
	
	if ((GetMouseInput() & MOUSE_INPUT_RIGHT) != 0) {
		_objects->enemyManager->AllClear();
		_manager->SetSceneNum(SCE_SELECT);
	}
}

void TitleScene::Draw() {
	DrawFormatString(200, 60, GetColor(255, 255, 255), L"TITLE");
	DrawFormatString(200, 90, GetColor(255, 255, 255), L"CLICK MOUSE RIGHT");
}



