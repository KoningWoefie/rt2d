#ifndef GRID_H
#define GRID_H

#include "tile.h"
#include "tower.h"
#include "basicentity.h"


class Grid : public Entity
{
public:
	Grid(int cellAmountHeight, int cellAmountWidth, Enemy* enemy);
	~Grid();
	std::vector<Tile*> tiles;
	virtual void update(float deltaTime);
	void checkTileSelectionWithMouse();
	void pathTileGeneration(Enemy* enemy);

	bool towerSpawned;
	bool interactable;
	bool doneLoading;

	Tower* ghostTower;
	
private:
	std::vector<Tile*> pathTiles;
	Enemy* fastEnemy;
	BasicEntity* loadingScreen;
};


#endif // !GRID_H
