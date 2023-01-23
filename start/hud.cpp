#include "hud.h"

Hud::Hud(Gate* endGate) : Entity()
{
	money = 100;
	moneyChange = 0;
	moneyBox = new Text();
	moneyBox->position = Point3(24, 36);
	moneyChangeBox = new Text();
	moneyChangeBox->position = Point3(60, 72);
	moneyChangeBox->scale = Point(0.5f, 0.5f);
	shop = new Shop();
	healthBar = new Bar(1000, endGate);
	this->addChild(shop);
	this->addChild(moneyBox);
	this->addChild(moneyChangeBox);
	this->addChild(healthBar);
	UIelements.push_back(shop);
	UIelements.push_back(moneyBox);
	UIelements.push_back(moneyChangeBox);
	UIelements.push_back(healthBar);
}

Hud::~Hud()
{

}

void Hud::update(float deltaTime)
{
	std::string moneyString = std::to_string(money);
	moneyBox->message(moneyString);
	if (moneyChange > 0)
	{
		std::string moneyChangeString = "+" + std::to_string(moneyChange);
		moneyChangeBox->message(moneyChangeString);
		money += 1;
		moneyChange -= 1;
	}
	else
	{
		moneyChangeBox->message("");
	}
}

bool Hud::checkIfUIisHovered()
{
	if (shop->checkIfHovered())
	{
		return true;
	}
	return false;
}
