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
	PlayMusic("Resources/mp3/title03.mp3", DX_PLAYTYPE_LOOP);
}

void TitleScene::Update() {

	if ((GetMouseInput() & MOUSE_INPUT_RIGHT) != 0) {
		_objects->enemyManager->AllClear();
		_manager->SetSceneNum(SCE_SELECT);
	}
}

void TitleScene::Draw() {
	//DrawFormatString(200, 60, GetColor(255, 255, 255), L"TITLE");
	DrawFormatString(250, 500, GetColor(255, 255, 255), "CLICK MOUSE RIGHT");

	DrawExtendGraph(50 + (0), 200 +(0), 50 + (719 * 0.8), 200 +(232*0.8), _objects->title, true);
}



