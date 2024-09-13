#include "Player.h"


void Player::Initialize()
{

	bulletPos = { (winSize.x / 2),((winSize.y)*2)/3 };
	bulletResetPos = bulletPos;
}

void Player::Update()
{
	int x, y;
	GetMousePoint(&x, &y);
	mousePos.x = (float)x;
	mousePos.y = (float)y;
	if (MouseHit() && (GetMouseInput() & MOUSE_INPUT_LEFT) != 0&& releaseMouse == false) {
		bulletPos = mousePos;
	}
	if (mousePushBefore == true && (GetMouseInput() & MOUSE_INPUT_LEFT) != 1 && releaseMouse == false) {
		bulletDir = bulletResetPos - bulletPos;
		float dirSpeed = bulletDir.length();
		bulletDir.normalize();
		bulletDir *= bulletSpeed + (dirSpeed/10);
		releaseMouse = true;
		if (bulletPos.x < (winSize.x / 2)) {
			mousePosLeft = true;
		}
		else if(bulletPos.x > (winSize.x / 2))
		{
			mousePosRight=true;
		}
		else
		{
			bulletPos = bulletResetPos;
			releaseMouse = false;
		}

		if(bulletPos.y< ((winSize.y) * 2) / 3)
		{
			mousePosUnder = true;
		}
		else if(bulletPos.y > ((winSize.y) * 2) / 3)
		{
			mousePosOver = true;
		}
		else
		{
			bulletPos = bulletResetPos;
			releaseMouse = false;
		}
		
	}
	if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) {
		mousePushBefore = true;
	}
	else
	{
		mousePushBefore = false;
	}
	BulletUpdate();
}

void Player::Draw()
{
	if (bulletResetPos.y < bulletPos.y) {
		DrawLineAA(bulletResetPos.x - 10, bulletResetPos.y, bulletPos.x, bulletPos.y, GetColor(255, 255, 255));
		DrawLineAA(bulletResetPos.x + 10, bulletResetPos.y, bulletPos.x, bulletPos.y, GetColor(255, 255, 255));
	}
	DrawCircle(bulletPos.x, bulletPos.y, bulletRadius, GetColor(255, 255, 255));
}

void Player::Reset()
{
	if (releaseMouse) {
		bulletPos = bulletResetPos;
		releaseMouse = false;
		bulletLimit = bulletLimitReset;
		mousePosUnder = false;
		mousePosOver = false;
		mousePosRight = false;
		mousePosLeft = false;
	}

}

bool Player::MouseHit()
{
	Vec2 VecLength = bulletPos - mousePos;
	float Length = VecLength.length();
	if (Length <= (bulletRadius + mouseRadius)*5) {
		return true;
	}
	else
	{
		return false;
	}
}

void Player::BulletUpdate()
{
	if (releaseMouse) {
		bulletPos += bulletDir;
		bulletLimit--;
	}
	if (mousePosLeft&& winSize.x < bulletPos.x) {
		Reset();
		releaseMouse = false;
	}
	if (mousePosRight&& 0 > bulletPos.x ) {
		Reset();
		releaseMouse = false;
	}
	if (mousePosUnder&& winSize.y < bulletPos.y) {
		Reset();
		releaseMouse = false;
	}
	if (mousePosOver&& 0 > bulletPos.y ) {
		Reset();
		releaseMouse = false;
	}
	/*if (winSize.x < bulletPos.x || 0 > bulletPos.x || winSize.y < bulletPos.y || 0 > bulletPos.y) {
		
	}*/
	if (bulletLimit < 0) {
		Reset();
		releaseMouse = false;

	}
}

Vec2 Player::BulletPos()
{
	return bulletPos;
}
