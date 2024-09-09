#pragma once
#include "DxLib.h"
#include <memory>
#include "Vec2.h"
#include "Circle.h"
#include "Enemy.h"
#include "SceneIntegrate.h"
#include "SceneFactory.h"


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

private:
	// mane-ja-
	SceneManager* sceneManager = nullptr;
	SceneFactory* sceneFactory = nullptr;

	std::unique_ptr<SceneObjects> sceneObjects;

private:

	

};

