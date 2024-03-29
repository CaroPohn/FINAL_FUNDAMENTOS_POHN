#include "GameLoop.h"

#include "Scenes.h"
#include "Utilities.h"
#include "Menu.h"
#include "Play.h"
#include "Rules.h"
#include "Credits.h"
#include "WinScreen.h"
#include "LoseScreen.h"

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
			RunMenu(scene, isNewScene);
			break;

		case Scenes::Play:
			RunPlay(scene, isNewScene, points);
			break;

		case Scenes::Rules:
			RunRules(scene, isNewScene);
			break;

		case Scenes::Credits:
			RunCredits(scene, isNewScene);
			break;

		case Scenes::WinScreen:
			RunWinScreen(scene);
			break;

		case Scenes::LoseScreen:
			RunLoseScreen(scene, points);
			break;

		case Scenes::Exit:
			break;

		default:
			break;
		}

	} while (scene != Scenes::Exit);

	system("cls");
}