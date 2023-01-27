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

	/// <summary>
	/// spawns bombtower when button is pressed
	/// </summary>
	void spawnBombTower();

	/// <summary>
	/// spawns infantrytower when button is pressed
	/// </summary>
	void spawnInfantryTower();

private:
	/// <summary>
	/// wave of enemies
	/// </summary>
	Wave* wave;
	
	/// <summary>
	/// exitgate/endposition
	/// </summary>
	Gate* exitGate;
	/// <summary>
	/// entrygate/startposition
	/// </summary>
	Gate* entryGate;

	/// <summary>
	/// first enemy that spawns for path generation
	/// </summary>
	Enemy* fastEnemy;

	/// <summary>
	/// grid that you can place towers in
	/// </summary>
	Grid* grid;

	/// <summary>
	/// the thing in the grid
	/// </summary>
	Tile* tile;

	Hud* hud;

	/// <summary>
	/// timer
	/// </summary>
	Timer* t;

	/// <summary>
	/// first button in shop
	/// </summary>
	ImageButton* button1;
	/// <summary>
	/// second button in shop
	/// </summary>
	ImageButton* button2;

	/// <summary>
	/// true when the entrygate has the correct x position
	/// </summary>
	bool entryGatePosXMade;
	/// <summary>
	/// true when the entrygate has the correct x position
	/// </summary>
	bool exitGatePosXMade;
	/// <summary>
	/// true when wave is already made and false when new wave needs to be made
	/// </summary>
	bool waveMade;
	/// <summary>
	/// true when timer already started
	/// </summary>
	bool timerStarted;
	
	float mousePosX;
	float mousePosY;

	/// <summary>
	/// list of all active towers
	/// </summary>
	std::vector<Tower*> towers;
	/// <summary>
	/// list of all checkpoints
	/// </summary>
	std::vector<Entity*> cps;

	/// <summary>
	/// loading screen (displayed when path is generating)
	/// </summary>
	BasicEntity* loadingScreen;
	/// <summary>
	/// background for the loading screen
	/// </summary>
	BasicEntity* background;

	BasicEntity* cp1;
	BasicEntity* cp2;
	BasicEntity* cp3;
	BasicEntity* cp4;
	BasicEntity* cp5;
	BasicEntity* cp6;

	/// <summary>
	/// enemies per wave increases 5 per time
	/// </summary>
	int enemiesPerWave;

	/// <summary>
	/// true when you lost
	/// </summary>
	bool ended;

	/// <summary>
	/// value of the enemyspeed
	/// </summary>
	int enemySpeed;
	/// <summary>
	/// current wave number
	/// </summary>
	int waveNumber;
};				 

#endif /* SCENE00_H */
