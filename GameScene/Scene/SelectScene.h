
#pragma once
/**
 * @file SelectScene.h
 * @brief
 */
#include "IScene.h"
#include "SceneIntegrate.h"

class SelectScene :
    public IScene
{
public:
	SelectScene();
	~SelectScene() override;

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

	void SelectSceneNum();
	void MoveScene();
	void SpriteCollision();

private:

public:

};

