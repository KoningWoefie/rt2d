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

	void targetEnemy(Point3 target, float deltaTime);

	Projectile* projectile;

	bool projectileSpawned;

	bool placed;

	void spawnProjectile();

private:
};

#endif