#ifndef SHIP_H
#define SHIP_H

#include "enemy.h"
#include "gate.h"
class Ship : public Enemy
{
public:
	Ship();

	virtual ~Ship();

	virtual void update(float deltaTime);

	virtual void spawn(std::vector<Entity*> checkpoints, Gate* gate, Point3 spawnPosition, int speed);

	bool reachedEndPoint;

private:
	Point3 TargetPosition;
	Gate* localGate;
	int velo;
};

#endif

