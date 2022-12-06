#include "gate.h"

Gate::Gate(int givenHealth) : Entity()
{
	this->addSprite("assets/square.tga");
	this->sprite()->color = WHITE;
	health = givenHealth;
}

Gate::~Gate()
{

}

void Gate::update(float deltaTime)
{

}
