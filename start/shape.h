/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file myentity.h
 *
 * @brief description of MyEntity behavior.
 */

#ifndef SHAPE_H
#define SHAPE_H

#include <rt2d/entity.h>

/// <summary>
/// for displaying shapes
/// </summary>
class Shape : public Entity
{
public:
	/// <summary>
	/// constructor
	/// </summary>
	Shape();

	/// <summary>
	/// destructor
	/// </summary>
	virtual ~Shape();

	virtual void update(float deltaTime);

private:
};

#endif
