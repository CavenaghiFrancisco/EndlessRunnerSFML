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
	menuTexture.loadFromFile("MainMenu.png");
	menuSprite.setTexture(menuTexture);
	menuSprite.setPosition(0, 0);
}

Menu::~Menu() {

}

void Menu::Init(RenderWindow& window) {
	menuInited = true;
	playButton = new Button((float)window.getSize().x / 2- (window.getSize().x / 4)/2, window.getSize().y * 3 / 6, window.getSize().x / 4, 100);
	creditsButton = new Button((float)window.getSize().x / 2 - (window.getSize().x / 4) / 2, (float)window.getSize().y * 4 / 6, (float)window.getSize().x / 4, 100);
	quitButton = new Button((float)window.getSize().x / 2 - (window.getSize().x / 4) / 2, (float)window.getSize().y * 5 / 6, (float)window.getSize().x / 4, 100);
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
	playButton->Draw(window);
	creditsButton->Draw(window);
	quitButton->Draw(window);
	window.draw(menuSprite);
	window.display();
}

bool Menu::GetInited() {
	return menuInited;
}

bool Menu::ExitMenuGoToGame() {
	return goToGame;
}

bool Menu::ExitMenuGoToCredits() {
	return goToCredits;
}

bool Menu::ExitGame() {
	return exitGame;
}

void Menu::DeInit() {
	menuInited = false;
}


