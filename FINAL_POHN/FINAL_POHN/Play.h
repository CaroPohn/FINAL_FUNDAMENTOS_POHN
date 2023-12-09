#pragma once
#include "Scenes.h"
#include "Asteroid.h"
#include "Bullet.h"

void InitPlay(int& points);
void UpdatePlay(Scenes& scene, int& points);
void UpdateAsteroidsArray();
bool CheckAsteroidShipCollision(Asteroid asteroid);
bool CheckAsteroidBulletCollision(Asteroid asteroid, Bullet bullet);
void DrawPlay(int points);
void DrawPoints(int points);
void DrawLives();
void DrawMenuInput();
void DrawStars();
void RunPlay(Scenes& scene, bool isNewScene, int& points);
