#include "hud.h"

Hud::Hud() : Entity()
{
	money = 0;
	moneyBox = new Text();
	moneyBox->position = Point3(24, SHEIGHT - 24);
	shop = new Shop();
	this->addChild(shop);
	this->addChild(moneyBox);
}

Hud::~Hud()
{

}

void Hud::update(float deltaTime)
{
	std::string moneyString = std::to_string(money);
	moneyBox->message(moneyString);
}
