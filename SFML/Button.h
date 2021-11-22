#pragma once
#include "SFML/Graphics.hpp"

using namespace sf;

class Button {
private:
	RectangleShape button;
	Texture buttonTexture;
	Sprite buttonSprite;
public:
	Button(Texture &buttonTexture, float positionX, float positionY, float sizeX, float sizeY);
	~Button();
	void IsClicked();
	void Draw(RenderWindow &window);
};

