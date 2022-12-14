#ifndef BOMB_H
#define BOMB_H

#include "projectile.h"

class Bomb : public Projectile
{
public:
	Bomb();

	virtual ~Bomb();

	virtual void update(float deltaTime);

private:

};

#endif