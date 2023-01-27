#ifndef WAVE_H
#define WAVE_H

#include "ship.h"
#include "explosivebarrel.h"
#include <iostream>

/// <summary>
/// enemy spawning in waves
/// </summary>
class Wave
{
public:
	/// <summary>
	/// constructor
	/// </summary>
	/// <param name="enemiesPerWave"></param>
	/// <param name="spawnPosition"></param>
	/// <param name="targetPosition"></param>
	/// <param name="speed"></param>
	Wave(int enemiesPerWave, Point3 spawnPosition, Point3 targetPosition, int speed);

	/// <summary>
	/// destructor
	/// </summary>
	virtual ~Wave();

	virtual void update(float deltaTime);

	/// <summary>
	/// list of all enemies in the wave
	/// </summary>
	std::vector<Enemy*> enemies;

private:
	/// <summary>
	/// spawnposition of the enemies spawned by the wave
	/// </summary>
	Point3 SpawnPosition;
};
#endif