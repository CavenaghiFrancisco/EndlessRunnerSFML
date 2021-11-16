#pragma once
#include "SFML/Graphics.hpp"

using namespace sf;

class Menu {
private:
	RenderWindow* window;
	Event* events;
	bool menuInited;
	bool goToGame;
	bool goToShop;
	bool goToCredits;
	bool goToOptions;
	bool exitGame;
	int option;
public:
	const float screenWidth = 1366;
	const float screenHeight = 768;
	float currentScreenWidth = 1366;
	float currentScreenHeight = 768;
	float windowReSizeWidth = currentScreenWidth / screenWidth;
	float windowReSizeHeight = currentScreenHeight / screenHeight;
	Menu(RenderWindow* window);
	~Menu();
	void Init();
	void Input();
	void Update();
	void Draw();
	void DeInit();
	bool GetInited();
	bool ExitGame();
	bool ExitMenuGoToCredits();
	bool ExitMenuGoToOptions();
	bool ExitMenuGoToGame();
	bool ExitMenuGoToShop();
};





