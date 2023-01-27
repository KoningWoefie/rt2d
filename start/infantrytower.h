#ifndef INFANTRYTOWER_H
#define INFANTRYTOWER_H

#include "tower.h"
#include "bullet.h"

/// <summary>
/// tower that fires bullets and has infinite range
/// </summary>
class Infantrytower : public Tower
{
public:
	/// <summary>
	/// constructor
	/// </summary>
	Infantrytower();

	/// <summary>
	/// destructor
	/// </summary>
	virtual ~Infantrytower();

	virtual void update(float deltaTime);

	/// <summary>
	/// spawns a projectile/bullet
	/// </summary>
	void spawnProjectile();

private:

};

#endif