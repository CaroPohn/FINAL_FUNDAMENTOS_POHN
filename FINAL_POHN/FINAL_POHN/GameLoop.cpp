#include "GameLoop.h"

#include "Scenes.h"
#include "Utilities.h"

static Scenes scene;

void GameLoop()
{
	SetConsoleTitleA("Cosmic Crusher");

	scene = Scenes::Menu;
	Scenes previousScene = Scenes::Exit;
	bool isNewScene;

	int consoleWidth = 110;
	int consoleHeight = 50;

	SetConsoleSize(consoleWidth, consoleHeight);

	do
	{
		isNewScene = (scene != previousScene);
		previousScene = scene;

		switch (scene)
		{
		case Scenes::Menu:
			
			break;

		case Scenes::Play:
			
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