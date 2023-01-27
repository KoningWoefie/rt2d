#include <iostream>
#include <list>
#include "wave.h"

Wave::Wave(int enemiesPerWave, Point3 spawnPosition, Point3 targetPosition, int speed)
{
	for (int i = 0; i < enemiesPerWave; i++)
	{
		this->SpawnPosition += Point3(-200 * i, 0, 0);
		if (i & 1)
		{
			ExplosiveBarrel* barrel = new ExplosiveBarrel();
			barrel->scale = Point(0.5, 0.5);
			enemies.push_back(barrel);
			barrel = nullptr;
		}
		else
		{
			Ship* ship = new Ship();
			ship->scale = Point(0.5, 0.5);
			enemies.push_back(ship);
			ship = nullptr;
		}
	}
}

Wave::~Wave()
{
}

void Wave::update(float deltaTime)
{
}