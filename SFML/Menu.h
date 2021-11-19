#pragma once
#include "SFML/Graphics.hpp"

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
	RectangleShape playButton;
	RectangleShape creditsButton;
	RectangleShape quitButton;
	RectangleShape title;
public:
	/*const float screenWidth = 1366;
	const float screenHeight = 768;
	float currentScreenWidth = 1366;
	float currentScreenHeight = 768;*/
	/*float windowReSizeWidth = currentScreenWidth / screenWidth;
	float windowReSizeHeight = currentScreenHeight / screenHeight;*/
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
	bool ExitMenuGoToOptions();
	bool ExitMenuGoToGame();
	bool ExitMenuGoToShop();
};





