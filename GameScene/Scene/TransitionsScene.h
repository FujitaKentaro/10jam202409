
#pragma once
/**
 * @file TransitionsScene.h
 * @brief
 */
#include "IScene.h"
#include "SceneIntegrate.h"

/// <summary>
/// シーン切り替え演出クラス
/// </summary>
class TransitionsScene :
    public IScene
{
public:
	TransitionsScene();
	~TransitionsScene() override;

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
	//代入演算子削除
	TransitionsScene& operator=(const TransitionsScene&) = delete;

	//コピーコンストラクタ削除
	TransitionsScene(const TransitionsScene&) = delete;
};

