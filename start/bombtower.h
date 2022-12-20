#ifndef BOMBTOWER_H
#define BOMBTOWER_H

#include "tower.h"
#include "bomb.h"
#include "shape.h"

class Bombtower : public Tower
{
public:
	Bombtower();

	virtual ~Bombtower();

	virtual void update(float deltaTime);

	virtual void spawnProjectile();

private:
	Shape* rangeCircle;
};

#endif