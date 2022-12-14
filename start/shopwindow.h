#ifndef SHOPWINDOW_H
#define SHOPWINDOW_H

#include <rt2d/entity.h>
#include "imagebutton.h"
#include "tower.h"

class Shopwindow : public Entity
{
public:
	Shopwindow(Point3 spawnPos);

	virtual ~Shopwindow();

	virtual void update(float deltaTime);

	std::vector<ImageButton*> imgButtons;

private:
	Point3 _pos;
};

#endif