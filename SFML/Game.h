#pragma once
#include "Player.h"

class Game {
private:
	RenderWindow* window;
	Event* events;
	bool gameInited;
	bool goToMenu;
	bool replay;
	bool isPaused;
	bool goToGame;
	float scrolling;
	float timerPowerUp;
public:
	const int screenWidth = 720;
	const int screenHeight = 1280;
	float currentScreenWidth = 720;
	float currentScreenHeight = 1280;
	float windowReSizeWidth = currentScreenWidth / screenWidth;
	float windowReSizeHeight = currentScreenHeight / screenHeight;
	Game();
	~Game();
	bool GetInited();
	void InitGame();         // Initialize game
	void InputGame();
	void UpdateGame();       // Update game (one frame)
	void DrawGame();         // Draw game (one frame)
	void DeInitGame();       // Unload game
	void UpdateDrawFrame();  // Update and Draw (one frame)
	bool GoToMenu();
	bool GoToGame();
};




