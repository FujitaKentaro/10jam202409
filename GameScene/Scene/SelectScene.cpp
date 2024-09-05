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
	}
}

void SelectScene::Draw() {
	DrawFormatString(200, 60, GetColor(255, 255, 255),"serect");
	DrawFormatString(200, 90, GetColor(255, 255, 255), "PRESS SPACE");
}

void SelectScene::SelectSceneNum() {

}
void SelectScene::MoveScene() {

}

void SelectScene::SpriteCollision()
{

}
