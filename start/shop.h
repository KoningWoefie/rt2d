#ifndef SHOP_H
#define SHOP_H

#include <rt2d/entity.h>
#include "omnibar.h"
#include "shopwindow.h"

/// <summary>
/// class that combines the omnibar and shopwindow
/// </summary>
class Shop : public Entity
{
public:
	/// <summary>
	/// constructor
	/// </summary>
	Shop();

	/// <summary>
	/// destructor
	/// </summary>
	virtual ~Shop();

	virtual void update(float deltaTime);

	/// <summary>
	/// checks if the shop is hovered with the mouse
	/// </summary>
	/// <returns>bool</returns>
	bool checkIfHovered();

	/// <returns>shopwindow</returns>
	Shopwindow* getShopwindow() { return shoow; };

	/// <returns>width</returns>
	int GetWidth() { return width; };

	/// <returns>height</returns>
	int GetHeight() { return height; };

	
	/// <returns>realpos</returns>
	Point3 GetRealPos() { return realPos; };

private:
	/// <summary>
	/// bar thats at the top that you can move
	/// </summary>
	Omnibar* omni;

	/// <summary>
	/// where the buttons are
	/// </summary>
	Shopwindow* shoow;

	int width;
	int height;

	/// <summary>
	/// world position
	/// </summary>
	Point3 realPos;
};

#endif