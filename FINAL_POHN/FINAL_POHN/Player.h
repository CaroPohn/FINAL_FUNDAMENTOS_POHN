#pragma once
#include "Utilities.h"
#include "Scenes.h"
#include "Bullet.h"

struct Player
{
	Vector2 pos = {};
	Vector2 prevPos = {};
	int width = 0;
	int height = 0;
	int lives = 3;

	static const int BULLET_QNTY = 30;
	Bullet bulletArray[BULLET_QNTY];
};

Player InitPlayer();
void MovePlayer(Player& player, char key);
void PlayerShoot(Player& player, char key);
void DrawPlayer(Player player);