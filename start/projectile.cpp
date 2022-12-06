#include "projectile.h"

Projectile::Projectile() : Entity()
{
	this->addSprite("assets/BombTower.tga");
	this->scale = Point(0.4, 0.4);
	this->sprite()->color = WHITE;
	hitTarget = false;
}

Projectile::~Projectile()
{

}

void Projectile::update(float deltaTime)
{

}

void Projectile::moveToTarget(Point3 targetPosition, float deltaTime)
{
	Vector2 length = Vector2(this->position.x - targetPosition.x, this->position.y - targetPosition.y);
	float diffX = this->position.x - targetPosition.x;
	float diffY = this->position.y - targetPosition.y;
	float angle = atan2(diffY, diffX);
	if (length.getLength() > 1)
	{
		this->rotation.z = angle;
		float currentRotation = angle / PI * 180;
		this->position.x += (cos(0.017453277777 * currentRotation)) * -13;
		this->position.y += (sin(0.017453277777 * currentRotation)) * -13;
	}
}

Point3 Projectile::checkClosestEnemy(std::vector<Enemy*> enemies)
{
	Vector2 length = Vector2(1000,1000);
	Point3 targetPosition;
	int index = 0;
	for (int i = enemies.size() - 1; i >= 0; i--)
	{
		Vector2 tempLength = Vector2(this->position.x - enemies[i]->position.x, this->position.y - enemies[i]->position.y);
		if (tempLength.getLength() < length.getLength())
		{
			length = tempLength;
			targetPosition = enemies[i]->position;
			index = i;
		}
	}
	if (length.getLength() < 64)
	{
		hitTarget = true;
		enemies[index]->reachedEndPoint = true;
	}
	else if (enemies.size() == 0)
	{
		hitTarget = true;
	}
	return targetPosition;
}