#pragma once
#include "SFML/Graphics.hpp"

using namespace sf;

class Button {
private:
	RectangleShape button;
public:
	Button(float positionX, float positionY, float sizeX, float sizeY);
	~Button();
	bool IsClicked(RenderWindow &window);
	void Draw(RenderWindow &window);
};

