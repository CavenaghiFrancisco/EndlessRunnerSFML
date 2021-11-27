#include "Button.h"

Button::Button(float positionX, float positionY, float sizeX, float sizeY) {
	button.setSize({ sizeX, sizeY });
	button.setPosition(positionX, positionY);
	button.setFillColor(Color::Blue);
}

Button::~Button() {
}

void Button::IsClicked() {
}

void Button::Draw(RenderWindow &window) {
	window.draw(button);
}
