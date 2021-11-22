#include "Button.h"

Button::Button(Texture &buttonTexture, float positionX, float positionY, float sizeX, float sizeY) {
	button.setSize({ sizeX, sizeY });
	button.setPosition(positionX, positionY);
	button.setFillColor(Color::Blue);
	buttonSprite.setTexture(buttonTexture);
	buttonSprite.setPosition(positionX, positionY);
}

Button::~Button() {
}

void Button::IsClicked() {
}

void Button::Draw(RenderWindow &window) {
	window.draw(button);
	window.draw(buttonSprite);
}
