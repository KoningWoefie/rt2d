#include "infantrytower.h"

Infantrytower::Infantrytower() : Tower()
{
	this->addSprite("assets/infantrytower.tga");
	range = 1000;
}

Infantrytower::~Infantrytower()
{

}

void Infantrytower::update(float deltaTime)
{

}

void Infantrytower::spawnProjectile()
{
	if (!projectileSpawned)
	{
		projectile = new Bullet();
		projectile->position = this->position;
		projectileSpawned = true;
	}
}
