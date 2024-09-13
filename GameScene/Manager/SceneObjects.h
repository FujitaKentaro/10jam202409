
#pragma once
/**
 * @file SceneObject.h
 * @brief シーンオブジェクト所持クラス
 */
#include <map>
#include <string>

#include "Circle.h"
#include "Enemy.h"
#include "Flower.h"
#include "Particle/ParticleManager.h"

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
	void SetWindowSize(Vec2 winsize) { windowSize = winsize; }
	Vec2 GetWindowSize() {return windowSize; }
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
	Vec2 windowSize;

public: // オブジェクトの管理

	std::unique_ptr<EnemyManager> enemyManager;
	std::unique_ptr<Circle> circle;
	std::unique_ptr<Flower> flower;

public:
	int enemyGraph;
	int flowerGraph[4];
	int wallGraph;
	int tutiGraph;


private: // ライト用

};

