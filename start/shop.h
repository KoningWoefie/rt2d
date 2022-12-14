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

	bool checkIfHovered();

	Shopwindow* getShopwindow() { return shoow; };

	int GetWidth() { return width; };

	int GetHeight() { return height; };

	Point3 GetRealPos() { return realPos; };

private:
	Omnibar* omni;
	Shopwindow* shoow;

	int width;
	int height;
	Point3 realPos;
};

#endif