#include "Ship.h"

Ship::Ship()
{

}

Ship::~Ship()
{

}

void Ship::Initialize()
{
	pos.x = RandomFloat(0, 200, 1080);
	pos.y = 20;
	radius = 10;
	speed = 5;
	isDead = false;
	isHit = false;
	isLeft = false;
}

void Ship::Update()
{
	float posresult;
	posresult = pos.y;

	if (isHit) {
		color = GetColor(100, 0, 0);
		posresult += speed;
		radius--;
	}
	else {
		color = GetColor(100, 200, 100);
	}

	if (radius <= 0) {
		isDead = true;
	}
	pos.y = posresult;

}

void Ship::Draw()
{
	DrawBox((int)pos.x - (radius+10), (int)pos.y - (radius), (int)pos.x + (radius + 10), (int)pos.y + (radius), color, true);
}
