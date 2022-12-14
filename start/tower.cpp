#include "tower.h"

Tower::Tower() : Entity()
{
	this->addSprite("assets/infantrytower.tga");
	this->sprite()->color = WHITE;
	this->scale = Point(0.5, 0.5);
	this->projectile = nullptr;
	this->projectileSpawned = false;
	this->placed = false;
}

Tower::~Tower()
{

}

void Tower::update(float deltaTime)
{

}

void Tower::moveWithMouse()
{
	this->position = Point3(input()->getMouseX(), input()->getMouseY(), 0);
}

void Tower::targetEnemy(Point3 targetPosition, float deltaTime)
{
	projectile->moveToTarget(targetPosition, deltaTime);
}

void Tower::spawnProjectile()
{
}

void Tower::deleteProjectile()
{
	projectile = nullptr;
	delete projectile;
}