#ifndef SHOP_H
#define SHOP_H

#include <rt2d/entity.h>
#include "omnibar.h"
#include "shopwindow.h"

class Shop : public Entity
{
public:
	Shop();

	virtual ~Shop();

	virtual void update(float deltaTime);

	Shopwindow* getShopwindow() { return shoow; };

private:
	Omnibar* omni;
	Shopwindow* shoow;
};

#endif