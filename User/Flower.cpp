#include "Flower.h"
#include "DxLib.h"

Flower::Flower()
{
}

Flower::~Flower()
{
}

void Flower::Initialize()
{
	life = LIFE_MAX;
	score = 0;
}

void Flower::Update()
{

}

void Flower::Draw()
{
	DrawFormatString(30, 60, GetColor(255, 255, 255), L"LIFE : %d", life);
	DrawFormatString(30, 90, GetColor(255, 255, 255), L"SCORE : %d", score);
	int addX = 120;
	int addPosX = 0;
	for (int i = 0; i < life; i++) {
		//DrawCircle((640 / 3) + addPosX, 700, 20, GetColor(255, 0, 128));

		DrawExtendGraph((640 / 5) + addPosX, 700,(640 / 5) + addPosX+(2*32), 700+(2*64), graphHandle[i], true);
		addPosX += addX;
	}
}

void Flower::Reset()
{
	life = LIFE_MAX;
	score = 0;
}

void Flower::AddScore(bool enemyColFX)
{
	if (enemyColFX == true) {
		score += 100;
	}
}

void Flower::HerasuLife(bool enemyLimitFX)
{
	if (enemyLimitFX) {
		life -= 1;
	}
}
