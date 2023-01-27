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
	for(int i = 0; i <= 50; i++)
	{
		Particle* p = new Particle(2*PI/50*i);
		this->parent()->addChild(p);
		p->position = this->position;
		p = nullptr;
	}
}

void ExplosiveBarrel::update(float deltaTime)
{
	if (localGate != nullptr)
	{
		this->move(localGate, velo, deltaTime);
	}
}

void ExplosiveBarrel::spawn(std::vector<Entity*> checkpoints, Gate* gate, Point3 spawnPosition, int speed)
{
	this->position = spawnPosition;
	_checkPoints = checkpoints;
	localGate = gate;
	velo = speed;
}
