/**
 * This file is part of a demo that shows how to use RT2D, a 2D OpenGL framework.
 *
 * - Copyright 2015 Rik Teerling <rik@onandoffables.com>
 *     - Initial commit
 */

#ifndef PARTICLE_H
#define PARTICLE_H

#include <rt2d/entity.h>

class Particle: public Entity
{
	public:
		Particle(float rot);
		virtual ~Particle();

		virtual void update(float deltaTime);

	private:
		Timer* t;
};

#endif /* BASICENTITY_H */
