#include "shopwindow.h"

Shopwindow::Shopwindow(Point3 spawnPos) : Entity()
{
	this->addSprite("assets/bg_shop.tga");
	this->position = Point3(spawnPos.x, spawnPos.y + 264, 0);

	for (int i = 0; i < 2; i++)
	{
		ImageButton* imgbutt = new ImageButton("");
		imgbutt->addSprite("assets/BombTower.tga");
		imgbutt->position = Point3(-64 + i * 128, -192);
		imgButtons.push_back(imgbutt);
		this->addChild(imgbutt);
	}
}

Shopwindow::~Shopwindow()
{

}

void Shopwindow::update(float deltaTime)
{

}
