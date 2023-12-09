#include "Play.h"
#include "Player.h"
#include "Asteroid.h"

static Player player;
static const int ASTEROID_QNTY = 4;
static Asteroid asteroidsArray[ASTEROID_QNTY];
static const int MAX_POINTS = 200;

void InitPlay(int& points)
{
	player = InitPlayer();
	points = 0;

	for (int i = 0; i < ASTEROID_QNTY; i++)
	{
		asteroidsArray[i] = InitAsteroid();
	}
}

void UpdatePlay(Scenes& scene, int& points)
{
	UpdateAsteroidsArray();

	//Move Asteroids
	for (int i = 0; i < ASTEROID_QNTY; i++)
	{
		AsteroidMovement(asteroidsArray[i]);
	}

	//Move Bullets
	for (int i = 0; i < player.BULLET_QNTY; i++)
	{
		BulletMovement(player.bulletArray[i]);
	}

	//Check every asteroid collision with player
	for (int i = 0; i < ASTEROID_QNTY; i++)
	{
		if (asteroidsArray[i].isActive && CheckAsteroidShipCollision(asteroidsArray[i]))
		{
			asteroidsArray[i].isActive = false;
			player.lives--;
		}
	}

	//Check every asteroid collision with every bullet
	for (int i = 0; i < ASTEROID_QNTY; i++)
	{
		if (asteroidsArray[i].isActive)
		{
			for (int j = 0; j < player.BULLET_QNTY; j++)
			{
				if (player.bulletArray[j].isActive)
				{
					if (CheckAsteroidBulletCollision(asteroidsArray[i], player.bulletArray[j]))
					{
						asteroidsArray[i].isActive = false;
						player.bulletArray[j].isActive = false;
						points += 10;
					}
				}
			}
		}
	}

	if (player.lives <= 0)
	{
		system("cls");
		scene = Scenes::LoseScreen;
	}

	if (points >= MAX_POINTS)
	{
		system("cls");
		scene = Scenes::WinScreen;
	}

	if (_kbhit())
	{
		char key = _getch();

		MovePlayer(player, key);
		PlayerShoot(player, key);

		if (key == 'm' || key == 'M')
		{
			system("cls");
			scene = Scenes::Menu;
		}
	}

	Sleep(20);
}

void UpdateAsteroidsArray()
{
	int xRandRange = GetScreenWidth() / 4;

	if (!asteroidsArray[0].isActive)
	{
		int xPos = rand() % (xRandRange - 2 - asteroidsArray[0].width) + 2;
		SetAsteroid(asteroidsArray[0], xPos);
	}

	if (!asteroidsArray[1].isActive)
	{
		int xPos = rand() % (xRandRange - asteroidsArray[1].width) + xRandRange;
		SetAsteroid(asteroidsArray[1], xPos);
	}

	if (!asteroidsArray[2].isActive)
	{
		int xPos = rand() % (xRandRange - asteroidsArray[1].width) + xRandRange * 2;
		SetAsteroid(asteroidsArray[2], xPos);
	}

	if (!asteroidsArray[3].isActive)
	{
		int xPos = rand() % (xRandRange - asteroidsArray[1].width - 2) + xRandRange * 3;
		SetAsteroid(asteroidsArray[3], xPos);
	}

}

bool CheckAsteroidShipCollision(Asteroid asteroid)
{
	float playerRightEdge = player.pos.x + player.width;
	float playerLeftEdge = player.pos.x;
	float playerTopEdge = player.pos.y + player.height;
	float playerBottomEdge = player.pos.y;

	float asteroidRightEdge = asteroid.pos.x + asteroid.width;
	float asteroidLeftEdge = asteroid.pos.x;
	float asteroidTopEdge = asteroid.pos.y + asteroid.height;
	float asteroidBottomEdge = asteroid.pos.y;

	return (playerRightEdge >= asteroidLeftEdge &&
		playerLeftEdge <= asteroidRightEdge &&
		playerTopEdge >= asteroidBottomEdge &&
		playerBottomEdge <= asteroidTopEdge);
}

bool CheckAsteroidBulletCollision(Asteroid asteroid, Bullet bullet)
{
	float asteroidRightEdge = asteroid.pos.x + asteroid.width;
	float asteroidLeftEdge = asteroid.pos.x;
	float asteroidTopEdge = asteroid.pos.y + asteroid.height;
	float asteroidBottomEdge = asteroid.pos.y;

	return (bullet.pos.x >= asteroidLeftEdge &&
		bullet.pos.x <= asteroidRightEdge &&
		bullet.pos.y >= asteroidBottomEdge &&
		bullet.pos.y <= asteroidTopEdge);
}

void DrawPlay(int points)
{
	SetForegroundColor(Color::LMAGENTA);
	DrawFrame(1, 2, GetScreenWidth() - 2, GetScreenHeight() - 1);
	SetForegroundColor(Color::WHITE);

	DrawStars();
	DrawPlayer(player);

	for (int i = 0; i < player.BULLET_QNTY; i++)
	{
		DrawBullet(player.bulletArray[i]);
	}

	for (int i = 0; i < ASTEROID_QNTY; i++)
	{
		DrawAsteroid(asteroidsArray[i]);
	}

	DrawPoints(points);
	DrawLives();
	DrawMenuInput();
}

void DrawPoints(int points)
{
	GoToCoordinates(GetScreenWidth() / 2 - 12, 1);
	cout << "Points: " << points << endl;
}

void DrawLives()
{
	GoToCoordinates(2, 1);

	if (player.lives == 3)
		cout << "Lives: <3 <3 <3";
	else if (player.lives == 2)
		cout << "Lives: <3 <3   ";
	else if (player.lives == 1)
		cout << "Lives: <3      ";
}

void DrawMenuInput()
{
	GoToCoordinates(GetScreenWidth() - 30, 1);
	cout << "Press 'M' to go back to MENU" << endl;
}

void DrawStars()
{
	int xStars = 2;
	int yStars = 3;

	SetForegroundColor(Color::GRAY);

	GoToCoordinates(xStars, yStars);
	cout << "       .                                   .              .         .            .                    ." << endl;
	GoToCoordinates(xStars, yStars + 1);
	cout << "               .              .                     .                                         .        " << endl;
	GoToCoordinates(xStars, yStars + 2);
	cout << ".                                     .                        .                        .              " << endl;
	GoToCoordinates(xStars, yStars + 3);
	cout << "         .                 .                         .                   .                         .   " << endl;
	GoToCoordinates(xStars, yStars + 4);
	cout << "                  .                   .                                            .        .          " << endl;
	GoToCoordinates(xStars, yStars + 5);
	cout << "    .                            .             .              .             .                      .   " << endl;
	GoToCoordinates(xStars, yStars + 6);
	cout << "            .            .                            .                                    .           " << endl;
	GoToCoordinates(xStars, yStars + 7);
	cout << "                                        .                            .           .             .       " << endl;
	GoToCoordinates(xStars, yStars + 8);
	cout << "    .             .         .                       .                    .                .            " << endl;
	GoToCoordinates(xStars, yStars + 9);
	cout << "              .        .                    .                .                         .              ." << endl;
	GoToCoordinates(xStars, yStars + 10);
	cout << "   .       .                    .                .                         .                  .        " << endl;
	GoToCoordinates(xStars, yStars + 11);
	cout << "      .         .       .                    .                .                         .              " << endl;
	GoToCoordinates(xStars, yStars + 12);
	cout << ".            .                    .                 .                    .         .             .    ." << endl;
	GoToCoordinates(xStars, yStars + 13);
	cout << "     .                  .                 .                      .                         .           " << endl;
	GoToCoordinates(xStars, yStars + 14);
	cout << "               .              .                     .                                         .        " << endl;
	GoToCoordinates(xStars, yStars + 15);
	cout << ".                                     .                        .                        .              " << endl;
	GoToCoordinates(xStars, yStars + 16);
	cout << "         .                 .                         .                   .                         .   " << endl;
	GoToCoordinates(xStars, yStars + 17);
	cout << "                  .                   .                                            .        .          " << endl;
	GoToCoordinates(xStars, yStars + 18);
	cout << "    .                            .             .              .             .                      .   " << endl;
	GoToCoordinates(xStars, yStars + 19);
	cout << "            .            .                            .                                    .           " << endl;
	GoToCoordinates(xStars, yStars + 20);
	cout << "                                        .                            .           .             .       " << endl;
	GoToCoordinates(xStars, yStars + 21);
	cout << "    .             .         .                       .                    .                .            " << endl;
	GoToCoordinates(xStars, yStars + 22);
	cout << "              .        .                    .                .                         .              ." << endl;
	GoToCoordinates(xStars, yStars + 23);
	cout << "   .       .                    .                .                         .                  .        " << endl;
	GoToCoordinates(xStars, yStars + 24);
	cout << "      .         .       .                    .                .                         .              " << endl;
	GoToCoordinates(xStars, yStars + 25);
	cout << ".            .                    .                 .                    .         .             .    ." << endl;
	GoToCoordinates(xStars, yStars + 26);
	cout << "     .                  .                 .                      .                         .           " << endl;
	GoToCoordinates(xStars, yStars + 27);
	cout << "               .              .                     .                                         .        " << endl;
	GoToCoordinates(xStars, yStars + 28);
	cout << ".                                     .                        .                        .              " << endl;
	GoToCoordinates(xStars, yStars + 29);
	cout << "         .                 .                         .                   .                         .   " << endl;
	GoToCoordinates(xStars, yStars + 30);
	cout << "                  .                   .                                            .        .          " << endl;
	GoToCoordinates(xStars, yStars + 31);
	cout << "    .                            .             .              .             .                      .   " << endl;
	GoToCoordinates(xStars, yStars + 32);
	cout << "            .            .                            .                                    .           " << endl;
	GoToCoordinates(xStars, yStars + 33);
	cout << "                                        .                            .           .             .       " << endl;
	GoToCoordinates(xStars, yStars + 34);
	cout << "    .             .         .                       .                    .                .            " << endl;
	GoToCoordinates(xStars, yStars + 35);
	cout << "              .        .                    .                .                         .              ." << endl;
	GoToCoordinates(xStars, yStars + 36);
	cout << "   .       .                    .                .                         .                  .        " << endl;
	GoToCoordinates(xStars, yStars + 37);
	cout << "      .         .       .                    .                .                         .              " << endl;
	GoToCoordinates(xStars, yStars + 38);
	cout << ".            .                    .                 .                    .         .             .    ." << endl;
	GoToCoordinates(xStars, yStars + 39);
	cout << "     .                  .                 .                      .                         .           " << endl;
	GoToCoordinates(xStars, yStars + 40);
	cout << "               .              .                     .                                         .        " << endl;
	GoToCoordinates(xStars, yStars + 41);
	cout << ".                                     .                        .                        .              " << endl;
	GoToCoordinates(xStars, yStars + 42);
	cout << "         .                 .                         .                   .                         .   " << endl;
	GoToCoordinates(xStars, yStars + 43);
	cout << "                  .                   .                                            .        .          " << endl;
	GoToCoordinates(xStars, yStars + 44);
	cout << "    .                            .             .              .             .                      .   " << endl;
	GoToCoordinates(xStars, yStars + 45);
	cout << "            .            .                            .                                    .           " << endl;

	SetForegroundColor(Color::WHITE);
}

void RunPlay(Scenes& scene, bool isNewScene, int& points)
{
	if (isNewScene)
	{
		InitPlay(points);
	}

	DrawPlay(points);
	UpdatePlay(scene, points);
}