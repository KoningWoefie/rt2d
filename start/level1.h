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
#include "basicentity.h"

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

	Enemy* fastEnemy;

	Grid* grid;

	///
	Tile* tile;

	Hud* hud;

	Timer* t;

	ImageButton* button1;
	ImageButton* button2;

	bool entryGatePosXMade;
	bool exitGatePosXMade;
	bool waveMade;
	bool timerStarted;
	
	float mousePosX;
	float mousePosY;

	std::vector<Tower*> towers;

	BasicEntity* loadingScreen;
	BasicEntity* background;

	int enemiesPerWave;

	bool ended;
	int enemySpeed;
};				 

#endif /* SCENE00_H */
