/**
 * Copyright 2023 Sander Hoving <sander@hdms.nl>
 *
 * @brief Description of Barco.
 *
 * @file main.cpp
 *
 * @mainpage Barco
 *
 * @section intro Introduction
 *
 * This is a communist tower defense game, where you play as Josef Jalin the mayor of Navis. You have to defend Navis from those pesky "rebels" with two different towers filled with forced volunteers.
 * 
 * Inspired by the game Navis by the group CGB.
 *
 * Made by Sander Hoving in the RT2D framework.
 */
#include <rt2d/core.h>

#include "level1.h"

/// @brief main entry point
int main( void )
{
	// Core instance
	Core core;

	// Scene01
	Level1* level1 = new Level1(); // create Scene on the heap
	while(level1->isRunning()) { // check status of Scene every frame
		core.run(level1); // update and render the current scene
		core.showFrameRate(5); // show framerate in output every n seconds
	}
	//core.cleanup(); // cleanup ResourceManager (Textures + Meshes, but not Shaders)
	delete level1; // delete Scene and everything in it from the heap to make space for next Scene

	// No need to explicitly clean up the core.
	// As a local var, core will go out of scope and destroy Renderer->ResourceManager.
	// ResourceManager destructor also deletes Shaders.

	return 0;
}
