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

	tile = nullptr;
	wave = nullptr;

	mousePosX = 0;
	mousePosY = 0;

	//create two gates and an enemy at the position of the entrygate
	exitGate = new Gate(1000);
	exitGate->position.y = SHEIGHT / 2;

	entryGate = new Gate(1000000000000000);
	entryGate->position.y = SHEIGHT / 2;

	grid = new Grid(15, 20);

	hud = new Hud();

	button1 = hud->getShop()->getShopwindow()->imgButtons[0];
	button2 = hud->getShop()->getShopwindow()->imgButtons[1];

	button1->setCallbackFunction(std::bind(&Level1::spawnBombTower, this));
	button2->setCallbackFunction(std::bind(&Level1::spawnInfantryTower, this));

	// create the scene 'tree'
	// add the gates and enemy as a child
	this->addChild(grid);
	this->addChild(exitGate);
	this->addChild(entryGate);
	this->addChild(hud);
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
	if (entryGatePosXMade && exitGatePosXMade && !waveMade)
	{
		int i = 0;
		wave = new Wave(10, entryGate->position, exitGate->position, 1);

		for (int i = 0; i < wave->enemies.size(); i++)
		{
			Enemy* enemy = wave->enemies[i];
			this->addChild(enemy);
			enemy->spawn(exitGate->position, exitGate, entryGate->position + Point3(-50 * i, 0, 0), 100);
		}
		waveMade = true;
	}
	for (int i = 0; i < wave->enemies.size(); i++)
	{
		if (wave->enemies[i]->reachedEndPoint)
		{
			this->removeChild(wave->enemies[i]);
			delete wave->enemies[i];
			wave->enemies.erase(wave->enemies.begin() + i);
		}
	}

	if (exitGate->health <= 0)
	{
		this->removeChild(exitGate);
		exitGate = nullptr;
		delete exitGate;
	}
	if (grid->ghostTower != nullptr)
	{
		grid->ghostTower->moveWithMouse();
	}
	for (int i = 0; i < towers.size(); i++)
	{
		if (towers[i]->placed && wave->enemies.size() > 0)
		{
			towers[i]->spawnProjectile();
			towers[i]->targetEnemy(towers[i]->projectile->checkClosestEnemy(wave->enemies), deltaTime);
			int index = towers[i]->projectile->checkCollision(towers[i]->projectile->checkClosestEnemy(wave->enemies));
			this->addChild(towers[i]->projectile);
			if (towers[i]->projectile->hitTarget)
			{
				this->removeChild(towers[i]->projectile);
				delete towers[i]->projectile;
				this->removeChild(wave->enemies[index]);
				delete wave->enemies[index];
				wave->enemies.erase(wave->enemies.begin() + index);
				towers[i]->projectile = nullptr;
				towers[i]->projectileSpawned = false;
				hud->money += 20;
			}
		}
		else if (wave->enemies.size() == 0 && towers[i]->projectile != nullptr)
		{
			this->removeChild(towers[i]->projectile);
			towers[i]->deleteProjectile();
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
