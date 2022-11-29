/**
 * This class describes Level1 behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include <fstream>
#include <sstream>

#include "level1.h"

Level1::Level1() : Scene()
{
	// start the timer.
	t.start();

<<<<<<< Updated upstream:start/myscene.cpp
	// create a single instance of MyEntity in the middle of the screen.
	// the Sprite is added in Constructor of MyEntity.
	myentity = new MyEntity();
	myentity->position = Point2(SWIDTH/2, SHEIGHT/2);

	// create the scene 'tree'
	// add myentity to this Scene as a child.
	this->addChild(myentity);
=======
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
>>>>>>> Stashed changes:start/level1.cpp
}


Level1::~Level1()
{
	// deconstruct and delete the Tree
<<<<<<< Updated upstream:start/myscene.cpp
	this->removeChild(myentity);

	// delete myentity from the heap (there was a 'new' in the constructor)
	delete myentity;
=======
	this->removeChild(exitGate);
	this->removeChild(entryGate);
	this->removeChild(grid);

	// delete the gates and enemy from the heap (there was a 'new' in the constructor)
	delete grid;
	delete wave;
	delete exitGate;
	delete entryGate;
>>>>>>> Stashed changes:start/level1.cpp
}

void Level1::update(float deltaTime)
{
	// ###############################################################
	// Escape key stops the Scene
	// ###############################################################
	if (input()->getKeyUp(KeyCode::Escape)) {
		this->stop();
	}

	// ###############################################################
	// Spacebar scales myentity
	// ###############################################################
	if (input()->getKeyDown(KeyCode::Space)) {
		myentity->scale = Point(0.5f, 0.5f);
	}
	if (input()->getKeyUp(KeyCode::Space)) {
		myentity->scale = Point(1.0f, 1.0f);
	}

<<<<<<< Updated upstream:start/myscene.cpp
	// ###############################################################
	// Rotate color
	// ###############################################################
	if (t.seconds() > 0.0333f) {
		RGBAColor color = myentity->sprite()->color;
		myentity->sprite()->color = Color::rotate(color, 0.01f);
		t.start();
=======
		for each (Enemy * enemy in wave->enemies)
		{
			this->addChild(enemy);
			enemy->spawn(exitGate->position, exitGate, entryGate->position + Point3(-50 * i, 0, 0), 100);
			i++;
		}
		waveMade = true;
>>>>>>> Stashed changes:start/level1.cpp
	}
	for (int i = 0; i < wave->enemies.size(); i++)
	{
		if (wave->enemies[i]->reachedEndPoint == true);
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
