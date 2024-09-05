
#pragma once
/**
 * @file SceneObject.h
 * @brief シーンオブジェクト所持クラス
 */
#include <map>
#include <string>

#include "Circle.h"
#include "Enemy.h"

typedef struct Shake {
	uint32_t isShake;
	uint32_t count;
	uint32_t maxSwing;
	uint32_t quantity;
	uint32_t randX;
	uint32_t randZ;
}Shake;

// ゲーム使用のオブジェクト一括宣言クラス
class SceneObjects
{
private:
	
public:
	SceneObjects();
	~SceneObjects();


	void Initialize();
	void Reset();
	void UpdateImGui();

public: // 演出用

	void BannerDraw();
	bool Banner(uint32_t isStart = 0);
	void ShakeRand(Shake& w);

	void SlowEffect(bool isSlow);
	void SlowReset();
	void SlowEffectDraw();

private: // 演出用
	
public:
	
public: // UI用
	void UIUpdate();
	void UIDraw();

	

public:
	class LevelData;
	void LoadLevels();
	void SetingLevel(LevelData* data);

private: // UI用
	

public: // オブジェクトの管理

	std::unique_ptr<EnemyManager> enemyManager;
	std::unique_ptr<Circle> player;

private: // ライト用
	
};

