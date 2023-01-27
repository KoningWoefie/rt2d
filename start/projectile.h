#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <rt2d/entity.h>
#include "enemy.h"

/// <summary>
/// projectiles that move in the direction they are looking in
/// </summary>
class Projectile : public Entity
{
public:
	/// <summary>
	/// constructor
	/// </summary>
	Projectile();

	/// <summary>
	/// destructor
	/// </summary>
	virtual ~Projectile();

	virtual void update(float deltaTime);

	/// <summary>
	/// move to targeted enemy
	/// </summary>
	/// <param name="targetPosition"></param>
	/// <param name="deltaTime"></param>
	void moveToTarget(Point3 targetPosition, float deltaTime);

	/// <summary>
	/// choose which enemy to target, this enemy is always the closest one
	/// </summary>
	/// <param name="enemies"></param>
	/// <returns></returns>
	Point3 checkClosestEnemy(std::vector<Enemy*> enemies);

	/// <summary>
	/// checks collision with the target
	/// </summary>
	/// <param name="target"></param>
	/// <returns></returns>
	int checkCollision(Point3 target);

	/// <summary>
	/// check if the projectile is out screen
	/// </summary>
	void checkIfOutOfScreen();

	/// <summary>
	/// true when projectile hits target
	/// </summary>
	bool hitTarget;
	/// <summary>
	/// true when projectile hits target or when its out of screen
	/// </summary>
	bool dead;
private:
	/// <summary>
	/// index of targeted enemy
	/// </summary>
	int index;
	/// <summary>
	/// true when out of screen
	/// </summary>
	bool outOfScreen;
	/// <summary>
	/// true when already rotated
	/// </summary>
	bool rotated;

protected:
	/// <summary>
	/// timer for the lifespan
	/// </summary>
	Timer* lifeSpanTimer;
	/// <summary>
	/// value of the lifespan
	/// </summary>
	float lifeSpan;
};

#endif