#include "infantrytower.h"

Infantrytower::Infantrytower() : Tower()
{
	this->addSprite("assets/infantrytower.tga");
	range = 1500;
	cooldownPassed = false;
	cooldown = new Timer();
	cooldown->start();
}

Infantrytower::~Infantrytower()
{

}

void Infantrytower::update(float deltaTime)
{

}

void Infantrytower::spawnProjectile()
{
	if (cooldown->seconds() > 1)
	{
		cooldownPassed = true;
	}
	if (!projectileSpawned && cooldownPassed)
	{
		projectile = new Bullet();
		projectile->position = this->position;
		projectileSpawned = true;
		cooldown->stop();
		cooldown->start();
		cooldownPassed = false;
	}
}
