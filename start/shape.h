/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file myentity.h
 *
 * @brief description of MyEntity behavior.
 */

#ifndef MYENTITY_H
#define MYENTITY_H

#include <rt2d/entity.h>

/// @brief The MyEntity class is the Entity implementation.
class Shape : public Entity
{
public:

	Shape();

	virtual ~Shape();

	virtual void update(float deltaTime);

private:
};

#endif
