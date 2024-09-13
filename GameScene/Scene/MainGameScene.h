
#pragma once
/**
 * @file GAME2Scene.h
 * @brief ゲーム実行2ステージ目
 */
#include "IScene.h"
#include "SceneIntegrate.h"
#include "Player.h"

class MainGameScene :
	public IScene
{
public:
	MainGameScene();
	~MainGameScene() override;

	//void Cleate(SceneManager& manager) override;
	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize() override;

	/// <summary>
	/// 更新
	/// </summary>
	/// <param name="input">入力管理クラス</param>
	void Update() override;

	/// <summary>
	/// 描画
	/// </summary>
	void Draw() override;

private:
	Vec2 mousePos;

	int enemyPopTimer = 0;
	const int MAX_TIME = 1200;
	int timer;
	float timeRate;

	bool isGameStart = false;
	bool isGameEnd;

	//プレイヤー
	std::unique_ptr<Player> player;
};

