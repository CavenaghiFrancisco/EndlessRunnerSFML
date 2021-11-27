#pragma once
#include "SFML/Graphics.hpp"

using namespace sf;

class Button {
private:
	RectangleShape button;
public:
	Button(float positionX, float positionY, float sizeX, float sizeY);
	~Button();
	void IsClicked();
	void Draw(RenderWindow &window);
};

