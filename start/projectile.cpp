#include "projectile.h"

Projectile::Projectile() : Entity()
{
	outOfScreen = true;
	hitTarget = false;
	rotated = false;
	dead = false;
	lifeSpan = 1;
	lifeSpanTimer = new Timer();
	currentRotation = 0;
	this->addSprite("assets/BombTower.tga");
	this->scale = Point(0.4, 0.4);
	this->sprite()->color = WHITE;
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
	if (length.getLength() > 1 && targetPosition != Point3(0,0,0))
	{
		if (!rotated)
		{
			this->rotation.z = angle;
			rotated = true;
		}
		this->position.x += ((cos(this->rotation.z)) * -1500) * deltaTime;
		this->position.y += ((sin(this->rotation.z)) * -1500) * deltaTime;
	}
}

//check which enemy is the closest through Vector2 GetLength()
Point3 Projectile::checkClosestEnemy(std::vector<Enemy*> enemies)
{
	Vector2 length = Vector2(1000,1000);
	Point3 targetPosition;
	for (int i = enemies.size() - 1; i >= 0; i--)
	{
		if (!(enemies[i]->position.x < 0 || enemies[i]->position.x > SWIDTH || enemies[i]->position.y < 0 || enemies[i]->position.y > SHEIGHT))
		{
			Vector2 tempLength = Vector2(this->position.x - enemies[i]->position.x, this->position.y - enemies[i]->position.y);
			if (tempLength.getLengthSquared() < length.getLengthSquared())
			{
				length = tempLength;
				targetPosition = enemies[i]->position;
				index = i;
			}
			outOfScreen = false;
		}
		else
		{
			outOfScreen = true;
		}
	}
	return targetPosition;
}

//check collision with its target through Vector2 getLength()
int Projectile::checkCollision(Point3 target)
{
	Vector2 length = Vector2(this->position.x - target.x, this->position.y - target.y);
	if (length.getLength() < 64)
	{
		dead = true;
		hitTarget = true;
	}
	return index;
}

void Projectile::checkIfOutOfScreen()
{
	if (this->position.x < 0 || this->position.x > SWIDTH || this->position.y < 0 || this->position.y > SHEIGHT)
	{
		dead = true;
	}
}