#include "bombtower.h"

Bombtower::Bombtower() : Tower()
{
	this->addSprite("assets/BombTower.tga");
	rangeCircle = new Shape();
	Line c1;
	c1.createCircle(512, 18);
	range = 256;
	rangeCircle->addLine(&c1);
	this->addChild(rangeCircle);
	cooldownPassed = false;
	cooldown = new Timer();
	cooldown->start();
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
	if (cooldown->seconds() > 0.7f)
	{
		cooldownPassed = true;
	}
	if (!projectileSpawned && cooldownPassed)
	{
		projectile = new Bomb();
		projectile->position = this->position;
		projectileSpawned = true;
		cooldown->stop();
		cooldown->start();
		cooldownPassed = false;
	}
}
