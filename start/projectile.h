#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <rt2d/entity.h>
#include "enemy.h"

class Projectile : public Entity
{
public:
	Projectile();

	virtual ~Projectile();

	virtual void update(float deltaTime);

	void moveToTarget(Point3 targetPosition, float deltaTime);

	Point3 checkClosestEnemy(std::vector<Enemy*> enemies);

	void checkCollision();

	bool hitTarget;
private:

};

#endif