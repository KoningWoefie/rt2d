#include "gate.h"

Gate::Gate() : Entity()
{
	this->addSprite("assets/square.tga");
	this->sprite()->color = WHITE;
}

Gate::~Gate()
{

}

void Gate::update(float deltaTime)
{

}
