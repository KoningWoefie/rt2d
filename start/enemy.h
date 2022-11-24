#ifndef ENEMY_H
#define ENEMY_H

#include <rt2d/entity.h>
class Enemy : public Entity
{
public:
	Enemy();

	virtual ~Enemy();

	virtual void update(float deltaTime);

	void move(Point3 position, int speed, float deltaTime);

	void spawn(Point3 targetPosition, Point3 spawnPosition, int speed);

private:
	Point3 TargetPosition;
	int velo;
};

#endif

