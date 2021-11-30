#include "App.h"

#include "SFML/Graphics.hpp"

#include "Scenes/GameManager.h"

using namespace sf;

void Run() {
    RenderWindow window(VideoMode(1000, 800), "Escape from the Underworld");
    Event events;
    GameManager* GM = new GameManager();
    while (window.isOpen() && GM->QuitGame()) {
        GM->StartGameManager(window, events);
    }
    delete GM;
}
