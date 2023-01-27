#include "tile.h"

Tile::Tile() : Entity()
{
	this->addSprite("assets/water.tga");
	this->scale = Point(0.5, 0.5);
	this->sprite()->color = WHITE;
}

Tile::~Tile()
{

}

void Tile::update(float deltaTime)
{

}
