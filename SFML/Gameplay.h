#pragma once
#include "Player.h"
#include "Fire.h"
#include <vector>

class Gameplay {
private:
	bool gameInited;
	bool goToMenu;
	bool replay;
	bool isPaused;
	bool goToGame;
	bool victory;
	bool pause;
	bool gameOver;
	int second;
	float scrolling;
	float timerPowerUp;
	RectangleShape shape;
	RectangleShape lava0;
	RectangleShape lava1;
	RectangleShape lava2;
	RectangleShape lava3;
	RectangleShape path0;
	RectangleShape path1;
	RectangleShape path2;
	Player* player;
	Texture fireTexture;
	RectangleShape fire0;
	RectangleShape fire1;
	RectangleShape fire2;
	vector<Object*> objects;
	Clock clock;
public:
	Gameplay();
	~Gameplay();
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




