#pragma once
#include "Utilities.h"

struct Bullet
{
	Vector2 pos = {};
	bool isActive;
};

Bullet InitBullet();
void SetBullet(Bullet& bullet, Vector2 spawnPos);
void BulletMovement(Bullet& bullet);
bool CheckBorderBulletCollision(Bullet& bullet);
void DrawBullet(Bullet bullet);
