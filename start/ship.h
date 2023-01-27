#ifndef SHIP_H
#define SHIP_H

#include "enemy.h"
#include "gate.h"

/// <summary>
/// enemy that is a ship
/// </summary>
class Ship : public Enemy
{
public:
	/// <summary>
	/// constructor
	/// </summary>
	Ship();

	/// <summary>
	/// destructor
	/// </summary>
	virtual ~Ship();

	virtual void update(float deltaTime);

	/// <summary>
	/// spawns enemy on the correct position and gives local fields a value for the movement
	/// </summary>
	/// <param name="checkpoints"></param>
	/// <param name="gate"></param>
	/// <param name="spawnPosition"></param>
	/// <param name="speed"></param>
	virtual void spawn(std::vector<Entity*> checkpoints, Gate* gate, Point3 spawnPosition, int speed);

	/// <summary>
	/// true when enemy reached endgate
	/// </summary>
	bool reachedEndPoint;

private:
	/// <summary>
	/// end gate
	/// </summary>
	Gate* localGate;
	/// <summary>
	/// speed of enemy
	/// </summary>
	int velo;
};

#endif

