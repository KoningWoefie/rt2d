#include "explosivebarrel.h"
#include <iostream>

ExplosiveBarrel::ExplosiveBarrel() : Enemy()
{
	this->addSprite("assets/explosivebarrel.tga");
	this->rotation.z = 0;
	velo = 0;
	localGate = nullptr;
	reachedEndPoint = false;
}

ExplosiveBarrel::~ExplosiveBarrel()
{

}

void ExplosiveBarrel::update(float deltaTime)
{
	if (localGate != nullptr)
	{
		this->move(TargetPosition, localGate, velo, deltaTime);
	}
}

void ExplosiveBarrel::spawn(Point3 targetPosition, Gate* gate, Point3 spawnPosition, int speed)
{
	this->position = spawnPosition;
	TargetPosition = targetPosition;
	localGate = gate;
	velo = speed;
}
