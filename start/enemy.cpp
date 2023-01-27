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
	checkPointReached = false;
}

Enemy::~Enemy()
{

}

void Enemy::update(float deltaTime)
{
	if (localGate != nullptr)
	{
		this->move(localGate, velo, deltaTime);
	}
}

void Enemy::move(Gate* gate, int speed, float deltaTime)
{
	Point3 targetPosition = _checkPoints[0]->position;
	Vector2 length = Vector2(this->position.x - targetPosition.x, this->position.y - targetPosition.y);
	if (length.getLength() < 10 && _checkPoints.size() == 1)
	{
		gate->health -= 100;
		reachedEndPoint = true;
	}
	else if(length.getLength() < 10)
	{
		checkPointReached = true;
		_checkPoints.erase(_checkPoints.begin());
	}
	else
	{
		if (abs(_checkPoints[0]->position.y - this->position.y) > abs(_checkPoints[0]->position.x - this->position.x))
		{
			if (_checkPoints[0]->position.y - this->position.y > 0)
			{
				this->position.y += speed * deltaTime;
			}
			else
			{
				this->position.y -= speed * deltaTime;
			}
		}
		else
		{
			if (_checkPoints[0]->position.x - this->position.x > 0)
			{
				this->position.x += speed * deltaTime;
			}
			else
			{
				this->position.x -= speed * deltaTime;
			}
		}
	}
}

void Enemy::spawn(std::vector<Entity*> checkpoints, Gate* gate, Point3 spawnPosition, int speed)
{
}
