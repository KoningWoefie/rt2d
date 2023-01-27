#ifndef TILE_H
#define TILE_H

#include <rt2d/entity.h>

/// <summary>
/// square tile that is made in a grid pattern
/// </summary>
class Tile : public Entity
{
public:
	/// <summary>
	/// constructor
	/// </summary>
	Tile();

	/// <summary>
	/// destructor
	/// </summary>
	virtual ~Tile();

	virtual void update(float deltaTime);

private:

};

#endif