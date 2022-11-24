#include <iostream>
#include <list>
#include "wave.h"
using namespace std;

Wave::Wave(int enemiesPerWave, Point3 spawnPosition, Point3 targetPosition, int speed)
{
	for (int i = 0; i < enemiesPerWave; i++)
	{
		this->SpawnPosition += Point3(-100 * i, -1000000, 0);
		enemy = new Enemy();
		enemy->scale = Point(0.5, 0.5);
		enemies.push_back(enemy);
	}
}

Wave::~Wave()
{
}

void Wave::update(float deltaTime)
{
}
