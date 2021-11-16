#pragma once
#include "Player.h"

class Game {
private:
	bool gameInited;
	bool goToMenu;
	bool replay;
	bool isPaused;
	bool goToGame;
	bool victory;
	bool pause;
	bool gameOver;
	float scrolling;
	float timerPowerUp;
	CircleShape shape;
	int shapePosition = 1;
	RectangleShape lava0;
	RectangleShape lava1;
	RectangleShape lava2;
	RectangleShape lava3;
	RectangleShape path0;
	RectangleShape path1;
	RectangleShape path2;

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
	void InitGame(RenderWindow& window);         // Initialize game
	void InputGame(RenderWindow& window, Event& events);
	void UpdateGame(RenderWindow& window);       // Update game (one frame)
	void DrawGame(RenderWindow& window);         // Draw game (one frame)
	void DeInitGame();       // Unload game
	void UpdateDrawFrame(RenderWindow& window, Event& events);  // Update and Draw (one frame)
	bool GoToMenu();
	bool GoToGame();
};




