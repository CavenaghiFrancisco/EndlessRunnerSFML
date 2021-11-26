#include "App.h"
#include "GameManager.h"
//Incluir todo lo que se usa

void Run() {
    RenderWindow window(VideoMode(1000, 800), "");
    Event events;
    GameManager* GM = new GameManager();
    while (window.isOpen()) {
        GM->StartGameManager(window, events);
    }
    delete GM;
}
