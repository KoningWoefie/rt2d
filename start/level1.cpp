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

	//create two gates and an enemy at the position of the entrygate
	exitGate = new Gate(1000);
	exitGate->position.y = SHEIGHT / 2;
	exitGate->scale = Point(0.2, 0.7);

	entryGate = new Gate(1000000000000000);
	entryGate->position.y = SHEIGHT / 2;
	entryGate->scale = Point(0.2, 0.7);

	grid = new Grid(15, 20);

	// create the scene 'tree'
	// add the gates and enemy as a child
	this->addChild(exitGate);
	this->addChild(entryGate);

	this->addChild(grid);
}


Level1::~Level1()
{
	// deconstruct and delete the Tree
	this->removeChild(exitGate);
	this->removeChild(entryGate);
	this->removeChild(grid);

	// delete the gates and enemy from the heap (there was a 'new' in the constructor)
	delete grid;
	delete wave;
	delete exitGate;
	delete entryGate;
}

void Level1::update(float deltaTime)
{
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
		wave = new Wave(10, entryGate->position, exitGate->position, 100);

		for each (Enemy * enemy in wave->enemies)
		{
			this->addChild(enemy);
			enemy->spawn(exitGate->position, exitGate, entryGate->position + Point3(-50 * i, 0, 0), 100);
			i++;
		}
		waveMade = true;
	}
	for (int i = 0; i < wave->enemies.size(); i++)
	{
		if (wave->enemies[i]->reachedEndPoint);
		{
			this->removeChild(wave->enemies[i]);
			delete wave->enemies[i];
			wave->enemies.erase(wave->enemies.begin() + i);
		}
	}

	if (exitGate->health <= 0)
	{
		this->removeChild(exitGate);
	}
}
