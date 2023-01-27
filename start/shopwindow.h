#ifndef SHOPWINDOW_H
#define SHOPWINDOW_H

#include <rt2d/entity.h>
#include "imagebutton.h"
#include "tower.h"

/// <summary>
/// window where the buttons are being displayed
/// </summary>
class Shopwindow : public Entity
{
public:
	/// <summary>
	/// constructor
	/// </summary>
	/// <param name="spawnPos"></param>
	Shopwindow(Point3 spawnPos);

	/// <summary>
	/// destructor
	/// </summary>
	virtual ~Shopwindow();

	virtual void update(float deltaTime);

	/// <summary>
	/// list of all buttons in the shopwindow
	/// </summary>
	std::vector<ImageButton*> imgButtons;

private:
};

#endif