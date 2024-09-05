
#pragma once
/**
 * @file TitleScene.h
 * @brief
 */
#include "IScene.h"
#include "SceneIntegrate.h"

class TitleScene :public IScene
{
public:

	TitleScene();
	~TitleScene() override;

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
	//代入演算子削除
	TitleScene& operator=(const TitleScene&) = delete;
	//コピーコンストラクタ削除
	TitleScene(const TitleScene&) = delete;

	
public:

private://リソース
	
};