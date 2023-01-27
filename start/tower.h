#ifndef TOWER_H
#define TOWER_H

#include <rt2d/entity.h>
#include "enemy.h"
#include "projectile.h"

/// <summary>
/// tower script with all the things a tower needs
/// </summary>
class Tower : public Entity
{
public:
	/// <summary>
	/// constructor
	/// </summary>
	Tower();

	/// <summary>
	/// destructor
	/// </summary>
	virtual ~Tower();

	virtual void update(float deltaTime);

	/// <summary>
	/// move the tower with the mouse
	/// </summary>
	void moveWithMouse();

	/// <summary>
	/// target enemy
	/// </summary>
	/// <param name="target"></param>
	/// <param name="deltaTime"></param>
	virtual void targetEnemy(Point3 target, float deltaTime);

	Projectile* projectile;

	bool projectileSpawned;

	bool placed;

	/// <summary>
	/// spawns projectile
	/// </summary>
	virtual void spawnProjectile();

	/// <returns>range</returns>
	virtual int getRange() { return range; };

	/// <summary>
	/// delete the projectile that you fired
	/// </summary>
	void deleteProjectile();

	/// <summary>
	/// bool that is true when an enemy is inrange
	/// </summary>
	bool inRange;

protected:
	/// <summary>
	/// range of the tower
	/// </summary>
	int range;
	/// <summary>
	/// true when cooldown has passed and can shoot again
	/// </summary>
	bool cooldownPassed;
	/// <summary>
	/// cooldown timer
	/// </summary>
	Timer* cooldown;
};

#endif