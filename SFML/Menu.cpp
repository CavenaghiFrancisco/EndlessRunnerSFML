#include "Menu.h"

Menu::Menu() {
	menuInited = false;
	goToGame = false;
	goToCredits = false;
	menuInited = false;
	goToGame = false;
	goToShop = false;
	goToCredits = false;
	goToOptions = false;
	exitGame = false;
}

Menu::~Menu() {

}

void Menu::Init(RenderWindow& window) {
	menuInited = true;
	shape.setRadius(100);
	shape.setFillColor(Color::Red);
}

void Menu::Input(RenderWindow& window, Event& events) {
	while (window.pollEvent(events)){
		if (events.type == Event::Closed) {
			window.close();
		}
		if (events.type == Event::KeyPressed) {
			if (Keyboard::isKeyPressed(Keyboard::G)) {
				goToGame = true;
			}
		}
	}
}

void Menu::Update(RenderWindow& window) {
	
}

void Menu::Draw(RenderWindow& window) {
	window.clear();
	window.draw(shape);
	window.display();
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


