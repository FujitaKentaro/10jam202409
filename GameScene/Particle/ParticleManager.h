#pragma once
#include "Vec2.h"
#include <list>
#include <memory>
#include "DxLib.h"

class Particle
{
public:
	/// <summary>
	/// 作成
	/// </summary>
	/// <returns></returns>
	static Particle* Create(const Vec2& pos, const Vec2& velocity, float scale = 1.0f, unsigned int color = GetColor(255, 255, 255));

	/// <summary>
	/// 初期化
	/// </summary>
	/// <param name="pos_"></param>
	/// <param name="model_"></param>
	/// <param name="pipeline_"></param>
	void Init(const Vec2& pos, const Vec2& velocity, float scale, unsigned int color = GetColor(255, 255, 255));

	/// <summary>
	/// 更新
	/// </summary>
	/// <param name="viewPro"></param>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

	/// <summary>
	/// 死んだかゲッター
	/// </summary>
	/// <returns></returns>
	const bool GetIsDead() const
	{
		return isDead;
	}

private:
	// オブジェクト
	Vec2 pos_;
	Vec2 velocity_ = { 0,0 };
	float scale_ = 1.0f;
	unsigned int color_;

	// 生存時間
	uint32_t lifeTimer = 0;
	const uint32_t MAXLIFETIME = 30;

	float easeTimer = 0;
	const float MAXEASETIME = 20;

	// 終了かどうか
	bool isDead = false;
};

class ParticleManager
{
public:
	// インスタンス
	static ParticleManager* GetInstance();

	struct ParticlePreset
	{
		// 発生位置
		Vec2 pos_;
		// 広がり値
		Vec2 velocityMinMax = { -1.0,1.0 };
		// 一回で出す量
		size_t volume = 10;
		// オブジェクトスケール
		float scale = 1.0f;
		// オブジェクトカラー
		unsigned int color;
	};

public:

	/// <summary>
	/// 初期化
	/// </summary>
	void Init();

	/// <summary>
	/// 更新
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

	/// <summary>
	/// 爆発演出
	/// </summary>
	/// <param name="pos">発生位置</param>
	/// <param name="minMax">広がり値</param>
	/// <param name="volume">一回で出す量</param>
	/// <param name="scale">オブジェクトスケール</param>
	/// <param name="color">オブジェクトカラー</param>
	void SetAnyExp(const Vec2& pos, Vec2 velocityMinMax = { -1.0,1.0 }, size_t volume = 10, float scale = 1.0f, unsigned int color = GetColor(255, 255, 255));
	/// <param name="ParticlePreset">プリセット</param>
	void SetAnyExp(ParticlePreset preset);

private:
	std::list<std::unique_ptr<Particle>> Particles_;

private:
	ParticleManager() = default;
	~ParticleManager() = default;
	ParticleManager(const ParticleManager&) = default;
	const ParticleManager& operator=(const ParticleManager&) = delete;
};