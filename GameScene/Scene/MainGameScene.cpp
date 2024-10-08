/**
 * @file MainGameScene.cpp
 * @brief ゲーム実行2ステージ目
 */
#include "MainGameScene.h"
#include "SceneManager.h"

MainGameScene::MainGameScene() {
}

MainGameScene::~MainGameScene() {

}

void MainGameScene::Initialize() {
	StopMusic();
	
	player= std::make_unique<Player>();
	player->WinSize(_objects->GetWindowSize());
	player->Initialize();

	timer = 0;
	isGameStart = false;
	isGameEnd = false;
	mousePos.x = 0;
	mousePos.y = 0;

}

void MainGameScene::Update() {
	int x, y;
	GetMousePoint(&x, &y);
	mousePos.x = (float)x;
	mousePos.y = (float)y;
	if (isGameStart == false) {
		if ((GetMouseInput() & MOUSE_INPUT_RIGHT) != 0) {
			PlayMusic("Resources/mp3/game02.mp3", DX_PLAYTYPE_LOOP);
			isGameStart = true;
			_objects->circle->Initialize(Vec2(600, 600), 20);
		}
	}
	if (isGameStart == true) {
		timeRate = (float)timer / MAX_TIME;

		if (timer >= MAX_TIME) {
			timer = 0;
			isGameEnd = true;
			isGameStart = false;
			_objects->enemyManager->AllClear();
		}
		else {
			timer++;
		}
		enemyPopTimer++;
		if (enemyPopTimer >= 50) {
			enemyPopTimer = 0;
			_objects->enemyManager->AddEnemy();
		}
		//_objects->circle->Update(isGameStart);
		//_objects->enemyManager->ColiderUpdate(_objects->circle.get());
		_objects->enemyManager->Update(isGameStart);
		_objects->flower->AddScore(_objects->enemyManager->ColiderUpdate(player->BulletPos(), 15));
		_objects->flower->HerasuLife(_objects->enemyManager->OverLimit());
	}
	if (isGameStart == false && isGameEnd == true) {
		_manager->SetSceneNum(SCE_CLEAR);
	}
	if (_objects->flower->Life2Score().x <=0) {
		_manager->SetSceneNum(SCE_TITLE);
	}
	player->Update();
}

void MainGameScene::Draw() {

	DrawCircle(mousePos.x, mousePos.y, 5, GetColor(255, 0, 255), true);

	DrawCircle(lerpFloat(80, 600, timeRate), 10, 10, GetColor(255, 0, 255), true);

	//_objects->circle->Draw();
	DrawGraph(0, 720, _objects->tutiGraph, true);
	_objects->flower->Draw();
	_objects->enemyManager->Draw();

	if (isGameStart == false) {
		DrawFormatString(200, 500, GetColor(255, 255, 255), "CLICK MOUSE RIGHT START");
	}
	if (isGameStart == true && isGameEnd == false) {
		//DrawFormatString(30, 30, GetColor(255, 255, 255), L"PUSH  A D  MOVE");
	}
	player->Draw();

}