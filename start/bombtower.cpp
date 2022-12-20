#include "bombtower.h"

Bombtower::Bombtower() : Tower()
{
	this->addSprite("assets/BombTower.tga");
	rangeCircle = new Shape();
	Line c1;
	c1.createCircle(512, 18);
	rangeCircle->addLine(&c1);
	this->addChild(rangeCircle);
}

Bombtower::~Bombtower()
{
	this->removeChild(rangeCircle);
	delete rangeCircle;
}

void Bombtower::update(float deltaTime)
{
}

void Bombtower::spawnProjectile()
{
	if (!projectileSpawned)
	{
		projectile = new Bomb();
		projectile->position = this->position;
		projectileSpawned = true;
	}
}
