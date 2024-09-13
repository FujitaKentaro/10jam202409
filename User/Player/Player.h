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

	void WinSize(Vec2 win) { winSize = win; }

private:
	//弾の変数
	Vec2 bulletPos = { 0,0 };
	Vec2 bulletResetPos = { 0,0 };
	//弾の方向
	Vec2 bulletDir;
	int bulletRadius = 10;
	bool releaseMouse = false;
	//弾の寿命
	int bulletLimit = 40;
	int bulletLimitReset = 40;
	//重力
	float gravity = 9.8f;

	//スピード(仮)
	float bulletSpeed = 3.0f;
	
	//マウスの変数
	Vec2 mousePos = { 0,0 };
	int mouseRadius = 10;
	Vec2 mousePushPos = { 0,0 };
	Vec2 mouseReleasePos = { 0,0 };
	//前フレームマウス入力保持
	bool mousePushBefore = false;
	//画面サイズ
	Vec2 winSize = { 1280,720 };

	//マウスの離した位置
	bool mousePosUnder = false;
	bool mousePosOver = false;
	bool mousePosRight = false;
	bool mousePosLeft = false;
};

