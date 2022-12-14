#ifndef OMNIBAR_H
#define OMNIBAR_H

#include <rt2d/entity.h>

class Omnibar : public Entity
{
public:
	Omnibar();

	virtual ~Omnibar();

	void moveWithMouseWhenClicked();

	virtual void update(float deltaTime);

	bool hovered;

private:

};

#endif