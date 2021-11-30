#include "Button.h"

Button::Button(float positionX, float positionY, float sizeX, float sizeY) {
	button.setSize({ sizeX, sizeY });
	button.setPosition(positionX, positionY);
	button.setFillColor({255,255,255,100});
}

Button::~Button() {
}

bool Button::IsClicked(RenderWindow& window) {
	if (button.getGlobalBounds().contains({ (float)Mouse::getPosition(window).x,(float)Mouse::getPosition(window).y })) {
		return true;
	}
	else {
		return false;
	}
}

void Button::Draw(RenderWindow &window) {
	window.draw(button);
}
