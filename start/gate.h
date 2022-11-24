#ifndef GATE_H
#define GATE_H

#include <rt2d/entity.h>

class Gate : public Entity
{
public:
	Gate();

	virtual ~Gate();

	virtual void update(float deltaTime);

	Point2 sizeOf;

private:

};

#endif