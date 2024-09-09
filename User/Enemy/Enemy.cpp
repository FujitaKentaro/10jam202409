#include "Enemy.h"
#include <random>
#include "Circle.h"

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

void Enemy::Initialize()
{
	pos.x = RandomFloat(0,200,1080);
	pos.y = 20;
	radius = 0;
	accel = 0;
	speed = 5;
	isDead = false;
	isfall = false;
	isHit = false;
}

void Enemy::Update(bool isStart)
{
	float posres;
	posres = pos.y;
	if (isStart) {}

	if (isfall) {
		accel += 0.005f;
		posres += speed * accel;
	}
	else {
		radius++;
	}

	if (radius >= 25) {
		isfall = true;
	}
	if (pos.y >= 650) {
		isDead = true;
	}
	if (isHit) {
		color = GetColor(100, 0, 0);
		accel -= 0.25;
		posres += speed * accel;
		radius--;
	}
	else {
		color = GetColor(100, 200, 100);
	}
	 pos.y = posres;
}


void Enemy::Draw()
{
	DrawCircle((int)pos.x, (int)pos.y, radius, color, true);
}

void EnemyManager::Initialize()
{

}

void EnemyManager::Update(bool isStart)
{
	//デスフラグの立った弾を削除
	enemy.remove_if([](std::unique_ptr<Enemy>& enemys) {
		return enemys->isDead;
		});
	//弾の更新
	for (std::unique_ptr<Enemy>& enemys : enemy)
	{
		enemys->Update(isStart);
	}
}

void EnemyManager::Draw()
{
	for (std::unique_ptr<Enemy>& enemys : enemy)
	{
		enemys->Draw();
	}
}

void EnemyManager::AddEnemy()
{
	std::unique_ptr<Enemy> newEnemy;
	newEnemy = std::make_unique<Enemy>();
	newEnemy->Initialize();
	enemy.push_back(std::move(newEnemy));
}

void EnemyManager::AllClear()
{
	enemy.clear();
}

void EnemyManager::ColiderUpdate(Circle* circle)
{
	for (std::unique_ptr<Enemy>& enemys : enemy)
	{
		enemys->Draw();
		float dist = sqrtf(float(
			pow(enemys->GetPos().x - circle->GetPos().x, 2) +
			pow(enemys->GetPos().y - circle->GetPos().y, 2)
			));

		if (dist < circle->GetRadius() + enemys->GetRadius() && enemys->isHit == false)
		{
			circle->Hit();
			enemys->isHit = true;
		}
	}
}
