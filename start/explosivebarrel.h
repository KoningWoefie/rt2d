#ifndef EXPLOSIVEBARREL_H
#define EXPLOSIVEBARREL_H

#include "enemy.h"
#include "gate.h"
#include "particle.h"

/// <summary>
/// specific enemy that fires particles on death
/// </summary>
class ExplosiveBarrel : public Enemy
{
public:
	/// <summary>
	/// constructor
	/// </summary>
	ExplosiveBarrel();

	/// <summary>
	/// destructor
	/// </summary>
	virtual ~ExplosiveBarrel();

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
	/// true when it reaches the endgate
	/// </summary>
	bool reachedEndPoint;

private:
	/// <summary>
	/// endgate
	/// </summary>
	Gate* localGate;
	/// <summary>
	/// speed of the explosivebarrel
	/// </summary>
	int velo;
};

#endif

