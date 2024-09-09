#pragma once
#include "DxLib.h"
#include <memory>
#include "Vec2.h"
#include "Circle.h"
#include "Enemy.h"
#include "SceneIntegrate.h"
#include "SceneFactory.h"
#include "Particle/ParticleManager.h"

class GameScene
{
public:
	GameScene();
	~GameScene();
	void Initialize();
	void Update();
	void Draw();
	void DrawUI();
	void AllClear();
	void SetWindowSize(const Vec2 windowSize) { GameScene::WINDOW_SIZE = windowSize; }
public:
	Vec2 WINDOW_SIZE;
private:
	// mane-ja-
	SceneManager* sceneManager = nullptr;
	SceneFactory* sceneFactory = nullptr;
	ParticleManager* particleManager = nullptr;

	std::unique_ptr<SceneObjects> sceneObjects;

private:



};

