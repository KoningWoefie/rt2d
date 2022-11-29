#ifndef GRID_H
#define GRID_H

#include "tile.h"


class Grid : public Entity
{
public:
	Grid(int cellAmountHeight, int cellAmountWidth);
	~Grid();
	std::vector<Tile*> tiles;
	virtual void update(float deltaTime);
	void checkTileSelectionWithMouse();
	
private:

};


#endif // !GRID_H
