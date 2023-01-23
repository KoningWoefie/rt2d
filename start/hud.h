#ifndef HUD_H
#define HUD_H

#include <rt2d/entity.h>
#include "shop.h"
#include "text.h"
#include "bar.h"
#include "gate.h"

class Hud : public Entity
{
public:
	Hud(Gate* endGate);

	virtual ~Hud();

	virtual void update(float deltaTime);

	bool checkIfUIisHovered();

	Shop* getShop() { return shop; };

	int money;
	int moneyChange;
private:
	Shop* shop;

	Text* moneyBox;
	Text* moneyChangeBox;

	Bar* healthBar;

	std::vector<Entity*> UIelements;
};

#endif