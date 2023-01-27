#ifndef ENEMY_H
#define ENEMY_H

#include <rt2d/entity.h>
#include "gate.h"

/// <summary>
/// enemy script with all the things an enemy needs
/// </summary>
class Enemy : public Entity
{
public:
	/// <summary>
	/// constructor
	/// </summary>
	Enemy();

	/// <summary>
	/// destructor
	/// </summary>
	virtual ~Enemy();

	virtual void update(float deltaTime);

	/// <summary>
	/// moves the enemy to the next checkpoint
	/// </summary>
	/// <param name="gate"></param>
	/// <param name="speed"></param>
	/// <param name="deltaTime"></param>
	void move(Gate* gate, int speed, float deltaTime);

	/// <summary>
	/// spawns enemy on the correct position and gives local fields a value for the movement
	/// </summary>
	/// <param name="checkpoints"></param>
	/// <param name="gate"></param>
	/// <param name="spawnPosition"></param>
	/// <param name="speed"></param>
	virtual void spawn(std::vector<Entity*> checkpoints, Gate* gate, Point3 spawnPosition, int speed);

	/// <summary>
	/// true when enemy reaches the endgate
	/// </summary>
	bool reachedEndPoint;

protected:
	/// <summary>
	/// endgate
	/// </summary>
	Gate* localGate;
	/// <summary>
	/// list of all the checkpoints
	/// </summary>
	std::vector<Entity*> _checkPoints;
	/// <summary>
	/// speed of the enemy
	/// </summary>
	int velo;
	/// <summary>
	/// true when the next checkpoint is reached
	/// </summary>
	bool checkPointReached;
};

#endif

