#include "Asteroid.h"

Asteroid InitAsteroid()
{
    Asteroid asteroid;

    asteroid.pos.x = 0;
    asteroid.pos.y = 3;
    asteroid.width = 7;
    asteroid.height = 4;
    asteroid.isActive = false;

    return asteroid;
}

void SetAsteroid(Asteroid& asteroid, int posX)
{
    asteroid.pos.x = posX;
    asteroid.pos.y = 3;
    asteroid.isActive = true;
}

void AsteroidMovement(Asteroid& asteroid)
{
    if (asteroid.isActive)
    {
        asteroid.pos.y++;

        if (CheckBorderAsteroidCollision(asteroid))
        {
            asteroid.isActive = false;
        }
    }
}

bool CheckBorderAsteroidCollision(Asteroid asteroid)
{
    return asteroid.pos.y + asteroid.height > (GetScreenHeight() - 3);
}

void DrawAsteroid(Asteroid asteroid)
{
    if (asteroid.isActive)
    {
        GoToCoordinates(asteroid.pos.x, asteroid.pos.y);
        cout << "    _ _  " << endl;
        GoToCoordinates(asteroid.pos.x, asteroid.pos.y + 1);
        cout << "  _( `.\\" << endl;
        GoToCoordinates(asteroid.pos.x, asteroid.pos.y + 2);
        cout << " / /   /" << endl;
        GoToCoordinates(asteroid.pos.x, asteroid.pos.y + 3);
        cout << "(     _/" << endl;
        GoToCoordinates(asteroid.pos.x, asteroid.pos.y + 4);
        cout << " '__/-'" << endl;

        GoToCoordinates(asteroid.pos.x, asteroid.pos.y - 1);
        cout << "         " << endl;
    }

    if (!asteroid.isActive)
    {
        GoToCoordinates(asteroid.pos.x, asteroid.pos.y - 1);
        cout << "         " << endl;
        GoToCoordinates(asteroid.pos.x, asteroid.pos.y);
        cout << "         " << endl;
        GoToCoordinates(asteroid.pos.x, asteroid.pos.y + 1);
        cout << "         " << endl;
        GoToCoordinates(asteroid.pos.x, asteroid.pos.y + 2);
        cout << "         " << endl;
        GoToCoordinates(asteroid.pos.x, asteroid.pos.y + 3);
        cout << "         " << endl;
        GoToCoordinates(asteroid.pos.x, asteroid.pos.y + 4);
        cout << "         " << endl;
    }
}
