/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file Level1.h
 *
 * @brief description of Level1 behavior.
 */

#ifndef LEVEL1_H
#define LEVEL1_H

#include <rt2d/scene.h>
#include "myentity.h"
#include "enemy.h"
#include "gate.h"
#include "wave.h"
#include "tile.h"
#include "grid.h"
#include "imagebutton.h"
#include "tower.h"
#include "bombtower.h"
#include "infantrytower.h"
#include "hud.h"
#include "imagebutton.h"

/// @brief The Level1 class is the Scene implementation.
class Level1 : public Scene
{
public:
	/// @brief Constructor
	Level1();
	/// @brief Destructor
	virtual ~Level1();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

	void spawnBombTower();

	void spawnInfantryTower();

private:
	Wave* wave;
	
	///
	Gate* exitGate;
	Gate* entryGate;

	Grid* grid;

	///
	Tile* tile;

	Hud* hud;

	ImageButton* button1;
	ImageButton* button2;

	bool entryGatePosXMade;
	bool exitGatePosXMade;
	bool waveMade;
	
	float mousePosX;
	float mousePosY;

	std::vector<Tower*> towers;
};				 

#endif /* SCENE00_H */
