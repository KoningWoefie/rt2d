#ifndef HUD_H
#define HUD_H

#include <rt2d/entity.h>
#include "shop.h"
#include "text.h"
#include "bar.h"
#include "gate.h"

/// <summary>
/// handles all UI elements
/// </summary>
class Hud : public Entity
{
public:
	/// <summary>
	/// constructor
	/// </summary>
	/// <param name="endGate"></param>
	Hud(Gate* endGate);

	/// <summary>
	/// destructor
	/// </summary>
	virtual ~Hud();

	virtual void update(float deltaTime);

	/// <summary>
	/// check if the mouse is over the UI.
	/// </summary>
	/// <returns>bool</returns>
	bool checkIfUIisHovered();


	/// <summary>
	/// get shop
	/// </summary>
	/// <returns>shop</returns>
	Shop* getShop() { return shop; };

	/// <summary>
	/// set the wavecounter on the top of the screen
	/// </summary>
	/// <param name="waveNumber"></param>
	void setWaveCounter(int waveNumber) { waveCounter->message("wave: " + std::to_string(waveNumber)); }

	/// <summary>
	/// money in the bank
	/// </summary>
	int money;
	/// <summary>
	/// money currently in escrow
	/// </summary>
	int moneyChange;
private:
	/// <summary>
	/// shop in the right part of the screen
	/// </summary>
	Shop* shop;

	/// <summary>
	/// displays money in the bank
	/// </summary>
	Text* moneyBox;
	/// <summary>
	/// displays money in escrow
	/// </summary>
	Text* moneyChangeBox;
	/// <summary>
	/// displays wavenumber
	/// </summary>
	Text* waveCounter;

	Bar* healthBar;

	/// <summary>
	/// list of all UI elements
	/// </summary>
	std::vector<Entity*> UIelements;
};

#endif