#include "enemy.h"
#include <iostream>

Enemy::Enemy() : Entity()
{
	this->addSprite("assets/BombTower.tga");
	this->rotation.z = PI;
	this->sprite()->color = WHITE;
	velo = 0;
}

Enemy::~Enemy()
{

}

void Enemy::update(float deltaTime)
{
	this->move(TargetPosition, velo, deltaTime);
}

void Enemy::move(Point3 targetPosition, int speed, float deltaTime)
{
	if (this->position.x <= targetPosition.x || this->position.y != targetPosition.y)
	{
		this->position.x += speed * deltaTime;
	}
}

void Enemy::spawn(Point3 targetPosition, Point3 spawnPosition, int speed)
{
	this->position = spawnPosition;
	TargetPosition = targetPosition;
	velo = speed;
}
