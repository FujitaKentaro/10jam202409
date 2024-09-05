#include "GameScene.h"

GameScene::GameScene()
{
}
GameScene::~GameScene()
{
}

void GameScene::Initialize()
{
	// シーン管理
	sceneObjects = std::make_unique<SceneObjects>();
	sceneObjects->Initialize();
	IScene::SetSceneObjects(sceneObjects.get());
	sceneFactory = new SceneFactory();
	sceneManager = new SceneManager(sceneObjects.get());
	sceneManager->SetFactory(sceneFactory);
	IScene::SetSceneManager(sceneManager);
	sceneManager->Initialize();
	sceneManager->SceneInitialize();
}

void GameScene::Update()
{

	sceneManager->ChangeScene();

	sceneObjects->UpdateImGui();

	sceneManager->SceneUpdate();

	
}

void GameScene::Draw()
{
	sceneManager->SceneDraw();

}

void GameScene::DrawUI()
{

}

void GameScene::AllClear()
{
	//enemyManager->AllClear();
}

