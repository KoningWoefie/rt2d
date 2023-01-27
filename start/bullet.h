#ifndef BULLET_H
#define BULLET_H

#include "projectile.h"

/// <summary>
/// projectile fired by the infantrytower 
/// </summary>
class Bullet : public Projectile
{
public:
	/// <summary>
	/// constructor
	/// </summary>
	Bullet();

	/// <summary>
	/// destructor
	/// </summary>
	virtual ~Bullet();

	virtual void update(float deltaTime);

private:

};

#endif