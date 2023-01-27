/**
 * This file is part of a demo that shows how to use RT2D, a 2D OpenGL framework.
 *
 * - Copyright 2015 Rik Teerling <rik@onandoffables.com>
 *     - Initial commit
 */

#ifndef PARTICLE_H
#define PARTICLE_H

#include <rt2d/entity.h>

/// <summary>
/// particles with lifetime
/// </summary>
class Particle: public Entity
{
	public:
		/// <summary>
		/// constructor
		/// </summary>
		/// <param name="rot"></param>
		Particle(float rot);

		/// <summary>
		/// destructor
		/// </summary>
		virtual ~Particle();

		virtual void update(float deltaTime);

	private:
		/// <summary>
		/// timer for lifetime
		/// </summary>
		Timer* t;
};

#endif /* BASICENTITY_H */
