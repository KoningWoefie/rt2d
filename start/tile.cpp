#include "tile.h"

Tile::Tile() : Entity()
{
	this->addSprite("assets/square.tga");
	this->scale = Point(0.5, 0.5);
	this->sprite()->color = WHITE;
	open = false;
}

Tile::~Tile()
{

}

void Tile::update(float deltaTime)
{

}
