#include "App.h"

void Run() {
    RenderWindow window(VideoMode(500, 800), "SFML works!");
    Event events;
    GameManager* GM = new GameManager();
    while (window.isOpen()) {
        GM->StartGameManager(window, events);
    }
    delete GM;
}
