#include "GameManager.h"
#include <iostream>

GameManager::GameManager() {
	isPlaying = true;
}

GameManager::~GameManager() {
}

STATES GameManager::GetState() {
	return currentState;
}

void GameManager::SetState(STATES& states) {
	currentState = states;
}

bool GameManager::ChangeState(STATES states) {
	if (currentState == states) {
		return false;
	}
	else {
		SetState(states);
		return true;
	}
}



void GameManager::StartGameManager(RenderWindow &window, Event& events) {
	UpdateState(GetState(), window, events);
}

bool GameManager::QuitGame() {
	return isPlaying;
}

void GameManager::MenuState(RenderWindow& window, Event& events) {
	if (isThisStateStarting) {
		menu = new Menu();
		isThisStateStarting = false;
	}
	if (!(menu->GetInited())) {
		menu->Init(window);
	}
	menu->Input(window, events);
	menu->Update(window);
	menu->Draw(window);
	if (menu->ExitMenuGoToGame()) {
		currentState = STATES::GAME;
		menu->DeInit();
		delete menu;
		isThisStateStarting = true;
	}
	else if (menu->ExitGame()) {
		currentState = STATES::EXIT;
		menu->DeInit();
		delete menu;
		isThisStateStarting = true;
	}
}

void GameManager::GameState(RenderWindow& window, Event& events) {
	if (isThisStateStarting) {
		gameplay = new Gameplay();
		isThisStateStarting = false;
	}
	if (!(gameplay->GetInited())) {
		gameplay->InitGame(window);
	}
	gameplay->UpdateDrawFrame(window, events);
	if (gameplay->GoToMenu()) {
		currentState = STATES::MENU;
		gameplay->DeInitGame();
		delete gameplay;
		isThisStateStarting = true;
	}
	else if (gameplay->GoToGame()) {
		currentState = STATES::GAME;
		gameplay->DeInitGame();
		delete gameplay;
		isThisStateStarting = true;
	}
}

void GameManager::UpdateState(STATES states, RenderWindow& window, Event& events) {
	switch (GetState()) {
	case STATES::MENU:
		MenuState(window, events);
		break;
	case STATES::GAME:
		GameState(window, events);
		break;
	case STATES::EXIT:
		isPlaying = false;
		break;
	default:
		break;
	}
}

