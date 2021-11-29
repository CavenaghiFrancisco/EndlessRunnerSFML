#include "Menu.h"

Menu::Menu() {
	menuInited = false;
	goToGame = false;
	goToCredits = false;
	exitGame = false;
	creditTexture.loadFromFile("Credits.png");
	menuTexture.loadFromFile("MainMenu.png");
	menuSprite.setTexture(menuTexture);
	menuSprite.setPosition(0, 0);
	creditSprite.setTexture(creditTexture);
	creditSprite.setPosition(0, 0);
	menuMusic.openFromFile("Audio/MenuMusic.wav");
	menuMusic.setLoop(true);
	menuMusic.play();
}

Menu::~Menu() {

}

void Menu::Init(RenderWindow& window) {
	menuInited = true;
	playButton = new Button((float)window.getSize().x / 2- (window.getSize().x / 4)/2+10, window.getSize().y * 3 / 6, window.getSize().x / 4, 100);
	creditsButton = new Button((float)window.getSize().x / 2 - (window.getSize().x / 4) / 2 + 10, (float)window.getSize().y * 4 / 6, (float)window.getSize().x / 4, 100);
	quitButton = new Button((float)window.getSize().x / 2 - (window.getSize().x / 4) / 2 + 10, (float)window.getSize().y * 5 / 6-10, (float)window.getSize().x / 4, 100);
	backButton = new Button((float)115, 95, 74, 60);
}

void Menu::Input(RenderWindow& window, Event& events) {
	while (window.pollEvent(events)){
		if (events.type == Event::Closed) {
			window.close();
		}
		if (events.type == Event::MouseButtonPressed) {
			if (mouse.isButtonPressed(Mouse::Button::Left)) {
				if (!goToCredits) {
					if (playButton->IsClicked(window)) {
						goToGame = true;
					}
					else if(creditsButton->IsClicked(window)) {
						goToCredits = true;
					} 
					else if (quitButton->IsClicked(window)) {
						exitGame = true;
					}
				}
				else {
					if (backButton->IsClicked(window)) {
						goToCredits = false;
					}
				}
			}
		}
	}
}

void Menu::Update(RenderWindow& window) {
	
}

void Menu::Draw(RenderWindow& window) {
	window.clear();
	if (!goToCredits) {
	window.draw(menuSprite);
	}
	else {
		window.draw(creditSprite);
		backButton->Draw(window);
	}
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


