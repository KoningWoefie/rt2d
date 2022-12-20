#include "ImageButton.h"

ImageButton::ImageButton(std::string ButtonText) : Entity() 
{
	hovered = false;
	ButtonState = 0;
	SpriteFrame = 3;
	_CallbackFunction = NULL;

	this->addSpriteSheet("assets/button.tga", 1, 4); // divide Texture in 1x4 slices
	this->sprite()->pivot = Point2(0, 0);
	this->sprite()->frame(SpriteFrame);

	textbox = new Text();
	textbox->scale = Point2(0.45f, 0.45f);
	textbox->position = Point2(32, 28);
	textbox->message(ButtonText, WHITE);

	addChild(textbox);
}

ImageButton::~ImageButton() 
{

}

void ImageButton::update(float deltaTime) 
{

	int mousex = input()->getMouseX();
	int mousey = input()->getMouseY();

	Point2 pos = worldposition();

	int left = pos.x - (sprite()->size.x * this->scale.x)/ 2;
	int right = pos.x + (sprite()->size.x * this->scale.x)/2;
	int top = pos.y - (sprite()->size.y * this->scale.y) / 2;
	int bottom = pos.y + (sprite()->size.y * this->scale.y)/2;

	if (ButtonState != 3) {
		if (mousex > left && mousex < right && mousey > top && mousey < bottom) {
			hovered = true;
			if (input()->getMouseDown(0)) {
				ButtonState = 2;
				textbox->position = Point2(textbox->position.x, 32);

				if (_CallbackFunction != NULL) {
					_CallbackFunction();
				}
			}

			if (ButtonState == 0 || input()->getMouseUp(0)) {
				ButtonState = 1;
				textbox->position = Point2(textbox->position.x, 28);
			}
		}
		else {
			ButtonState = 0;
			hovered = false;
			textbox->position = Point2(textbox->position.x, 28);
		}
	}
	else {
		textbox->position = Point2(textbox->position.x, 28);
	}

	switch (ButtonState) {
	case 0: SpriteFrame = 3; break;	//Normal
	case 1: SpriteFrame = 1; break;	//MouseOver
	case 2: SpriteFrame = 2; break;	//MouseDown
	case 3: SpriteFrame = 0; break;	//Disabled
	}

	this->sprite()->frame(SpriteFrame);
}

void ImageButton::setCallbackFunction(std::function<void()> CallbackFunction) 
{
	_CallbackFunction = CallbackFunction;
}

void ImageButton::Disable() 
{
	ButtonState = 3;
}

void ImageButton::Enable() 
{
	ButtonState = 0;
}