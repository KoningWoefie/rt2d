#ifndef OMNIBAR_H
#define OMNIBAR_H

#include <rt2d/entity.h>

/// <summary>
/// bar on top of the shop that you can move
/// </summary>
class Omnibar : public Entity
{
public:
	/// <summary>
	/// constructor
	/// </summary>
	Omnibar();

	/// <summary>
	/// destructor
	/// </summary>
	virtual ~Omnibar();

	/// <summary>
	/// moves the omnibar with the mouse when clicked (sets bool hovered)
	/// </summary>
	void moveWithMouseWhenClicked();

	virtual void update(float deltaTime);

	/// <summary>
	/// true when hovered by the mouse
	/// </summary>
	bool hovered;

private:

};

#endif