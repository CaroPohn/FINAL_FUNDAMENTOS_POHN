#include "Rules.h"
#include "Utilities.h"

void UpdateRules(Scenes& scene)
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

void DrawRules()
{
	SetForegroundColor(Color::CYAN);
	DrawFrame(1, 0, GetScreenWidth() - 2, GetScreenHeight() - 1);
	SetForegroundColor(Color::WHITE);

	DrawRulesTitle();

	SetForegroundColor(Color::LMAGENTA);
	DrawFrame(11, 12, GetScreenWidth() - 12, GetScreenHeight() - 6);
	SetForegroundColor(Color::WHITE);

	DrawRulesText();
}

void DrawRulesTitle()
{
	int xText = 38;
	int yText = 3;

	SetForegroundColor(Color::LMAGENTA);
	GoToCoordinates(xText, yText);
	cout << " ____  __ __  _        ___  _____" << endl;
	GoToCoordinates(xText, yText + 1);
	cout << "|    \\|  |  || |      /  _]/ ___/" << endl;
	GoToCoordinates(xText, yText + 2);
	cout << "|  D  )  |  || |     /  [_(   \\_ " << endl;
	GoToCoordinates(xText, yText + 3);
	cout << "|    /|  |  || |___ |    _]\\__  |" << endl;
	SetForegroundColor(Color::CYAN);
	GoToCoordinates(xText, yText + 4);
	cout << "|    \\|  :  ||     ||   [_ /  \\ |" << endl;
	GoToCoordinates(xText, yText + 5);
	cout << "|  .  \\     ||     ||     |\\    |" << endl;
	GoToCoordinates(xText, yText + 6);
	cout << "|__|\\_|\\__,_||_____||_____| \\___|" << endl;
	SetForegroundColor(Color::WHITE);
}

void DrawRulesText()
{
	int xText = 13;
	int yText = 14;

	GoToCoordinates(xText, yText);
	cout << "In COSMIC CRUSHER, you are a spaceship and you have to destroy as many asteroids as" << endl;
	GoToCoordinates(xText, yText + 1);
	cout << "possible by shooting them with your cannons. To win, you must accumulate 200 points." << endl;
	GoToCoordinates(xText, yText + 2);
	cout << "Each asteroid you break will give you 10 points!" << endl;

	GoToCoordinates(xText, yText + 5);
	cout << "CONTROLS:" << endl;
	GoToCoordinates(xText, yText + 6);
	cout << "\tUse A and D to move sideways." << endl;
	GoToCoordinates(xText, yText + 7);
	cout << "\tUse W or SPACE to shoot." << endl;
	GoToCoordinates(xText, yText + 8);
	cout << "\tPress M every time you want to go back to MENU" << endl;

	GoToCoordinates(xText, yText + 11);
	cout << "You only have 3 lives, and each time an asteroid hits you, you'll lose one. If you" << endl;
	GoToCoordinates(xText, yText + 12);
	cout << "run out of lives, you lose :(" << endl;

	GoToCoordinates(xText, yText + 15);
	cout << "Without much more to say hope you have fun and enjoy COSMIC CRUSHER :D" << endl;

	GoToCoordinates(xText, yText + 17);
	cout << "      .             -*-          .          .      .  +                 *          ." << endl;
	GoToCoordinates(xText, yText + 18);
	cout << "  +         .                *         .                 .       +          .       " << endl;
	GoToCoordinates(xText, yText + 19);
	cout << "       .          .  +          .               .                     .       -*-   " << endl;
	GoToCoordinates(xText, yText + 20);
	cout << "      .                          .          .      .                    *           " << endl;
	GoToCoordinates(xText, yText + 21);
	cout << "  .    _     *       \\|/   .       .      -*-       *         .               .   +" << endl;
	GoToCoordinates(xText, yText + 22);
	cout << "    .' \\\\`.     +    -*-     *   .         '       . +             .     *        " << endl;
	GoToCoordinates(xText, yText + 23);
	cout << " .  |__''_|  .       /|\\ +         .    +       .           .                 .  |" << endl;
	GoToCoordinates(xText, yText + 24);
	cout << "    |     | .                       +                 .            .        .    -*-" << endl;
	GoToCoordinates(xText, yText + 25);
	cout << "    |     |           `  .    '             . *   .    +     .         .          '" << endl;
	GoToCoordinates(xText, yText + 26);
	cout << "  _.'-----'-._     *                  .         +      .         .        *     .    " << endl;
	GoToCoordinates(xText, yText + 27);
	cout << "/             \\__.__.--._______________--------________________---__________---_____" << endl;

	GoToCoordinates(GetScreenWidth() - 39, GetScreenHeight() - 7);
	cout << "Press M to go back to menu" << endl;
}

void RunRules(Scenes& scene, bool isNewScene)
{
	if (isNewScene)
	{
		system("cls");
	}

	UpdateRules(scene);
	DrawRules();
}
