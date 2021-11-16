#pragma once
#include "Menu.h"
#include "Game.h"

enum class STATES { MENU, EXIT, GAME, SHOP };

class GameManager {
private:
	RenderWindow* window;
	Event* events;
	STATES currentState = STATES::MENU;
	bool isThisStateStarting = true;
	bool isPlaying;
	Menu* menu;
	Game* game;
public:
	GameManager(RenderWindow* window, Event* events);
	~GameManager();
	STATES GetState();
	void SetState(STATES& states);
	void UpdateState(STATES states);
	bool ChangeState(STATES states);
	void StartGameManager();
	bool QuitGame();
};



