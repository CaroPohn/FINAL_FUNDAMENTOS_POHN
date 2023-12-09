#include "WinScreen.h"
#include "Utilities.h"

void UpdateWinScreen(Scenes& scene)
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

void DrawWinScreen()
{
	SetForegroundColor(Color::CYAN);
	DrawFrame(1, 0, GetScreenWidth() - 2, GetScreenHeight() - 1);
	SetForegroundColor(Color::WHITE);

	DrawWinSky();
	DrawWinText();
}

void DrawWinText()
{
	int xText = 30;
	int yText = 12;

	SetForegroundColor(Color::LCYAN);
	GoToCoordinates(xText, yText);
	cout << " __ __   ___   __ __      __    __   ___   ____  " << endl;
	GoToCoordinates(xText, yText + 1);
	cout << "|  |  | /   \\ |  |  |    |  |__|  | /   \\ |    \\ " << endl;
	GoToCoordinates(xText, yText + 2);
	cout << "|  |  ||     ||  |  |    |  |  |  ||     ||  _  |" << endl;
	GoToCoordinates(xText, yText + 3);
	cout << "|  ~  ||  O  ||  |  |    |  |  |  ||  O  ||  |  |" << endl;
	GoToCoordinates(xText, yText + 4);
	cout << "|___, ||     ||  :  |    |  `  '  ||     ||  |  |" << endl;
	GoToCoordinates(xText, yText + 5);
	cout << "|     ||     ||     |     \\      / |     ||  |  |" << endl;
	GoToCoordinates(xText, yText + 6);
	cout << "|____/  \\___/  \\__,_|      \\_/\\_/   \\___/ |__|__|" << endl;
	SetForegroundColor(Color::WHITE);
}

void DrawWinSky()
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
	GoToCoordinates(xStars, yStars + 11);
	cout << "        .      ." << endl;
	GoToCoordinates(xStars + 80, yStars + 11);
	cout << "  .          ." << endl;
	GoToCoordinates(xStars, yStars + 12);
	cout << "           .         ." << endl;
	GoToCoordinates(xStars + 80, yStars + 12);
	cout << "     .             . " << endl;
	GoToCoordinates(xStars, yStars + 13);
	cout << " .            " << endl;
	GoToCoordinates(xStars + 80, yStars + 13);
	cout << "   .                .    " << endl;
	GoToCoordinates(xStars, yStars + 14);
	cout << "       .       ." << endl;
	GoToCoordinates(xStars + 80, yStars + 14);
	cout << ".       .          .  " << endl;
	GoToCoordinates(xStars, yStars + 15);
	cout << "  .                ." << endl;
	GoToCoordinates(xStars + 80, yStars + 15);
	cout << "       .     ." << endl;
	GoToCoordinates(xStars, yStars + 16);
	cout << "      .       ." << endl;
	GoToCoordinates(xStars + 80, yStars + 16);
	cout << "      .      .           ." << endl;
	GoToCoordinates(xStars, yStars + 17);
	cout << "   .              .  " << endl;
	GoToCoordinates(xStars + 80, yStars + 17);
	cout << "   .            . " << endl;
	GoToCoordinates(xStars, yStars + 18);
	cout << "    .                            .             .              .             .                      .   " << endl;
	GoToCoordinates(xStars, yStars + 19);
	cout << "            .            .                            .                                    .           " << endl;
	GoToCoordinates(xStars, yStars + 20);
	cout << "                                        .                            .           .             .       " << endl;
	GoToCoordinates(xStars, yStars + 21);
	cout << "    .             .         .                       .                    .                .            " << endl;
	GoToCoordinates(xStars, yStars + 22);
	cout << "     .        .        .         .          .                .                         .              ." << endl;
	GoToCoordinates(xStars, yStars + 23);

	SetForegroundColor(Color::CYAN);

	cout << ".                  .         .         .        _......____._        .         .               .       " << endl;
	GoToCoordinates(xStars, yStars + 24);
	cout << "         .       .          .          . ..--''' .           ''''''---...          .           .      " << endl;
	GoToCoordinates(xStars, yStars + 25);
	cout << "   .                 .           _...--''        ................       `-.              .            ." << endl;
	GoToCoordinates(xStars, yStars + 26);
	cout << "        .                     .-'        ...:'::::;:::%:.::::::_;;:...     `-.  .          .           " << endl;
	GoToCoordinates(xStars, yStars + 27);
	cout << "    .      .           .   .-'       ..::::'''''   _...---''''':::+;_::.      `.      .          .     " << endl;
	GoToCoordinates(xStars, yStars + 28);
	cout << " .              .        .' .    ..::::'      _.-''               :::)::.       `.         .          ." << endl;
	GoToCoordinates(xStars, yStars + 29);
	cout << "       .               .      ..;:::'     _.-'         .             f::'::    o  _               .    " << endl;
	GoToCoordinates(xStars, yStars + 30);
	cout << " .                    /     .:::%'  .  .-'                        . - .  ::;; :./' 'x  .               " << endl;

	SetForegroundColor(Color::LBLUE);

	GoToCoordinates(xStars, yStars + 31);
	cout << "                .   .'  ''::.::'    .-'     _.--''''-.           (   )  ::.::  |_.-' |        .         " << endl;
	GoToCoordinates(xStars, yStars + 32);
	cout << "      .    .       .'    ::;:'    .'     .-'.d@@b.   \\    .    . `-'   ::%::    \\_ _/    .       .    " << endl;
	GoToCoordinates(xStars, yStars + 33);
	cout << " .                .'    :,::'    /   . _'    8@@@@8   j      .-'       :::::      ' o          .       " << endl;
	GoToCoordinates(xStars, yStars + 34);
	cout << "          .       | .  :.%:' .  j     (_)    `@@@P'  .'   .-'         ::.::.      |    .               " << endl;
	GoToCoordinates(xStars, yStars + 35);
	cout << "    .             |    ::::     (        -..____...-'  .-'          .::::'       /             .      ." << endl;
	GoToCoordinates(xStars, yStars + 36);
	cout << ".             .   |    `:`::    `.                ..--'        .  .::'::   .    /    .                 " << endl;
	GoToCoordinates(xStars, yStars + 37);
	cout << "      .           |     `:::::    `-._____...---''             .::%:::'       .'  .         .          " << endl;
	GoToCoordinates(xStars, yStars + 38);
	cout << " .                 \\      ::.:%..             .       .    ...:,::::'       .'                  .     " << endl;

	SetForegroundColor(Color::BLUE);

	GoToCoordinates(xStars, yStars + 39);
	cout << "         .     .    \\       `:::`:..                ....::::.::::'       .-'          .              ." << endl;
	GoToCoordinates(xStars, yStars + 40);
	cout << "    .                \\    .   ``:::%::`::.......:::::%::.::::''       .-'                             " << endl;
	GoToCoordinates(xStars, yStars + 41);
	cout << "          .         . `.        . ``::::::%::::.::;;:::::'''      _.-'          .       .         .    " << endl;
	GoToCoordinates(xStars, yStars + 42);
	cout << ".               .       `-..     .    .   ````'''''         . _.-'     .          .          .         " << endl;
	GoToCoordinates(xStars, yStars + 43);
	cout << "      .                .    ''--...____    .   ______......--' .         .         .                 . " << endl;
	GoToCoordinates(xStars, yStars + 44);
	cout << "  .             .        .        .    ''''''''     .        .        .        .        .         .    " << endl;
	GoToCoordinates(xStars, yStars + 45);
	cout << "           .              .            .                            .                         .        " << endl;
	GoToCoordinates(xStars, yStars + 46);
	cout << "     .              .         .       .                    .                .         .               ." << endl;

	SetForegroundColor(Color::WHITE);
	GoToCoordinates(79, yStars + 47);
	cout << "Press 'M' to go back to MENU" << endl;
}

void RunWinScreen(Scenes& scene)
{
	UpdateWinScreen(scene);
	DrawWinScreen();
}
