#pragma once
#include "Utilities.h"
#include "Scenes.h"

void UpdateMenu(Scenes& scene);
void DrawMenu(int selectedOption);
void DrawTitle(int xTitle, int yTitle);
void DrawOptions(int xOptions, int yTitle);
void DrawSpaceship();
void DrawSky();
void RunMenu(Scenes& scene);
