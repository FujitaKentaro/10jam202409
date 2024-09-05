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
	pos.x = RandomFloat();
	pos.y = 20, radius = 30;
	accel = 0;
	speed = 2;
	isDead = false;
}

void Enemy::Update(bool isStart)
{
	if (isStart) {
		accel += 0.1f;

		pos.y += speed + accel;
	}
	else {

	}
	if (pos.y >= 700) {
		isDead = true;
	}
}

void Enemy::Draw()
{
	DrawCircle(pos.x, pos.y, 20, GetColor(100, 200, 100), true);
}

float Enemy::RandomFloat() {
	//乱数生成装置(メルセンヌ・ツイスタ)
	std::random_device seed_gen;
	std::mt19937_64 engine(seed_gen());

	//乱数
	std::uniform_real_distribution<float>dist(200, 1080);
	float result;
	result = dist(engine);

	return result;
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

		if (dist < circle->GetRadius() + enemys->GetRadius())
		{
			circle->Hit();
			enemys->isDead = true;
		}
	}
}
