#include "Enemy.h"
#include <random>
#include "Circle.h"
#include "Player.h"
#include "Flower.h"

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

void Enemy::Initialize()
{
	pos.x = RandomFloat(0, 50, 600);
	pos.y = 20;
	radius = 0;
	accel = 0;
	speed = 5;
	isDead = false;
	isfall = false;
	isHit = false;
	isOverLimiit = false;
}

void Enemy::Update(bool isStart)
{
	float posresult;
	posresult = pos.y;
	if (isStart) {}

	if (isfall) {
		accel += 0.005f;
		posresult += speed * accel;
	}
	else {
		radius++;
	}

	if (radius >= 25) {
		isfall = true;
	}
	if (isHit) {
		color = GetColor(100, 0, 0);
		accel -= 0.25;
		posresult += speed * accel;
		radius--;
	}
	else {
		color = GetColor(100, 200, 100);
	}
	if (pos.y >= FALL_LIMIT) {
		isOverLimiit = true;
	}
	if (isOverLimiit) {
		radius--;
	}
	if (radius <= 0) {
		isDead = true;
	}
	pos.y = posresult;
}


void Enemy::Draw(int graphHandle)
{
	//DrawCircle((int)pos.x, (int)pos.y, radius, color, true);
	DrawGraph((int)pos.x - radius, (int)pos.y - radius, graphHandle, true);
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
		enemys->Draw(eneGraph);
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

//void EnemyManager::ColiderUpdate(Circle* circle)
//{
//	for (std::unique_ptr<Enemy>& enemys : enemy)
//	{
//		enemys->Draw();
//		float dist = sqrtf(float(
//			pow(enemys->GetPos().x - circle->GetPos().x, 2) +
//			pow(enemys->GetPos().y - circle->GetPos().y, 2)
//			));
//
//		if (dist < circle->GetRadius() + enemys->GetRadius() && enemys->isHit == false)
//		{
//			circle->Hit();
//			enemys->isHit = true;
//		}
//	}
//}

bool EnemyManager::ColiderUpdate(Vec2 pos, float radius)
{
	for (std::unique_ptr<Enemy>& enemys : enemy)
	{
		float dist = sqrtf(float(
			pow(enemys->GetPos().x - pos.x, 2) +
			pow(enemys->GetPos().y - pos.y, 2)
			));

		if (dist < radius + enemys->GetRadius() && enemys->isHit == false)
		{
			enemys->isHit = true;
			return true;
		}
	}
	return false;
}

bool EnemyManager::OverLimit()
{
	for (std::unique_ptr<Enemy>& enemys : enemy)
	{
		if (enemys->IsOverLimit() == true && enemys->isDead == false) {
			enemys->isDead = true;
			return true;
		}
	}
	return false;
}
