#pragma once
#include "DxLib.h"
#include "Vec2.h"
#include <list>
#include <memory>

class Circle;

class Enemy {
public:
	Enemy();
	~Enemy();
	void Initialize();
	void Update(bool isStart);
	void Draw();
	Vec2 GetPos() { return pos; };
	int GetRadius() { return radius; };
	bool isHit;
	bool isDead;
private:
	bool isfall;
	Vec2 pos;
	int radius;
	unsigned int color;
	float speed;
	float accel;

};

class EnemyManager {
private:
	std::list<std::unique_ptr<Enemy>> enemy;
public:
	void Initialize();
	void Update(bool isStart);
	void Draw();
	void AddEnemy();
	void AllClear();
	void ColiderUpdate(Circle* circle);
};

