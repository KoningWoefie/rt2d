#include "particle.h"

Particle::Particle(float rot) : Entity()
{
	this->addSprite("assets/shrapnel.tga");
	this->sprite()->color = RED;
	this->rotation.z = rot;
	t = new Timer();
	t->start();
}


Particle::~Particle()
{

}

void Particle::update(float deltaTime)
{
	this->position.x += cos(this->rotation.z) * 2000 * deltaTime;
	this->position.y += sin(this->rotation.z) * 2000 * deltaTime;
	if (t->seconds() > 0.5f)
	{
		this->parent()->removeChild(this);
		delete this;
	}
}
