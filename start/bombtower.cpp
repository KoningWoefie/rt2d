#include "bombtower.h"

Bombtower::Bombtower() : Tower()
{
	this->addSprite("assets/BombTower.tga");
}

Bombtower::~Bombtower()
{

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
