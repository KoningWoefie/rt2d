#ifndef WAVE_H
#define WAVE_H

#include "enemy.h"
#include <iostream>

class Wave
{
public:
	Wave(int enemiesPerWave, Point3 spawnPosition, Point3 targetPosition, int speed);

	virtual ~Wave();

	virtual void update(float deltaTime);

	std::vector<Enemy*> enemies;

private:
	Enemy* enemy;

	Point3 SpawnPosition;
};
#endif

