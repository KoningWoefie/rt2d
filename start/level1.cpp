/**
 * This class describes Level1 behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include <iostream>
#include <fstream>
#include <sstream>

#include "level1.h"


Level1::Level1() : Scene()
{
	entryGatePosXMade = false;
	exitGatePosXMade = false;
	waveMade = false;
	timerStarted = false;

	tile = nullptr;
	wave = nullptr;

	mousePosX = 0;
	mousePosY = 0;

	enemiesPerWave = 10;

	//create two gates and an enemy at the position of the entrygate
	exitGate = new Gate(1100);
	exitGate->position.y = SHEIGHT / 2;

	entryGate = new Gate(1000000000000000);
	entryGate->position.y = SHEIGHT / 2;

	Wave* testWave = new Wave(1, entryGate->position, exitGate->position, 10);
	fastEnemy = testWave->enemies[0];
	fastEnemy->spawn(Point3(SWIDTH,SHEIGHT/2,0), exitGate, Point3(0, SHEIGHT/2,0), 400);

	grid = new Grid(25, 35, fastEnemy);

	hud = new Hud();

	button1 = hud->getShop()->getShopwindow()->imgButtons[0];
	button2 = hud->getShop()->getShopwindow()->imgButtons[1];

	button2->addSprite("assets/infantrytower.tga");

	button1->setCallbackFunction(std::bind(&Level1::spawnBombTower, this));
	button2->setCallbackFunction(std::bind(&Level1::spawnInfantryTower, this));

	t = new Timer();

	loadingScreen = new BasicEntity();
	loadingScreen->addSprite("assets/loadingscreen.tga");
	loadingScreen->scale = Point(2, 2);
	loadingScreen->position = Point3(SWIDTH / 2, SHEIGHT / 2, 0);

	background = new BasicEntity();
	background->addSprite("assets/background.tga");
	background->scale = Point(200,20);
	background->sprite()->color = BLACK;
	background->position = Point3(SWIDTH / 2, SHEIGHT / 2, 0);

	// create the scene 'tree'
	// add the gates and enemy as a child
	this->addChild(grid);
	this->addChild(fastEnemy);
	this->addChild(exitGate);
	this->addChild(entryGate);
	this->addChild(hud);
	this->addChild(background);
	this->addChild(loadingScreen);
}


Level1::~Level1()
{
	// deconstruct and delete the Tree
	this->removeChild(exitGate);
	this->removeChild(entryGate);
	this->removeChild(grid);
	this->removeChild(hud);

	// delete the gates and enemy from the heap (there was a 'new' in the constructor)
	delete grid;
	delete wave;
	delete exitGate;
	delete entryGate;
	delete hud;
}

void Level1::update(float deltaTime)
{
	if (!grid->doneLoading)
	{
		loadingScreen->rotation.z += PI * deltaTime;
	}
	if (fastEnemy != nullptr && grid->doneLoading)
	{
		this->removeChild(fastEnemy);
		this->removeChild(loadingScreen);
		this->removeChild(background);
		delete fastEnemy;
		delete loadingScreen;
		delete background;
		fastEnemy = nullptr;
		loadingScreen = nullptr;
		background = nullptr;
	}
	grid->interactable = !hud->checkIfUIisHovered();
	//check the size of the sprite only once. Can't do this at the constructor because the sprite hasn't loaded yet
	if (exitGate->sizeOf == Point2(0, 0))
	{
		exitGate->sizeOf = exitGate->sprite()->size;
		
		//set the position so that the sprite is at the edge regardless of scale
		exitGate->position.x = SWIDTH - (exitGate->sizeOf.x * exitGate->scale.x)/2;
		exitGatePosXMade = true;
	}
	if (entryGate->sizeOf == Point2(0, 0))
	{
		entryGate->sizeOf = entryGate->sprite()->size;
		
		//set the position so that the sprite is at the edge regardless of scale
		entryGate->position.x = (entryGate->sizeOf.x * entryGate->scale.x) / 2;
		entryGatePosXMade = true;
	}
	if (grid->doneLoading)
	{
		if (entryGatePosXMade && exitGatePosXMade && !waveMade && exitGate != nullptr)
		{
			wave = new Wave(enemiesPerWave, entryGate->position, exitGate->position, 1);

			for (int i = 0; i < wave->enemies.size(); i++)
			{
				Enemy* enemy = wave->enemies[i];
				this->addChild(enemy);
				enemy->spawn(exitGate->position, exitGate, entryGate->position + Point3(-50 * i, 0, 0), 200);
			}
			enemiesPerWave += 5;
			waveMade = true;
		}
		for (Tower* tower : towers)
		{
			tower->inRange = false;
			for (int i = wave->enemies.size() - 1; i >= 0; i--)
			{
				if (wave->enemies[i]->reachedEndPoint)
				{
					this->removeChild(wave->enemies[i]);
					delete wave->enemies[i];
					wave->enemies.erase(wave->enemies.begin() + i);
				}
				if (Vector2(tower->position - wave->enemies[i]->position).getLengthSquared() < (float)(tower->getRange() * tower->getRange()))
				{
					tower->inRange = true;
				}
			}
		}

		if (exitGate != nullptr && exitGate->health <= 0)
		{
			this->removeChild(exitGate);
			/*delete exitGate;
			exitGate = nullptr;*/
		}
		if (grid->ghostTower != nullptr)
		{
			grid->ghostTower->moveWithMouse();
		}
		for (int i = towers.size() - 1; i >= 0; i--)
		{
			if (towers[i]->placed && wave->enemies.size() > 0)
			{
				int index = 0;
				if (towers[i]->inRange)
				{
					towers[i]->spawnProjectile();
				}
				if (towers[i]->projectile != nullptr)
				{
					index = towers[i]->projectile->checkCollision(towers[i]->projectile->checkClosestEnemy(wave->enemies));
					towers[i]->targetEnemy(wave->enemies[index]->position, deltaTime);
					this->addChild(towers[i]->projectile);
				}
				if (towers[i]->projectile != nullptr && towers[i]->projectile->dead)
				{
					if (towers[i]->projectile->hitTarget)
					{
						hud->money += 20;
						this->removeChild(wave->enemies[index]);
						delete wave->enemies[index];
						wave->enemies.erase(wave->enemies.begin() + index);
					}
					this->removeChild(towers[i]->projectile);
					delete towers[i]->projectile;
					towers[i]->projectile = nullptr;
					towers[i]->projectileSpawned = false;
				}
			}
			else if (wave->enemies.size() == 0 && towers[i]->projectile != nullptr)
			{
				this->removeChild(towers[i]->projectile);
				towers[i]->deleteProjectile();
			}
		}
		if (wave->enemies.size() == 0 && !timerStarted)
		{
			t->start();
			timerStarted = true;
		}
		if (t->seconds() > 4)
		{
			waveMade = false;
			t->stop();
			timerStarted = false;
		}
	}
}

void Level1::spawnBombTower()
{
	if (grid->ghostTower == nullptr && hud->money >= 40)
	{
		grid->ghostTower = new Bombtower();
		towers.push_back(grid->ghostTower);
		grid->addChild(grid->ghostTower);
		hud->money -= 40;
	}
}

void Level1::spawnInfantryTower()
{
	if (grid->ghostTower == nullptr && hud->money >= 60)
	{
		grid->ghostTower = new Infantrytower();
		towers.push_back(grid->ghostTower);
		grid->addChild(grid->ghostTower);
		hud->money -= 60;
	}
}
