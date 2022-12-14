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

	//move to the target enemy
	void moveToTarget(Point3 targetPosition, float deltaTime);

	//choose which enemy to target, this enemy is always the closest one
	Point3 checkClosestEnemy(std::vector<Enemy*> enemies);

	//checks collision with the closest enemy
	int checkCollision(Point3 target);

	bool hitTarget;
private:

	int index;
};

#endif