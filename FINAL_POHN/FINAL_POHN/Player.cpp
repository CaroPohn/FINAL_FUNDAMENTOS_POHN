#include "Player.h"

Player InitPlayer()
{
	Player player;

	player.pos.x = GetScreenWidth() / 2 - 10;
	player.pos.y = GetScreenHeight() - 6;
	player.prevPos = player.pos;
	player.width = 15;
	player.height = 2;

	return player;
}

void UpdatePlayer(Player& player)
{
	player.prevPos = player.pos;
	char key = _getch();

	if (key == 'a' || key == 'A')
	{
		if (player.pos.x > 2)
			player.pos.x--;
	}
	else if (key == 'd' || key == 'D')
	{
		if (player.pos.x + player.width < (GetScreenWidth() - 3))
			player.pos.x++;
	}
}

void DrawPlayer(Player player)
{
	GoToCoordinates(player.prevPos.x, player.prevPos.y);
	cout << "                ";
	GoToCoordinates(player.prevPos.x, player.prevPos.y + 1);
	cout << "                ";
	GoToCoordinates(player.prevPos.x, player.prevPos.y + 2);
	cout << "                ";

	SetForegroundColor(Color::LCYAN);

	GoToCoordinates(player.pos.x, player.pos.y);
	cout << "       /\\ " << endl;
	GoToCoordinates(player.pos.x, player.pos.y + 1);
	cout << "   " << char(201) << char(196) << char(168) << char(196) << char(202) << char(202) << char(196) << char(168) << char(196) << char(187) << endl;
	GoToCoordinates(player.pos.x, player.pos.y + 2);
	cout << char(201) << char(202) << char(202) << char(188) << " " << char(153) << " " << char(186) << char(186) << " " << char(153) << " " << char(200) << char(202) << char(202) << char(187) << endl;

	SetForegroundColor(Color::WHITE);
}

