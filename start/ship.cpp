#include "ship.h"
#include <iostream>

Ship::Ship() : Enemy()
{
	this->rotation.z = PI / 2;
	velo = 0;
	localGate = nullptr;
	reachedEndPoint = false;
}

Ship::~Ship()
{

}

void Ship::update(float deltaTime)
{
	if (localGate != nullptr)
	{
		this->move(localGate, velo, deltaTime);
	}
}

void Ship::spawn(std::vector<Entity*> checkpoints, Gate* gate, Point3 spawnPosition, int speed)
{
	this->position = spawnPosition;
	_checkPoints = checkpoints;
	localGate = gate;
	velo = speed;
}
