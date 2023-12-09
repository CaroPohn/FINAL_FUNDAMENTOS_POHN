#pragma once
#include "Utilities.h"

struct Asteroid
{
	Vector2 pos = {};
	int width = 0;
	int height = 0;
	bool isActive = false;
};

Asteroid InitAsteroid();
void SetAsteroid(Asteroid& asteroid, int posX);
void AsteroidMovement(Asteroid& asteroid);
bool CheckBorderAsteroidCollision(Asteroid asteroid);
void DrawAsteroid(Asteroid asteroid);
