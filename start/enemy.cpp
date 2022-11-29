#include "enemy.h"
#include <iostream>

Enemy::Enemy() : Entity()
{
	this->addSprite("assets/BombTower.tga");
	this->rotation.z = PI;
	this->sprite()->color = WHITE;
	velo = 0;
	reachedEndPoint = false;
}

Enemy::~Enemy()
{

}

void Enemy::update(float deltaTime)
{
	this->move(TargetPosition, localGate, velo, deltaTime);
}

void Enemy::move(Point3 targetPosition, Gate* gate, int speed, float deltaTime)
{
	if (this->position.x <= targetPosition.x || this->position.y != targetPosition.y)
	{
		this->position.x += speed * deltaTime;
	}
	else
	{
		gate->health -= 100;
		reachedEndPoint = true;
	}
}

void Enemy::spawn(Point3 targetPosition, Gate* gate, Point3 spawnPosition, int speed)
{
	this->position = spawnPosition;
	TargetPosition = targetPosition;
	localGate = gate;
	velo = speed;
}
