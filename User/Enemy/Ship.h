#pragma once
#include "DxLib.h"
#include "Vec2.h"
#include <memory>

class Ship {
public:
	Ship();
	~Ship();
	void Initialize();
	void Update();
	void Draw();
	Vec2 GetPos() { return pos; };
	bool isHit;
	bool isDead;
private:
	bool isLeft;
	Vec2 pos;
	int radius;
	unsigned int color;
	float speed;

};
