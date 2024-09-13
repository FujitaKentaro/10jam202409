#pragma once
#include "Vec2.h"


class Flower
{
public:
	Flower();
	~Flower();
	void Initialize();
	void Update();
	void Draw();
	void Reset();
	void AddScore(bool enemyColFX);
	void HerasuLife(bool enemyLimitFX);
	// X-> life ,Y-> score
	Vec2 Life2Score() { return Vec2(life, score); };
	void SetHandle(int handle[]) {
		for (int i = 0; i < 4; i++) {
			graphHandle[i] = handle[i];
		}
	};
private:
	const int LIFE_MAX = 4;
	int life;
	int score;
	int graphHandle[4];
};

