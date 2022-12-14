#include "enemy.h"
#include <iostream>

Enemy::Enemy() : Entity()
{
	this->addSprite("assets/ship.tga");
	this->sprite()->color = WHITE;
	this->rotation.z = PI / 2;
	velo = 0;
	localGate = nullptr;
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
	Vector2 length = Vector2(this->position.x - targetPosition.x, this->position.y - targetPosition.y);
	if (length.getLength() > 1)
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
