#ifndef BULLET_H
#define BULLET_H

#include "projectile.h"

class Bullet : public Projectile
{
public:
	Bullet();

	virtual ~Bullet();

	virtual void update(float deltaTime);

private:

};

#endif