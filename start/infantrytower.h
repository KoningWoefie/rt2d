#ifndef INFANTRYTOWER_H
#define INFANTRYTOWER_H

#include "tower.h"
#include "bullet.h"

class Infantrytower : public Tower
{
public:
	Infantrytower();

	virtual ~Infantrytower();

	virtual void update(float deltaTime);

	void spawnProjectile();
private:

};

#endif