#include "Player.h"   void Player::Initialize() { 	bulletPos = (winSize / 2); 	bulletResetPos = bulletPos; }  void Player::Update() { 	int x, y; 	GetMousePoint(&x, &y); 	mousePos.x = (float)x; 	mousePos.y = (float)y; 	if (MouseHit() && (GetMouseInput() & MOUSE_INPUT_LEFT) != 0) { 		bulletPos = mousePos; 	} 	if (mousePushBefore == true && (GetMouseInput() & MOUSE_INPUT_LEFT) != 1) { 		bulletDir = bulletResetPos -bulletPos; 		bulletDir.normalize(); 		bulletDir *= bulletSpeed; 		releaseMouse = true; 	} 	if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) { 		mousePushBefore = true; 	} 	else 	{ 		mousePushBefore = false; 	} 	BulletUpdate(); }  void Player::Draw() { 	DrawCircle(bulletPos.x, bulletPos.y, bulletRadius, GetColor(255, 255, 255)); }  void Player::Reset() { 	bulletPos = bulletResetPos; }  bool Player::MouseHit() { 	Vec2 VecLength = bulletPos - mousePos; 	float Length = VecLength.length(); 	if (Length >= bulletRadius + mouseRadius) { 		return true; 	} 	else 	{ 		return false; 	} }  void Player::BulletUpdate() { 	if (releaseMouse) { 		bulletPos += bulletDir; 	} 	if (winSize.x < bulletPos.x || 0 > bulletPos.x || winSize.y < bulletPos.y || 0 > bulletPos.y) { 		Reset(); 		releaseMouse = false; 	} 	 }  Vec2 Player::BulletPos() { 	return bulletPos; } 