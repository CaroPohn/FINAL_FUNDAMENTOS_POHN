#include "Play.h"
#include "Player.h"
#include "Asteroid.h"

static Player player;
static const int ASTEROID_QNTY = 4;
static Asteroid asteroidsArray[ASTEROID_QNTY];

void InitPlay()
{
	player = InitPlayer();

	for (int i = 0; i < ASTEROID_QNTY; i++)
	{
		asteroidsArray[i] = InitAsteroid();
	}
}

void UpdatePlay(Scenes& scene, int& points)
{
	UpdateAsteroidsArray();

	for (int i = 0; i < ASTEROID_QNTY; i++)
	{
		AsteroidMovement(asteroidsArray[i]);
	}

	for (int i = 0; i < player.BULLET_QNTY; i++)
	{
		BulletMovement(player.bulletArray[i]);
	}

	for (int i = 0; i < ASTEROID_QNTY; i++)
	{
		if (asteroidsArray[i].isActive && CheckAsteroidShipCollision(asteroidsArray[i]))
		{
			asteroidsArray[i].isActive = false;
			player.lives--;
		}
	}

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

	if (points >= 50)
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
}

void DrawPoints(int points)
{
	GoToCoordinates(100, 1);
	cout << "Points: " << points << endl;
}

void DrawLives()
{
	GoToCoordinates(2, 1);

	if (player.lives == 3)
		cout << "<3 <3 <3";
	else if (player.lives == 2)
		cout << "<3 <3   ";
	else if (player.lives == 1)
		cout << "<3      ";
}

void RunPlay(Scenes& scene, bool isNewScene, int& points)
{
	if (isNewScene)
	{
		InitPlay();
	}

	DrawPlay(points);
	UpdatePlay(scene, points);
}