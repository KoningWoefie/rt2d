#ifndef GATE_H
#define GATE_H

#include <rt2d/entity.h>

/// <summary>
/// Can beb used as spawnpoints and end point
/// </summary>
class Gate : public Entity
{
public:
	/// <summary>
	/// constructor
	/// </summary>
	/// <param name="health"></param>
	Gate(int health);

	/// <summary>
	/// destructor
	/// </summary>
	virtual ~Gate();

	virtual void update(float deltaTime);

	/// <summary>
	/// size of the gate sprite
	/// </summary>
	Point2 sizeOf;

	/// <summary>
	/// current value of the health of the gate
	/// </summary>
	int health;
private:

};

#endif