#include "shop.h"

Shop::Shop() : Entity()
{
	realPos = Point3(0, 0, 0);
	width = 0;
	height = 0;
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
	realPos = omni->position;
	shoow->position = Point3(omni->position.x, omni->position.y + 264, 0);
	if (width == 0)
	{
		width = omni->sprite()->size.x;
	}
	if (height == 0)
	{
		height = omni->sprite()->size.y + shoow->sprite()->size.y;
	}
}

bool Shop::checkIfHovered()
{
	float mouseX = input()->getMouseX();
	float mouseY = input()->getMouseY();

	int left = realPos.x - width/2;
	int right = realPos.x + width/2;
	int top = realPos.y - omni->sprite()->size.y /2;
	int bottom = realPos.y + (shoow->sprite()->size.y - omni->sprite()->size.y / 2);
	if (mouseX > left && mouseX < right && mouseY > top && mouseY < bottom)
	{
		return true;
	}
	return false;
}
