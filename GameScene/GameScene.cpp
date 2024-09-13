#include "GameScene.h"

GameScene::GameScene()
{
}
GameScene::~GameScene()
{
}

void GameScene::Initialize()
{
	particleManager = ParticleManager::GetInstance();
	particleManager->Init();

	// シーン管理
	sceneObjects = std::make_unique<SceneObjects>();
	sceneObjects->SetWindowSize(WINDOW_SIZE);
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

	particleManager->Update();

	sceneManager->SceneUpdate();
}

void GameScene::Draw()
{
	DrawGraph(0, 0, sceneObjects->wallGraph, false);

	sceneManager->SceneDraw();

}

void GameScene::DrawUI()
{

}

void GameScene::AllClear()
{
	delete sceneFactory;
	delete sceneManager;
}

