#pragma once
#include "Scenes.h"

void UpdateLoseScreen(Scenes& scene);
void DrawLoseScreen(int points);
void DrawLoseText();
void DrawLoseSky();
void DrawLosePoints(int points);
void RunLoseScreen(Scenes& scene, int points);

