#include "Menu.h"

Menu::Menu(RenderWindow* window) {
	this->window = window;
	menuInited = false;
	goToGame = false;
	goToCredits = false;
	
}

Menu::~Menu() {

}

void Menu::Init() {
	menuInited = true;
}

void Menu::Input() {
	
}

void Menu::Update() {
	
}

void Menu::Draw() {
	
}

bool Menu::GetInited() {
	return menuInited;
}

bool Menu::ExitMenuGoToGame() {
	return goToGame;
}

bool Menu::ExitMenuGoToShop() {
	return goToShop;
}

bool Menu::ExitMenuGoToCredits() {
	return goToCredits;
}

bool Menu::ExitMenuGoToOptions() {
	return goToOptions;
}

bool Menu::ExitGame() {
	return exitGame;
}

void Menu::DeInit() {
	menuInited = false;
}


