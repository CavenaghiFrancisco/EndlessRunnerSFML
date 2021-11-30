#pragma once

#include <vector>

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

#include "Player.h"
#include "Objects/Fire.h"
#include "Objects/Coin.h"
#include "Objects/Wine.h"
#include "Scenes/Menu/Objects/Button.h"

class Gameplay {
private:
	bool gameInited;
	bool goToMenu;
	bool isPaused;
	bool goToGame;
	bool gameOver;
	int second;
	RectangleShape shape;
	Texture lava;
	Sprite spriteLava0;
	Sprite spriteLava1;
	Sprite spriteLava2;
	Sprite spriteLava3;
	RectangleShape lava0;
	RectangleShape lava1;
	RectangleShape lava2;
	RectangleShape lava3;
	Texture path;
	Sprite spritePath0;
	Sprite spritePath1;
	Sprite spritePath2;
	RectangleShape path0;
	RectangleShape path1;
	RectangleShape path2;
	Player* player;
	Texture fireTexture;
	Texture coinTexture;
	Texture wineTexture;
	RectangleShape fire0;
	RectangleShape fire1;
	RectangleShape fire2;
	RectangleShape fire3;
	RectangleShape fire4;
	RectangleShape fire5;
	RectangleShape fire6;
	RectangleShape coin0;
	RectangleShape coin1;
	RectangleShape coin2;
	RectangleShape wine;
	Texture unpausedTexture;
	Texture unpausedGreyTexture;
	Texture pausedTexture;
	Texture pausedGreyTexture;
	Texture restartTexture;
	Texture restartGreyTexture;
	Sprite halfScreen;
	vector<Object*> objects;
	Clock clock;
	Clock pausedClock;
	Button* resumeButton;
	Button* menuButton;
	Font font;
	Text text;
	SoundBuffer initialBuffer;
	Sound initialSound;
	SoundBuffer deathBuffer;
	Sound deathSound;
	Music gameMusic;
public:
	Gameplay();
	~Gameplay();
	bool GetInited();
	void InitGame(RenderWindow& window);         // Initialize game
	void InputGame(RenderWindow& window, Event& events);
	void UpdateGame();       // Update game (one frame)
	void DrawGame(RenderWindow& window);         // Draw game (one frame)
	void DeInitGame();       // Unload game
	void UpdateDrawFrame(RenderWindow& window, Event& events);  // Update and Draw (one frame)
	bool GoToMenu();
	bool GoToGame();
};




