#include "bomb.h"

Bomb::Bomb() : Projectile()
{
	this->addSprite("assets/Bomb.tga");
	lifeSpanTimer->start();
}

Bomb::~Bomb()
{

}

void Bomb::update(float deltaTime)
{
	checkIfOutOfScreen();
	if (lifeSpanTimer->seconds() >= lifeSpan)
	{
		dead = true;
		lifeSpanTimer->stop();
	}
}
