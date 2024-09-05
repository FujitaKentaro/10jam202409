#pragma once
#include "DxLib.h"
#include "Vec2.h"

class Circle{
public:
	Circle();
	~Circle();
	void Initialize(Vec2 position, int rad);
	void Update(bool isStart);
	void Draw();
	void Hit();
	int GetScore() { return score; };
	Vec2 GetPos() { return pos; };
	int GetRadius() { return radius; };
private:

	Vec2 pos;
	int radius;
	int score;

};