#ifndef EXPLOSIVEBARREL_H
#define EXPLOSIVEBARREL_H

#include "enemy.h"
#include "gate.h"
class ExplosiveBarrel : public Enemy
{
public:
	ExplosiveBarrel();

	virtual ~ExplosiveBarrel();

	virtual void update(float deltaTime);

	virtual void spawn(Point3 targetPosition, Gate* gate, Point3 spawnPosition, int speed);

	bool reachedEndPoint;

private:
	Point3 TargetPosition;
	Gate* localGate;
	int velo;
};

#endif

