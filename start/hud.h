#ifndef HUD_H
#define HUD_H

#include <rt2d/entity.h>
#include "shop.h"
#include "text.h"

class Hud : public Entity
{
public:
	Hud();

	virtual ~Hud();

	virtual void update(float deltaTime);

	Shop* getShop() { return shop; };

	int money;
private:
	Shop* shop;

	Text* moneyBox;
};

#endif