#include "Credits.h"
#include "Utilities.h"

void UpdateCredits(Scenes& scene)
{
	if (_kbhit())
	{
		char key = _getch();

		if (key == 'm' || key == 'M')
		{
			scene = Scenes::Menu;
		}
	}
}

void DrawCredits()
{
	SetForegroundColor(Color::CYAN);
	DrawFrame(1, 0, GetScreenWidth() - 2, GetScreenHeight() - 1);
	SetForegroundColor(Color::WHITE);

	DrawCreditsStars();
	DrawCreditsTitle();
}

void DrawCreditsTitle()
{
	int xTitle = 17;
	int yTitle = 12;

	int xName = 11;
	
	SetForegroundColor(Color::LCYAN);

	GoToCoordinates(xTitle, yTitle);
	cout << "  ____                                            _        _           " << endl;
	GoToCoordinates(xTitle, yTitle + 1);
	cout << " / ___| __ _ _ __ ___   ___   _ __ ___   __ _  __| | ___  | |__  _   _ " << endl;
	GoToCoordinates(xTitle, yTitle + 2);
	cout << "| |  _ / _` | '_ ` _ \\ / _ \\ | '_ ` _ \\ / _` |/ _` |/ _ \\ | '_ \\| | | |" << endl;
	GoToCoordinates(xTitle, yTitle + 3);
	cout << "| |_| | (_| | | | | | |  __/ | | | | | | (_| | (_| |  __/ | |_) | |_| |" << endl;
	GoToCoordinates(xTitle, yTitle + 4);
	cout << " \\____|\\__,_|_| |_| |_|\\___| |_| |_| |_|\\__,_|\\__,_|\\___| |_.__/ \\__, |" << endl;
	GoToCoordinates(xTitle, yTitle + 5);
	cout << "                                                                  |___/ " << endl;

	SetForegroundColor(Color::LMAGENTA);

	GoToCoordinates(xName, yTitle + 8);
	cout << "    __   ____  ____   ___   _      ____  ____    ____      ____   ___   __ __  ____  " << endl;
	GoToCoordinates(xName, yTitle + 9);
	cout << "   /  ] /    ||    \\ /   \\ | |    |    ||    \\  /    |    |    \\ /   \\ |  |  ||    \\ " << endl;
	GoToCoordinates(xName, yTitle + 10);
	cout << "  /  / |  o  ||  D  )     || |     |  | |  _  ||  o  |    |  o  )     ||  |  ||  _  |" << endl;
	GoToCoordinates(xName, yTitle + 11);
	cout << " /  /  |     ||    /|  O  || |___  |  | |  |  ||     |    |   _/|  O  ||  _  ||  |  |" << endl;
	GoToCoordinates(xName, yTitle + 12);
	cout << "/   \\_ |  _  ||    \\|     ||     | |  | |  |  ||  _  |    |  |  |     ||  |  ||  |  |" << endl;
	GoToCoordinates(xName, yTitle + 13);
	cout << "\\     ||  |  ||  .  \\     ||     | |  | |  |  ||  |  |    |  |  |     ||  |  ||  |  |" << endl;
	GoToCoordinates(xName, yTitle + 14);
	cout << " \\____||__|__||__|\\_|\\___/ |_____||____||__|__||__|__|    |__|   \\___/ |__|__||__|__|" << endl;

	SetForegroundColor(Color::WHITE);

	GoToCoordinates(79, GetScreenHeight() - 2);
	cout << "Press 'M' to go back to MENU" << endl;
}

void DrawCreditsStars()
{
	int xPlanet = 3;
	int yPlanet = 2;

	SetForegroundColor(Color::WHITE);

	GoToCoordinates(xPlanet, yPlanet);
	cout << "                 *       +          .              .                *              .             ." << endl;
	GoToCoordinates(xPlanet, yPlanet + 1);
	cout << "           '           .      |             .                      .                       .      " << endl;
	GoToCoordinates(xPlanet, yPlanet + 2);
	cout << "       ()    .-.,='``'=.    - o -       .                +                          .             " << endl;
	GoToCoordinates(xPlanet, yPlanet + 3);
	cout << "             '=/_       \\     |  *           .                      .                         .  " << endl;
	GoToCoordinates(xPlanet, yPlanet + 4);
	cout << "          *   |  '=._    |      .                    .                       .       +            " << endl;
	GoToCoordinates(xPlanet, yPlanet + 5);
	cout << "               \\     `=./`,           .    *                +          .                  .     '" << endl;
	GoToCoordinates(xPlanet, yPlanet + 6); 
	cout << "            .   '=.__.=' `='    .  *                  .               .              .       *    " << endl;
	GoToCoordinates(xPlanet, yPlanet + 7);
	cout << "   +             .         +            .                  .                *      .              " << endl;
	GoToCoordinates(xPlanet, yPlanet + 8);
	cout << "        O      *        '          .                +   .                  .                 .    " << endl;

	GoToCoordinates(xPlanet, yPlanet + 27);
	cout << ".       O      *        '          .                +   .                  .                 .        .  " << endl;
	GoToCoordinates(xPlanet, yPlanet + 28);
	cout << "   +             .         +            .                  .                *      .              .      " << endl;
	GoToCoordinates(xPlanet, yPlanet + 29);
	cout << "       .             *               .              .                *                    .              " << endl;
	GoToCoordinates(xPlanet, yPlanet + 30);
	cout << " .              +         .               .    *                +          .                   .     '   " << endl;
	GoToCoordinates(xPlanet, yPlanet + 31); 
	cout << "            .                    .  *                  .               .              .                  " << endl;
	GoToCoordinates(xPlanet, yPlanet + 32);
	cout << "   +             .         +            .                  .                *      .              .      " << endl;
	GoToCoordinates(xPlanet, yPlanet + 33);
	cout << "   .              .   /^--^\\     /^--^\\     /^--^\\           .               .          .           + " << endl;
	GoToCoordinates(xPlanet, yPlanet + 34);
	cout << "         *            \\____/     \\____/     \\____/  .            +                 .            .     " << endl;
	GoToCoordinates(xPlanet, yPlanet + 35);
	cout << ".             .      /      \\   /      \\   /      \\       .              .                +           " << endl;
	GoToCoordinates(xPlanet, yPlanet + 36);
	cout << "     .              |        | |        | |        |     *          .               .             .      " << endl;
	GoToCoordinates(xPlanet, yPlanet + 37);
	cout << "                 .  |        | |        | |        |             .          +           .               ." << endl;
	GoToCoordinates(xPlanet, yPlanet + 38);
	cout << "  +      .           \\__  __/   \\__  __/   \\__  __/  .              .       .                .        " << endl;
	GoToCoordinates(xPlanet, yPlanet + 39);
	cout << "|^|^|^|^|^|^|^|^|^|^|^|^\\ \\^|^|^|^/ /^|^|^|^|^\\ \\^|^|^|^|^|^|^|^|^|^|^|^|^|^|^|^|^|^|^|^|^|^|^|^|^|^|^|^|" << endl;
	GoToCoordinates(xPlanet, yPlanet + 40);
	cout << "| | | | | | | | | | | | |\\ \\| | |/ /| | | | | | \\ \\ | | | | | | | | | | | | | | | | | | | | | | | | | | |" << endl;
	GoToCoordinates(xPlanet, yPlanet + 41);
	cout << "########################/ /######\\ \\###########/ /#######################################################" << endl;
	GoToCoordinates(xPlanet, yPlanet + 42);
	cout << "| | | | | | | | | | | | \\/| | | | \\/| | | | | |\\/ | | | | | | | | | | | | | | | | | | | | | | | | | | | |" << endl;
	GoToCoordinates(xPlanet, yPlanet + 43);
	cout << "|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|" << endl;
}

void RunCredits(Scenes& scene, bool isNewScene)
{
	if (isNewScene)
	{
		system("cls");
	}

	UpdateCredits(scene);
	DrawCredits();
}
