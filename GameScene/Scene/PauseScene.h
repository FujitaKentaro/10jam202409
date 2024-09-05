
#pragma once
/**
 * @file PauseScene.h
 * @brief
 */
#include "IScene.h"

class PauseScene :
    public IScene
{
public:
	PauseScene();
	~PauseScene() override;

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

public:


};

