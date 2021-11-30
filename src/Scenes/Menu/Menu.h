#pragma once
#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"

#include "Objects/Button.h"

using namespace sf;

class Menu {
private:
	bool menuInited;
	bool goToGame;
	bool goToCredits;
	bool exitGame;
	Texture menuTexture;
	Texture creditTexture;
	Sprite menuSprite;
	Sprite creditSprite;
	Button* playButton;
	Button* creditsButton;
	Button* quitButton;
	Button* backButton;
	Mouse mouse;
	Music menuMusic;
public:
	Menu();
	~Menu();
	void Init(RenderWindow& window);
	void Input(RenderWindow& window, Event& events);
	void Draw(RenderWindow& window);
	void DeInit();
	bool GetInited();
	bool ExitGame();
	bool ExitMenuGoToCredits();
	bool ExitMenuGoToGame();
};





