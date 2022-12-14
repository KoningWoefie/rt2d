#include "gate.h"

Gate::Gate(int givenHealth) : Entity()
{
	this->addSprite("assets/gate.tga");
	health = givenHealth;
}

Gate::~Gate()
{

}

void Gate::update(float deltaTime)
{

}
