#ifndef TILE_H
#define TILE_H

#include <rt2d/entity.h>

class Tile : public Entity
{
public:
	Tile();

	virtual ~Tile();

	virtual void update(float deltaTime);

	bool open;

private:

};

#endif