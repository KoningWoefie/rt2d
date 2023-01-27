/**
 * This file is part of a demo that shows how to use RT2D, a 2D OpenGL framework.
 *
 * - Copyright 2015 Rik Teerling <rik@onandoffables.com>
 *     - Initial commit
 */

#ifndef BASICENTITY_H
#define BASICENTITY_H

#include <rt2d/entity.h>

/// <summary>
/// Just an entity script you can use
/// </summary>
class BasicEntity: public Entity
{
	public:
		/// <summary>
		/// constructor
		/// </summary>
		BasicEntity();

		/// <summary>
		/// detructor
		/// </summary>
		virtual ~BasicEntity();

		virtual void update(float deltaTime);

	private:
};

#endif /* BASICENTITY_H */
