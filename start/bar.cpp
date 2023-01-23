#include "bar.h"

Bar::Bar(int health, Gate* endGate) : Entity()
{
	//maximum health of gate
	_health = health;
	//gate pointer for the health of the gate
	_endGate = endGate;

	//make green(health) bar
	greenBar = new BasicEntity();
	greenBar->addSprite("assets/background.tga");
	greenBar->scale = Point(8, 0.4f);
	greenBar->sprite()->pivot = Point(0, 0);
	greenBar->sprite()->color = GREEN;

	//make red(damage) bar
	redBar = new BasicEntity();
	redBar->addSprite("assets/background.tga");
	redBar->scale = Point(8, 0.4f);
	redBar->sprite()->pivot = Point(0, 0);
	redBar->sprite()->color = RED;

	//add them as child and give them positions
	this->addChild(redBar);
	redBar->position = Point3(SWIDTH - 128 * 4, SHEIGHT - 38, 0);
	this->addChild(greenBar);
	greenBar->position = Point3(SWIDTH - 128 * 4, SHEIGHT - 38, 0);
}


Bar::~Bar()
{

}

void Bar::update(float deltaTime)
{
	if (_endGate->health >= 0)
	{
		greenBar->scale = Point(((float)_endGate->health / 1000) * 8, 0.4f);
	}
}