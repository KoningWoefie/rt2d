#include "hud.h"

Hud::Hud() : Entity()
{
	money = 100;
	moneyBox = new Text();
	moneyBox->position = Point3(24, 36);
	shop = new Shop();
	this->addChild(shop);
	this->addChild(moneyBox);
	UIelements.push_back(shop);
	UIelements.push_back(moneyBox);
}

Hud::~Hud()
{

}

void Hud::update(float deltaTime)
{
	std::string moneyString = std::to_string(money);
	moneyBox->message(moneyString);
}

bool Hud::checkIfUIisHovered()
{
	if (shop->checkIfHovered())
	{
		return true;
	}
	return false;
}
