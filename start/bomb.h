#ifndef BOMB_H
#define BOMB_H

#include "projectile.h"

/// <summary>
/// projectile fired by the bombtower
/// </summary>
class Bomb : public Projectile
{
public:
	/// <summary>
	/// constructor
	/// </summary>
	Bomb();

	/// <summary>
	/// destructor
	/// </summary>
	virtual ~Bomb();

	virtual void update(float deltaTime);

private:

};

#endif