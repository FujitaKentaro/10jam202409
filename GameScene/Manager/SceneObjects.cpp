/**
 * @file SceneObject.cpp
 * @brief シーンオブジェクト所持クラス
 */
#include "SceneObjects.h"


SceneObjects::SceneObjects() {

}
SceneObjects::~SceneObjects() {

}

void SceneObjects::Initialize() {

	title = LoadGraph(L"Resources/PIC/title.png");
	tutiGraph = LoadGraph(L"Resources/PIC/tuti.png");
	enemyGraph = LoadGraph(L"Resources/PIC/enemy.png");
	wallGraph = LoadGraph(L"Resources/PIC/sky_2.png");
	flowerGraph[0] = LoadGraph(L"Resources/PIC/flower.png");
	flowerGraph[1] = LoadGraph(L"Resources/PIC/flower_red.png");
	flowerGraph[2] = LoadGraph(L"Resources/PIC/flower_pink.png");
	flowerGraph[3] = LoadGraph(L"Resources/PIC/flower_white.png");
	info = LoadGraph(L"Resources/PIC/info.png");


	circle = std::make_unique<Circle>();
	circle->Initialize(Vec2(600, 600), 20);

	enemyManager = std::make_unique<EnemyManager>();
	enemyManager->Initialize();
	enemyManager->SetGraphHandle(enemyGraph);

	flower = std::make_unique<Flower>();
	flower->Initialize();
	flower->SetHandle(flowerGraph);
}

void SceneObjects::UpdateImGui()
{

}

void SceneObjects::Reset()
{
	
}



void SceneObjects::UIUpdate()
{
	

}

void SceneObjects::UIDraw()
{
	
}

void SceneObjects::LoadLevels()
{
	

}

void SceneObjects::SetingLevel(LevelData* data)
{
	/*
	for (auto& objectData : data->JsonObjects) {

		if (objectData.fileName == "enemy") {
			std::unique_ptr<Enemy> newEnemy = std::make_unique<Enemy>();
			if (objectData.weapon == "ASSAULT") {
				newEnemy->SetWeaponNum(WP_ASSAULT);
			}if (objectData.weapon == "SHOTGUN") {
				newEnemy->SetWeaponNum(WP_SHOTGUN);
			}if (objectData.weapon == "BOMFIRE") {
				newEnemy->SetWeaponNum(WP_BOMFIRE);
			}
			newEnemy->SetModel(enemyMD.get());
			newEnemy->Initialize();
			//座標
			Vector3 pos;
			pos = objectData.translation;
			newEnemy->object_->transForm.position = pos;
			//回転
			Vector3 rot;
			rot = objectData.rotation;
			newEnemy->object_->transForm.rotation = rot;
			newEnemy->SetRestRotate(rot);
			//拡縮
			Vector3 sca;
			sca = objectData.scaling;
			newEnemy->object_->transForm.scale = sca;
			enemys.emplace_back(std::move(newEnemy));
		}
		else if (objectData.fileName == "boss") {
			std::unique_ptr<Boss> newBoss = std::make_unique<Boss>();
			if (objectData.weapon == "ASSAULT") {
				newBoss->SetWeaponNum(WP_ASSAULT);
			}if (objectData.weapon == "SHOTGUN") {
				newBoss->SetWeaponNum(WP_SHOTGUN);
			}if (objectData.weapon == "BOMFIRE") {
				newBoss->SetWeaponNum(WP_BOMFIRE);
			}
			newBoss->SetFBXModel(bossFbxM_.get());
			newBoss->Initialize();
			//座標
			Vector3 pos;
			pos = objectData.translation;
			newBoss->object_->transForm.position = pos;
			//回転
			Vector3 rot;
			rot = objectData.rotation;
			newBoss->object_->transForm.rotation = rot;
			newBoss->SetRestRotate(rot);
			//拡縮
			Vector3 sca;
			sca = objectData.scaling;
			newBoss->object_->transForm.scale = sca;
			boss.emplace_back(std::move(newBoss));
		}
		else if (objectData.fileName == "wall") {
			std::unique_ptr<Wall> newWall = std::make_unique<Wall>();
			newWall->Initialize(wallMD.get());
			//座標
			Vector3 pos;
			pos = objectData.translation;
			newWall->object_->transForm.position = pos;
			//回転
			Vector3 rot;
			rot = objectData.rotation;
			newWall->object_->transForm.rotation = rot;
			//拡縮
			Vector3 sca;
			sca = objectData.scaling;
			newWall->object_->transForm.scale = sca;
			newWall->object_->SetColor(Vector4(1.0f, 1.0f, 1.0f, 1.0f));
			newWall->object_->Update();
			newWall->CollideInitialize();
			walls.emplace_back(std::move(newWall));
		}
		else if (objectData.fileName == "player") {
			Vector3 position = objectData.translation;
			player->SetPos(position);
		}
	}
	*/
}
