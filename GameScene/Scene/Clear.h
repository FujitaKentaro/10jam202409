
#pragma once
/**
 * @file Clear.h
 * @brief
 */
#include "IScene.h"
#include "SceneIntegrate.h"

class Clear :
	public IScene
{
public:
	Clear();
	~Clear() override;

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

	const int SCORE_MAX_TIME = 100;
	int scoretimer = 0;
	int previewScore;

	bool isExp = false;

public:
	//代入演算子削除
	Clear& operator=(const Clear&) = delete;

	//コピーコンストラクタ削除
	Clear(const Clear&) = delete;
};