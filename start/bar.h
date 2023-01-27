#ifndef BAR_H
#define BAR_H

#include <rt2d/entity.h>
#include "basicentity.h"
#include "gate.h"

/// <summary>
/// makes a bar that can be used as a healthbar
/// </summary>
class Bar : public Entity
{
public:
	/// <summary>
	/// constructor
	/// </summary>
	/// <param name="health"></param>
	/// <param name="endGate"></param>
	Bar(int health, Gate* endGate);

	/// <summary>
	/// destructor
	/// </summary>
	virtual ~Bar();

	virtual void update(float deltaTime);

private:
	/// <summary>
	/// bar that scales
	/// </summary>
	BasicEntity* greenBar;
	/// <summary>
	/// background bar
	/// </summary>
	BasicEntity* redBar;

	/// <summary>
	/// endgate for health
	/// </summary>
	Gate* _endGate;

	/// <summary>
	/// maxhealth
	/// </summary>
	int _health;
};

#endif