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
	//crear clase button
	playButton.setSize({ (float)window.getSize().x / 2,100 });
	creditsButton.setSize({ (float)window.getSize().x / 2,100 });
	quitButton.setSize({ (float)window.getSize().x / 2,100 });
	playButton.setPosition({ (float)window.getSize().x / 4,(float)window.getSize().y*3/6 });
	creditsButton.setPosition({ (float)window.getSize().x / 4,(float)window.getSize().y * 4 / 6 });
	quitButton.setPosition({ (float)window.getSize().x / 4,(float)window.getSize().y * 5 / 6 });
	playButton.setFillColor(Color::Blue);
	creditsButton.setFillColor(Color::Green);
	quitButton.setFillColor(Color::Red);
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
	window.draw(playButton);
	window.draw(creditsButton);
	window.draw(quitButton);
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


