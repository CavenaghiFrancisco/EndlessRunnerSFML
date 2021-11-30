#pragma once

#include "Menu/Menu.h"
#include "Gameplay/Gameplay.h"

enum class STATES { MENU, EXIT, GAME, SHOP };

class GameManager {
private:
	STATES currentState = STATES::MENU;
	bool isThisStateStarting = true;
	bool isPlaying;
	Menu* menu;
	Gameplay* gameplay;
public:
	GameManager();
	~GameManager();
	STATES GetState();
	void SetState(STATES& states);
	void UpdateState(RenderWindow& window, Event& events);
	bool ChangeState(STATES states);
	void StartGameManager(RenderWindow& window, Event &events);
	bool QuitGame();
	void MenuState(RenderWindow& window, Event& events);
	void GameState(RenderWindow& window, Event& events);
};



