#include "Bullet.h"

Bullet InitBullet()
{
	Bullet bullet;

	bullet.pos.x = 0;
	bullet.pos.y = 0;
	bullet.isActive = false;

	return bullet;
}

void SetBullet(Bullet& bullet, Vector2 spawnPos)
{
	bullet.pos = spawnPos;
	bullet.isActive = true;
}

void BulletMovement(Bullet& bullet)
{
	if (bullet.isActive)
	{
		bullet.pos.y--;

		if (CheckBorderBulletCollision(bullet))
		{
			bullet.isActive = false;
		}
	}
}

bool CheckBorderBulletCollision(Bullet& bullet)
{
	return bullet.pos.y < 1;
}

void DrawBullet(Bullet bullet)
{
	if (bullet.isActive)
	{
		GoToCoordinates(bullet.pos.x, bullet.pos.y);
		cout << "O" << endl;

		GoToCoordinates(bullet.pos.x, bullet.pos.y + 1);
		cout << " " << endl;
	}

	if (!bullet.isActive)
	{
		GoToCoordinates(bullet.pos.x, bullet.pos.y + 1);
		cout << " " << endl;
	}
}
