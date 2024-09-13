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
		StopMusic();
		_manager->SetSceneNum(SCE_GAME1);
		_objects->flower->Reset();
	}
}

void SelectScene::Draw() {
	//DrawFormatString(200, 60, GetColor(255, 255, 255),L"serect");
	DrawGraph(0, 0, _objects->info, false);
	DrawFormatString(250, 790, GetColor(255, 255, 255), "PRESS SPACE");
	
}

void SelectScene::SelectSceneNum() {

}
void SelectScene::MoveScene() {

}

void SelectScene::SpriteCollision()
{

}
