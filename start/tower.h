#ifndef TOWER_H
#define TOWER_H

#include <rt2d/entity.h>
#include "enemy.h"
#include "projectile.h"

class Tower : public Entity
{
public:
	Tower();

	virtual ~Tower();

	virtual void update(float deltaTime);

	void moveWithMouse();

	virtual void targetEnemy(Point3 target, float deltaTime);

	Projectile* projectile;

	bool projectileSpawned;

	bool placed;

	virtual void spawnProjectile();

	virtual int getRange() { return range; };

	void deleteProjectile();

	bool inRange;

protected:
	int range;
	bool cooldownPassed;
	Timer* cooldown;
};

#endif