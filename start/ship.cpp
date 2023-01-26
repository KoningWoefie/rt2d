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
		this->move(TargetPosition, localGate, velo, deltaTime);
	}
}

void Ship::spawn(Point3 targetPosition, Gate* gate, Point3 spawnPosition, int speed)
{
	this->position = spawnPosition;
	TargetPosition = targetPosition;
	localGate = gate;
	velo = speed;
}
