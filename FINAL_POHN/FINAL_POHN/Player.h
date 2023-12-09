#pragma once
#include "Utilities.h"
#include "Scenes.h"

struct Player
{
	Vector2 pos = {};
	Vector2 prevPos = {};
	int width = 0;
	int height = 0;
};

Player InitPlayer();
void UpdatePlayer(Player& player);
void DrawPlayer(Player player);