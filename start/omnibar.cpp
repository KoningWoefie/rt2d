#include "omnibar.h"

Omnibar::Omnibar() : Entity()
{
	hovered = false;

	this->addSprite("assets/omnibar.tga");
	this->sprite()->color = WHITE;
	this->position = Point3(SWIDTH - 128,8, 0);
}

Omnibar::~Omnibar()
{

}

void Omnibar::update(float deltaTime)
{
	moveWithMouseWhenClicked();
}

void Omnibar::moveWithMouseWhenClicked()
{
	int mouseX = input()->getMouseX();
	int mouseY = input()->getMouseY();

	Point2 pos = Point2(this->position.x, this->position.y);

	int left = pos.x - sprite()->size.x;
	int right = pos.x + sprite()->size.x;
	int top = pos.y - sprite()->size.y;
	int bottom = pos.y + sprite()->size.y;
	if (mouseX > left && mouseX < right && mouseY > top && mouseY < bottom)
	{
		hovered = true;
		if (input()->getMouse(0))
		{
			this->position.x += mouseX - pos.x;
			this->position.y += mouseY - pos.y;
		}
	}
	else
	{
		hovered = false;
	}
}
