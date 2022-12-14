#include "projectile.h"

Projectile::Projectile() : Entity()
{
	this->addSprite("assets/BombTower.tga");
	this->scale = Point(0.4, 0.4);
	this->sprite()->color = WHITE;
	hitTarget = false;
	index = 0;
}

Projectile::~Projectile()
{

}

void Projectile::update(float deltaTime)
{

}

//rotate towards target and move forward
void Projectile::moveToTarget(Point3 targetPosition, float deltaTime)
{
	Vector2 length = Vector2(this->position.x - targetPosition.x, this->position.y - targetPosition.y);
	float diffX = this->position.x - targetPosition.x;
	float diffY = this->position.y - targetPosition.y;
	float angle = atan2(diffY, diffX);
	if (length.getLength() > 1)
	{
		this->rotation.z = angle - 30;
		float currentRotation = angle / PI * 180;
		this->position.x += (cos(0.017453277777 * currentRotation)) * -13;
		this->position.y += (sin(0.017453277777 * currentRotation)) * -13;
	}
}

//check which enemy is the closest through Vector2 GetLength()
Point3 Projectile::checkClosestEnemy(std::vector<Enemy*> enemies)
{
	Vector2 length = Vector2(1000,1000);
	Point3 targetPosition;
	for (int i = enemies.size() - 1; i >= 0; i--)
	{
		Vector2 tempLength = Vector2(this->position.x - enemies[i]->position.x, this->position.y - enemies[i]->position.y);
		if (tempLength.getLengthSquared() < length.getLengthSquared())
		{
			length = tempLength;
			targetPosition = enemies[i]->position;
			index = i;
		}
	}
	return targetPosition;
}

//check collision with its target through Vector2 getLength()
int Projectile::checkCollision(Point3 target)
{
	Vector2 length = Vector2(this->position.x - target.x, this->position.y - target.y);
	if (length.getLength() < 32)
	{
		hitTarget = true;
	}
	return index;
}