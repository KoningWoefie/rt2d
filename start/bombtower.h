#ifndef BOMBTOWER_H
#define BOMBTOWER_H

#include "tower.h"
#include "bomb.h"
#include "shape.h"

/// <summary>
/// tower that shoots bombs and has limited range
/// </summary>
class Bombtower : public Tower
{
public:
	/// <summary>
	/// constructor
	/// </summary>
	Bombtower();

	/// <summary>
	/// destructor
	/// </summary>
	virtual ~Bombtower();

	virtual void update(float deltaTime);

	/// <summary>
	/// spawns projectile/bomb
	/// </summary>
	virtual void spawnProjectile();

	/// <summary>
	/// returns range
	/// </summary>
	/// <returns>range</returns>
	int getRange() { return range; };

private:
	/// <summary>
	/// displays the range in the form of a circle
	/// </summary>
	Shape* rangeCircle;
	/// <summary>
	/// value of the range of the tower
	/// </summary>
	int range;
};

#endif