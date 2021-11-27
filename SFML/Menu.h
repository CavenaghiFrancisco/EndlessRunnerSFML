#pragma once
#include "Button.h"

using namespace sf;

class Menu {
private:
	bool menuInited;
	bool goToGame;
	bool goToShop;
	bool goToCredits;
	bool goToOptions;
	bool exitGame;
	int option;
	Texture menuTexture;
	Sprite menuSprite;
	Button* playButton;
	Button* creditsButton;
	Button* quitButton;
public:
	Menu();
	~Menu();
	void Init(RenderWindow& window);
	void Input(RenderWindow& window, Event& events);
	void Update(RenderWindow& window);
	void Draw(RenderWindow& window);
	void DeInit();
	bool GetInited();
	bool ExitGame();
	bool ExitMenuGoToCredits();
	bool ExitMenuGoToGame();
};





