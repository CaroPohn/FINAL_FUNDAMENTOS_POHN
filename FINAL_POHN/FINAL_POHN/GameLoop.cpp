#include "GameLoop.h"

#include "Scenes.h"
#include "Utilities.h"
#include "Menu.h"
#include "Play.h"

static Scenes scene;
static int points = 0;

void GameLoop()
{
	SetConsoleTitleA("Cosmic Crusher");

	scene = Scenes::Menu;
	Scenes previousScene = Scenes::Exit;
	bool isNewScene;

	int consoleWidth = 110;
	int consoleHeight = 50;

	SetConsoleSize(consoleWidth, consoleHeight);

	srand(time(NULL));

	do
	{
		isNewScene = (scene != previousScene);
		previousScene = scene;

		switch (scene)
		{
		case Scenes::Menu:
			RunMenu(scene);
			break;

		case Scenes::Play:
			RunPlay(scene, isNewScene, points);
			break;

		case Scenes::Rules:
			
			break;

		case Scenes::Credits:
			
			break;

		case Scenes::WinScreen:
			
			break;

		case Scenes::LoseScreen:
			
			break;

		case Scenes::Exit:
			break;

		default:
			break;
		}

	} while (scene != Scenes::Exit);
}