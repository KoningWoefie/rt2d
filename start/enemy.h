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

	void move(Point3 position, Gate* gate, int speed, float deltaTime);

	void spawn(Point3 targetPosition, Gate* gate, Point3 spawnPosition, int speed);

	bool reachedEndPoint = false;

private:
	Point3 TargetPosition;
	Gate* localGate;
	int velo;
};

#endif

