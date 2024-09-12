#pragma once
#include "DxLib.h"
#include "Vec2.h"
#include <list>
#include <memory>

class Enemy {
public:
	Enemy();
	~Enemy();
	void Initialize();
	void Update(bool isStart);
	void Draw();
	Vec2 GetPos() { return pos; };
	int GetRadius() { return radius; };
	bool IsOverLimit() { return isOverLimiit; };
	bool isHit;
	bool isDead;
private:
	bool isfall;
	bool isOverLimiit;
	const int FALL_LIMIT = 650;
	Vec2 pos;
	int radius;
	unsigned int color;
	float speed;
	float accel;

};

class Flower;
class Player;
class EnemyManager {
private:
	std::list<std::unique_ptr<Enemy>> enemy;
public:
	void Initialize();
	void Update(bool isStart);
	void Draw();
	void AddEnemy();
	void AllClear();
	//void ColiderUpdate(Circle* circle);
	bool ColiderUpdate(Vec2 pos, float radius);
	bool OverLimit();
	void SetFlower(Flower* flower) { flower_ = flower; };
private:
	Flower* flower_ = nullptr;
};

