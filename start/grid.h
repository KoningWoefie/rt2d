#ifndef GRID_H
#define GRID_H

#include "tile.h"
#include "tower.h"
#include "basicentity.h"

/// <summary>
/// makes a grid in a single dimension array
/// </summary>
class Grid : public Entity
{
public:
	/// <summary>
	/// constructor
	/// </summary>
	/// <param name="cellAmountHeight"></param>
	/// <param name="cellAmountWidth"></param>
	/// <param name="enemy"></param>
	Grid(int cellAmountHeight, int cellAmountWidth, Enemy* enemy);

	/// <summary>
	/// destructor
	/// </summary>
	~Grid();

	/// <summary>
	/// list of all active tiles in script
	/// </summary>
	std::vector<Tile*> tiles;


	virtual void update(float deltaTime);

	/// <summary>
	/// check which tile is selected by the mouse
	/// </summary>
	void checkTileSelectionWithMouse();

	/// <summary>
	/// generates path
	/// </summary>
	/// <param name="enemy"></param>
	void pathTileGeneration(Enemy* enemy);

	/// <summary>
	/// true when tower has spawned
	/// </summary>
	bool towerSpawned;
	/// <summary>
	/// true when not hovered over UI
	/// </summary>
	bool interactable;
	/// <summary>
	/// true when path generation is done
	/// </summary>
	bool doneLoading;

	/// <summary>
	/// tower that is currently following the mouse
	/// </summary>
	Tower* ghostTower;
	
private:
	/// <summary>
	/// list of all pathtiles
	/// </summary>
	std::vector<Tile*> pathTiles;
	/// <summary>
	/// enemy for path generation
	/// </summary>
	Enemy* fastEnemy;
};


#endif // !GRID_H
