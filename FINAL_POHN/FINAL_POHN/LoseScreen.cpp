#include "LoseScreen.h"
#include "Utilities.h"

void UpdateLoseScreen(Scenes& scene)
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

void DrawLoseScreen(int points)
{
	SetForegroundColor(Color::RED);
	DrawFrame(1, 0, GetScreenWidth() - 2, GetScreenHeight() - 1);
	SetForegroundColor(Color::WHITE);

	DrawLoseSky();
	DrawLoseText();
	DrawLosePoints(points);
}

void DrawLoseText()
{
	int xText = 27;
	int yText = 12;

	SetForegroundColor(Color::LRED);
	GoToCoordinates(xText, yText);
	cout << " __ __   ___   __ __      _       ___   _____ ______ " << endl;
	GoToCoordinates(xText, yText + 1);
	cout << "|  |  | /   \\ |  |  |    | |     /   \\ / ___/|      |" << endl;
	GoToCoordinates(xText, yText + 2);
	cout << "|  |  ||     ||  |  |    | |    |     (   \\_ |      |" << endl;
	GoToCoordinates(xText, yText + 3);
	cout << "|  ~  ||  O  ||  |  |    | |___ |  O  |\\__  ||_|  |_|" << endl;
	GoToCoordinates(xText, yText + 4);
	cout << "|___, ||     ||  :  |    |     ||     |/  \\ |  |  |  " << endl;
	GoToCoordinates(xText, yText + 5);
	cout << "|     ||     ||     |    |     ||     |\\    |  |  |  " << endl;
	GoToCoordinates(xText, yText + 6);
	cout << "|____/  \\___/  \\__,_|    |_____| \\___/  \\___|  |__|  " << endl;
	SetForegroundColor(Color::WHITE);
}

void DrawLoseSky()
{
	int xStars = 2;
	int yStars = 1;

	SetForegroundColor(Color::GRAY);

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
	cout << "       .      " << endl;
	GoToCoordinates(xStars + 80, yStars + 13);
	cout << "   .                .    " << endl;
	GoToCoordinates(xStars, yStars + 14);
	cout << "       .       ." << endl;
	GoToCoordinates(xStars + 80, yStars + 14);
	cout << ".       .          .  " << endl;
	GoToCoordinates(xStars, yStars + 15);
	cout << "       .           ." << endl;
	GoToCoordinates(xStars + 80, yStars + 15);
	cout << "            ." << endl;

	SetForegroundColor(Color::BROWN);

	GoToCoordinates(xStars, yStars + 16);
	cout << "  .         ." << endl;
	GoToCoordinates(xStars + 80, yStars + 16);
	cout << "      .      .          " << endl;
	GoToCoordinates(xStars, yStars + 17);
	cout << "   .      " << endl;
	GoToCoordinates(xStars + 80, yStars + 17);
	cout << "   .            .   " << endl;
	GoToCoordinates(xStars, yStars + 18);
	cout << "    .                            .             .              .             .                      .   " << endl;
	GoToCoordinates(xStars, yStars + 19);
	cout << "            .   ||       .          |" << endl;
	GoToCoordinates(xStars + 70, yStars + 19);
	cout << "                     .           " << endl;
	GoToCoordinates(xStars, yStars + 20);
	cout << "                                  ::.   .                         ||:.           .             .       " << endl;
	GoToCoordinates(xStars, yStars + 21);
	cout << "    .             .         .                 ||    . ||    |            .                .            " << endl;
	GoToCoordinates(xStars, yStars + 22);
	cout << "              .        . :       |       | .::              .::      |                 .     |        ." << endl;
	GoToCoordinates(xStars, yStars + 23);
	cout << "   .       .                  |:.                .     |         |         .                  .        " << endl;
	GoToCoordinates(xStars, yStars + 24);
	cout << "           |    ` :     | |:      :     `     |     :   :   :    .        `   :.         .       ||   ." << endl;
	GoToCoordinates(xStars, yStars + 25);
	cout << ".            .      ` :   :|      |:  :    `       :| :     |    |  .                    :    |        " << endl;
	GoToCoordinates(xStars, yStars + 26);
	cout << "   .                   .' ':       :  |  '       `      :    : : |   .  `           .   :.  |    .     " << endl;
	GoToCoordinates(xStars, yStars + 27);
	cout << "         .                    `'   |     '     *    ` :        |    :   :               :              " << endl;
	GoToCoordinates(xStars, yStars + 28);
	cout << "     .          .     *    *       `  |  : :  |  .      ` '    | :| .   :         *   :.|    .         " << endl;
	GoToCoordinates(xStars, yStars + 29);
	cout << " .       .                 .`            |       : .:|       ` |    |   |: |             |          .  " << endl;

	SetForegroundColor(Color::LRED);

	GoToCoordinates(xStars, yStars + 30);
	cout << "     .       .      '          .         + `     :  .: .         '    :  |      .   |   |       .      " << endl;
	GoToCoordinates(xStars, yStars + 31);
	cout << "  .         .          .                 .    `      | :       `    | | :| | :      |:| |  .           " << endl;
	GoToCoordinates(xStars, yStars + 32);
	cout << "      .        .                .          .         |  .: *          |  | : :     :|||            .   " << endl;
	GoToCoordinates(xStars, yStars + 33);
	cout << "   .                  .            .   . *    .   .  ` | |.  +        + '| | |  .  ||`  .              " << endl;
	GoToCoordinates(xStars, yStars + 34);
	cout << "       .           .             *              .     +:`|!             . |  |  :. |`              .   " << endl;
	GoToCoordinates(xStars, yStars + 35);
	cout << " .             +                      .                ..  *          . | :` |  | |`          .        " << endl;
	GoToCoordinates(xStars, yStars + 36);
	cout << "   .               .                         +      : | |`        .  :  | | |.| ||`     .             ." << endl;

	SetForegroundColor(Color::RED);

	GoToCoordinates(xStars, yStars + 37);
	cout << "        .            *     +   '               +  :|  |`     :.+.  | |  | |:`|| ` .           .        " << endl;
	GoToCoordinates(xStars, yStars + 38);
	cout << "                                          .      .||` .    .. | | |: '` `| | |`  +                  .  " << endl;
	GoToCoordinates(xStars, yStars + 39);
	cout << "  .      .      .       +++                      ||        ! !: `       :| |           .       .       " << endl;
	GoToCoordinates(xStars, yStars + 40);
	cout << "                            +         .      .    | .      `| |.:      .||    .      .    `            " << endl;
	GoToCoordinates(xStars, yStars + 41);
	cout << "    .       .           '                           `|.   .  `:| |   + ||'     `                 .     " << endl;
	GoToCoordinates(xStars, yStars + 42);
	cout << "        .       __    +      *                         `'       `'|.    `:         .              .    " << endl;
	GoToCoordinates(xStars, yStars + 44);
	cout << "  '''         ''  `---'''----....____,..^---`^``----.,.___          `.    `.  .    ____,.,---- . .--   " << endl;
	GoToCoordinates(xStars, yStars + 45);
	cout << "      ---         ___,--'''`---''   ^  ^ ^        ^       ''''---,..___ __,..---'''                  --" << endl;
	GoToCoordinates(xStars, yStars + 46);
	cout << " -----   ------- '                                 ^                         ``                        " << endl;

	SetForegroundColor(Color::WHITE);

	GoToCoordinates(79, yStars + 47);
	cout << "Press 'M' to go back to MENU" << endl;
}

void DrawLosePoints(int points)
{
	SetForegroundColor(Color::WHITE);
	GoToCoordinates(45, 20);
	cout << "You've made " << points << " points!" << endl;
}

void RunLoseScreen(Scenes& scene, int points)
{
	UpdateLoseScreen(scene);
	DrawLoseScreen(points);
}
