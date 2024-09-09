/**
 * @file PauseScene.cpp
 * @brief
 */
#include "PauseScene.h"
#include "SceneManager.h"
#include "SceneIntegrate.h"

PauseScene::PauseScene() {
}
PauseScene::~PauseScene() {


}

void PauseScene::Initialize() {

}

void PauseScene::Update() {

}

void PauseScene::Draw() {


	//ここより下にポーズシーン用の描画処理

	DrawFormatString(200, 60, GetColor(255, 255, 255), L"pause");
}