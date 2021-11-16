#pragma once
#include "Menu.h"
#include "Game.h"

enum class STATES { MENU, EXIT, GAME, SHOP };

class GameManager {
private:
	STATES currentState = STATES::MENU;
	bool isThisStateStarting = true;
	bool isPlaying;
	Menu* menu;
	Game* game;
public:
	GameManager();
	~GameManager();
	STATES GetState();
	void SetState(STATES& states);
	void UpdateState(STATES states, RenderWindow& window, Event& events);
	bool ChangeState(STATES states);
	void StartGameManager(RenderWindow& window, Event &events);
	bool QuitGame();
};



