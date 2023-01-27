#ifndef ENEMY_H
#define ENEMY_H

#include <rt2d/entity.h>
#include "gate.h"
class Enemy : public Entity
{
public:
	Enemy();

	virtual ~Enemy();

	virtual void update(float deltaTime);

	void move(Gate* gate, int speed, float deltaTime);

	virtual void spawn(std::vector<Entity*> checkpoints, Gate* gate, Point3 spawnPosition, int speed);

	bool reachedEndPoint;

protected:
	Gate* localGate;
	std::vector<Entity*> _checkPoints;
	int velo;
	bool checkPointReached;
};

#endif

