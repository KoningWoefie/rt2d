#include "grid.h"

Grid::Grid(int cellAmountHeight, int cellAmountWidth)
{
	ghostTower = nullptr;
	towerSpawned = false;
	interactable = true;
	for (int y = 0; y < cellAmountHeight; y++)
	{
		for (int x = 0; x < cellAmountWidth; x++)
		{
			Tile* tile = new Tile();
			tile->position = Point3(64 * x + 32, 64 * y + 32, 0);
			tiles.push_back(tile);
			this->addChild(tile);
		}
	}
}

Grid::~Grid()
{
	for (int i = 0; i < tiles.size(); i++)
	{
		this->removeChild(tiles[i]);
		delete tiles[i];
	}
	tiles.clear();
}

void Grid::update(float deltaTime)
{
	if (tiles.size() != 0)
	{
		checkTileSelectionWithMouse();
	}
}

void Grid::checkTileSelectionWithMouse()
{
	for (int i = 0; i < tiles.size(); i++)
	{
		Tile* tile = tiles[i];
		float mousePosX = input()->getMouseX();
		float mousePosY = input()->getMouseY();
		float xPos = tiles[i]->position.x;
		float yPos = tiles[i]->position.y;

		float top = yPos - 32;
		float bottom = yPos + 32;
		float left = xPos - 32;
		float right = xPos + 32;
		if ((mousePosX > left && mousePosX < right && mousePosY > top && mousePosY < bottom) && interactable)
		{
			tile->sprite()->color = RED;
			if (input()->getMouseDown(0))
			{
				tile->sprite()->color = BLUE;
				if (ghostTower != nullptr)
				{
					ghostTower->position = tile->position;
					ghostTower->placed = true;
					ghostTower = nullptr;
				}
				this->removeChild(tile);
				tiles.erase(tiles.begin() + i);
			}
		}
		else
		{
			tile->sprite()->color = WHITE;
		}
	}
}