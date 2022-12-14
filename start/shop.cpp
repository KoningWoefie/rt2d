#include "shop.h"

Shop::Shop() : Entity()
{
	omni = new Omnibar();
	shoow = new Shopwindow(omni->position);
	this->addChild(omni);
	this->addChild(shoow);
}

Shop::~Shop()
{
	this->removeChild(shoow);
	this->removeChild(omni);
}

void Shop::update(float deltaTime)
{
	shoow->position = Point3(omni->position.x, omni->position.y + 264, 0);
}
