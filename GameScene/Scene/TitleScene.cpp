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

}

void TitleScene::Update() {
	if (CheckHitKey(KEY_INPUT_RETURN)) {
		_manager->SetSceneNum(SCE_SELECT);
	}
}

void TitleScene::Draw() {
	DrawFormatString(200, 60, GetColor(255, 255, 255), L"TITLE");
	DrawFormatString(200, 90, GetColor(255, 255, 255), L"PRESS ENTER");
}



