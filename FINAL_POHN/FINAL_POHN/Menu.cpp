#include "Menu.h"

static const int totalOptions = 4;
static string options[totalOptions] = { "PLAY", "RULES", "CREDITS", "EXIT" };
static int selectedOption = 0;

void UpdateMenu(Scenes& scene)
{
	DrawMenu(selectedOption);

	char key = _getch();

	if (key == 'w' || key == 'W')
		selectedOption = (selectedOption - 1 + 4) % 4;
	else if (key == 's' || key == 'S')
		selectedOption = (selectedOption + 1) % 4;
	else if (key == '\r')
	{
		if (selectedOption == 0)
		{
			system("cls");
			scene = Scenes::Play;
		}
		else if (selectedOption == 1)
		{
			system("cls");
			scene = Scenes::Rules;
		}
		else if (selectedOption == 2)
		{
			system("cls");
			scene = Scenes::Credits;
		}
		else if (selectedOption == 3)
		{
			system("cls");
			scene = Scenes::Exit;
		}
	}
}

void DrawMenu(int selectedOption)
{
	int xTitle = 8;
	int yTitle = 12;

	int xOptions = 52;

	SetForegroundColor(Color::LMAGENTA);
	DrawFrame(1, 0, GetScreenWidth() - 2, GetScreenHeight() - 1);
	SetForegroundColor(Color::WHITE);

	DrawTitle(xTitle, yTitle);
	DrawOptions(xOptions, yTitle);
	DrawSpaceship();
	DrawSky();
}

void DrawTitle(int xTitle, int yTitle)
{

	SetForegroundColor(Color::MAGENTA);
	GoToCoordinates(xTitle, yTitle);
	cout << "    __   ___   _____ ___ ___  ____   __         __  ____  __ __  _____ __ __    ___  ____  " << endl;
	GoToCoordinates(xTitle, yTitle + 1);
	cout << "   /  ] /   \\ / ___/|   |   ||    | /  ]       /  ]|    \\|  |  |/ ___/|  |  |  /  _]|    \\ " << endl;
	GoToCoordinates(xTitle, yTitle + 2);
	cout << "  /  / |     (   \\_ | _   _ | |  | /  /       /  / |  D  )  |  (   \\_ |  |  | /  [_ |  D  )" << endl;
	SetForegroundColor(Color::LMAGENTA);
	GoToCoordinates(xTitle, yTitle + 3);
	cout << " /  /  |  O  |\\__  ||  \\_/  | |  |/  /       /  /  |    /|  |  |\\__  ||  _  ||    _]|    / " << endl;
	GoToCoordinates(xTitle, yTitle + 4);
	cout << "/   \\_ |     |/  \\ ||   |   | |  /   \\_     /   \\_ |    \\|  :  |/  \\ ||  |  ||   [_ |    \\ " << endl;
	SetForegroundColor(Color::CYAN);
	GoToCoordinates(xTitle, yTitle + 5);
	cout << "\\     ||     |\\    ||   |   | |  \\     |    \\     ||  .  \\     |\\    ||  |  ||     ||  .  \\" << endl;
	GoToCoordinates(xTitle, yTitle + 6);
	cout << " \\____| \\___/  \\___||___|___||____\\____|     \\____||__|\\_|\\__,_| \\___||__|__||_____||__|\\_|" << endl;

	SetForegroundColor(Color::WHITE);
}

void DrawOptions(int xOptions, int yTitle)
{
	for (int i = 0; i < totalOptions; i++)
	{
		GoToCoordinates(xOptions, yTitle + 9 + i);

		if (i == selectedOption)
		{
			SetForegroundColor(Color::LMAGENTA);
			GoToCoordinates(xOptions - 3, yTitle + 9 + i);
			cout << ">>";
			GoToCoordinates(xOptions, yTitle + 9 + i);
		}
		else
		{
			SetForegroundColor(Color::WHITE);
			GoToCoordinates(xOptions - 3, yTitle + 9 + i);
			cout << "  ";
			GoToCoordinates(xOptions, yTitle + 9 + i);
		}

		cout << options[i] << endl;
	}
}

void DrawSpaceship()
{
	int xShip = 25;
	int yShip = 28;
	
	SetForegroundColor(Color::LCYAN);

	GoToCoordinates(xShip, yShip);
	cout << "                     `. ___" << endl;
	GoToCoordinates(xShip, yShip + 1);
	cout << "                    __,' __`.                _..----....____" << endl;
	GoToCoordinates(xShip, yShip + 2);
	cout << "        __...--.'``;.   ,.   ;``--..__     .'    ,-._    _.-'" << endl;
	GoToCoordinates(xShip, yShip + 3);
	cout << "  _..-''-------'   `'   `'   `'     O ``-''._   (,;') _,'" << endl;
	GoToCoordinates(xShip, yShip + 4);
	cout << ",'________________                          \\`-._`-','" << endl;
	GoToCoordinates(xShip, yShip + 5);
	cout << " `._              ```````````------...___   '-.._'-:" << endl;
	GoToCoordinates(xShip, yShip + 6);
	cout << "    ```--.._      ,.                     ````--...__\\-." << endl;

	SetForegroundColor(Color::CYAN);
	GoToCoordinates(xShip, yShip + 7);
	cout << "            `.--. `-`                       ____    |  |`" << endl;
	GoToCoordinates(xShip, yShip + 8);
	cout << "              `. `.                       ,'`````.  ;  ;`" << endl;
	GoToCoordinates(xShip, yShip + 9);
	cout << "                `._`.        __________   `.      \\'__/`" << endl;
	GoToCoordinates(xShip, yShip + 10);
	cout << "                   `-:._____/______/___/____`.     \\  `" << endl;
	GoToCoordinates(xShip, yShip + 11);
	cout << "                               |       `._    `.    \\" << endl;
	GoToCoordinates(xShip, yShip + 12);
	cout << "                               `._________`-.   `.   `.___" << endl;
	GoToCoordinates(xShip, yShip + 13);
	cout << "                                                  `------'`" << endl;
}

void DrawSky()
{
	int xStars = 2;
	int yStars = 1;

	SetForegroundColor(Color::WHITE);

	GoToCoordinates(xStars, yStars);
	cout << "          _____                            .              .         .            .                    ." << endl;
	GoToCoordinates(xStars, yStars + 1);
	cout << "      ,-:` \;',`'-,           .                     .                                         .        " << endl;
	GoToCoordinates(xStars, yStars + 2);
	cout << "    .'-;_,;  ':-;_,'.                 .                        .                        .              " << endl;
	GoToCoordinates(xStars, yStars + 3);
	cout << "   /;   '/    ,  _`.-\\    .                         .                   .                         .   " << endl;
	GoToCoordinates(xStars, yStars + 4);
	cout << "  | '`. (`     /` ` \\`|              .                                            .        .          " << endl;
	GoToCoordinates(xStars, yStars + 5);
	cout << "  |:.  `\\`-.   \\_   / |        .             .              .             .                      .   " << endl;
	GoToCoordinates(xStars, yStars + 6);
	cout << "  |     (   `,  .`\\ ;'| .                            .                                    .           " << endl;
	GoToCoordinates(xStars, yStars + 7);
	cout << "   \\     | .'     `-'/                 .                            .           .             .       " << endl;
	GoToCoordinates(xStars, yStars + 8);
	cout << "    `.   ;/        .'       .                       .                    .                .            " << endl;
	GoToCoordinates(xStars, yStars + 9);
	cout << "      `'-._____.       .                    .                .                         .              ." << endl;
	GoToCoordinates(xStars, yStars + 10);
	cout << "   .       .                    .                .                         .                  .        " << endl;
	GoToCoordinates(xStars, yStars + 18);
	cout << "      .         .       .                    .                .                         .              " << endl;
	GoToCoordinates(xStars, yStars + 19);
	cout << ".            .                    .                 .                    .         .             .    ." << endl;
	GoToCoordinates(xStars, yStars + 20);
	cout << "                       .                    ." << endl;
	GoToCoordinates(xStars + 60, yStars + 20);
	cout << "  .               .             ." << endl;
	GoToCoordinates(xStars, yStars + 21);
	cout << "                             .         ." << endl;
	GoToCoordinates(xStars + 60, yStars + 21);
	cout << "                          .       " << endl;
	GoToCoordinates(xStars, yStars + 22);
	cout << "                                 .      " << endl;
	GoToCoordinates(xStars + 60, yStars + 22);
	cout << "   .                .             " << endl;
	GoToCoordinates(xStars, yStars + 23);
	cout << "             .                           ." << endl;
	GoToCoordinates(xStars + 60, yStars + 23);
	cout << "         .                       .  " << endl;
	GoToCoordinates(xStars, yStars + 24);
	cout << ".                                 .                 .                              .             .    ." << endl;
	GoToCoordinates(xStars, yStars + 25);
	cout << "                  .                     .                             .                    .           " << endl;
	GoToCoordinates(xStars, yStars + 26);
	cout << "     .                      .                            .                      .                      " << endl;
	GoToCoordinates(xStars, yStars + 27);
	cout << "                .                          .                         .                            .    " << endl;
	GoToCoordinates(xStars, yStars + 28);
	cout << "             .                           ." << endl;
	GoToCoordinates(xStars + 90, yStars + 28);
	cout << ".         .     " << endl;
	GoToCoordinates(xStars, yStars + 29);
	cout << "    .              .  " << endl;
	GoToCoordinates(xStars + 90, yStars + 29);
	cout << "              ." << endl;
	GoToCoordinates(xStars, yStars + 30);
	cout << ".           .           " << endl;
	GoToCoordinates(xStars + 82, yStars + 30);
	cout << "   .         .        " << endl;
	GoToCoordinates(xStars, yStars + 31);
	cout << "         .           . " << endl;
	GoToCoordinates(xStars + 82, yStars + 31);
	cout << "     .                 " << endl;
	GoToCoordinates(xStars, yStars + 32);
	cout << "            .            ." << endl;
	GoToCoordinates(xStars + 75, yStars + 32);
	cout << "  .              .       " << endl;
	GoToCoordinates(xStars, yStars + 33);
	cout << "                     . " << endl;
	GoToCoordinates(xStars + 82, yStars + 33);
	cout << "            .           " << endl;
	GoToCoordinates(xStars, yStars + 34);
	cout << "      .                 " << endl;
	GoToCoordinates(xStars + 82, yStars + 34);
	cout << "          .        " << endl;
	GoToCoordinates(xStars, yStars + 35);
	cout << "  .                     " << endl;
	GoToCoordinates(xStars + 82, yStars + 35);
	cout << "    .             . " << endl;
	GoToCoordinates(xStars, yStars + 36);
	cout << "         .              ." << endl;
	GoToCoordinates(xStars + 82, yStars + 36);
	cout << " .             .    " << endl;
	GoToCoordinates(xStars, yStars + 37);
	cout << "       .         .              .     ." << endl;
	GoToCoordinates(xStars + 82, yStars + 37);
	cout << "        .           " << endl;
	GoToCoordinates(xStars, yStars + 38);
	cout << "  .                      .             " << endl;
	GoToCoordinates(xStars + 82, yStars + 38);
	cout << "                .   " << endl;
	GoToCoordinates(xStars, yStars + 39);
	cout << "            .                      .  " << endl;
	GoToCoordinates(xStars + 82, yStars + 39);
	cout << "     .             ." << endl;
	GoToCoordinates(xStars, yStars + 40);
	cout << "       .         .              .     .         .              ." << endl;
	GoToCoordinates(xStars + 82, yStars + 40);
	cout << "        .           " << endl;
	GoToCoordinates(xStars, yStars + 41);
	cout << "            .                              .                         .                            .    " << endl;
	GoToCoordinates(xStars, yStars + 42);
	cout << "   .                        .                           .                           .                 ." << endl;
	GoToCoordinates(xStars, yStars + 43);
	cout << "                     .                 .                              .                       .        " << endl;
	GoToCoordinates(xStars, yStars + 44);
	cout << "        .                                         .                              .                     " << endl;
	GoToCoordinates(xStars, yStars + 45);
	cout << " .                              .                              .                                    .  " << endl;
	GoToCoordinates(xStars, yStars + 46);
	cout << "                 .                            .                             .             .            " << endl;
}

void RunMenu(Scenes& scene, bool isNewScene)
{
	if (isNewScene)
	{
		system("cls");
	}

	UpdateMenu(scene);
}