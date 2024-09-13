/**
 * @file SelectScene.cpp
 * @brief
 */
#include "SelectScene.h"
#include "SceneManager.h"

SelectScene::SelectScene() {
}
SelectScene::~SelectScene() {


}

void SelectScene::Initialize() {

}

void SelectScene::Update() {
	if (CheckHitKey(KEY_INPUT_SPACE)) {
		_manager->SetSceneNum(SCE_GAME1);
		_objects->flower->Reset();
	}
}

void SelectScene::Draw() {
	DrawFormatString(200, 60, GetColor(255, 255, 255),L"serect");
	DrawFormatString(200, 90, GetColor(255, 255, 255), L"PRESS SPACE");
}

void SelectScene::SelectSceneNum() {

}
void SelectScene::MoveScene() {

}

void SelectScene::SpriteCollision()
{

}
