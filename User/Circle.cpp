#include "Circle.h"

Circle::Circle()
{
}

Circle::~Circle()
{

}

void Circle::Initialize(Vec2 position, int rad)
{
	pos = position, radius = rad;
	score = 0;
}

void Circle::Update(bool isStart)
{
	if (isStart) {

		if (CheckHitKey(KEY_INPUT_D) && pos.x < 1080) {
			pos.x += 10;
		}
		if (CheckHitKey(KEY_INPUT_A) && pos.x > 200) {
			pos.x -= 10;
		}
	}
	else {

	}
}

void Circle::Draw()
{
	DrawCircle(pos.x, pos.y, 20, GetColor(100, 200, 100), true);
}

void Circle::Hit()
{
	score += 100;
}
