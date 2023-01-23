#ifndef BAR_H
#define BAR_H

#include <rt2d/entity.h>
#include "basicentity.h"
#include "gate.h"

class Bar : public Entity
{
public:
	Bar(int health, Gate* endGate);
	virtual ~Bar();

	virtual void update(float deltaTime);

private:
	/* add your private declarations */
	BasicEntity* greenBar;
	BasicEntity* redBar;

	Gate* _endGate;

	int _health;
};

#endif /* BASICENTITY_H */