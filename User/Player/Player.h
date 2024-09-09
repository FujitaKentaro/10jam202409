#pragma once
#include "Vec2.h"
#include <DxLib.h>
class Player
{
public:
	void Initialize();

	void Update();

	void Draw();

	void Reset();

	bool MouseHit();

	void BulletUpdate();

	Vec2 BulletPos();

private:
	//弾の変数
	Vec2 bulletPos = { 0,0 };
	Vec2 bulletResetPos = { 0,0 };
	//弾の方向

	Vec2 bulletDir;
	int bulletRadius = 5;
	bool releaseMouse = false;

	//スピード(仮)
	float bulletSpeed = 3.0f;
	
	//マウスの変数
	Vec2 mousePos = { 0,0 };
	int mouseRadius = 3;
	Vec2 mousePushPos = { 0,0 };
	Vec2 mouseReleasePos = { 0,0 };
	//前フレームマウス入力保持
	bool mousePushBefore = false;
	//画面サイズ
	Vec2 winSize = { 1280,720 };

};

