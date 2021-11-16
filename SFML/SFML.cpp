#include "GameManager.h"

using namespace sf;

int main() {
    RenderWindow window(VideoMode(500, 800), "SFML works!");
    Event event;
    GameManager* GM = new GameManager();
    while (window.isOpen()) {
        
        while (window.pollEvent(event))         {
            if (event.type == Event::Closed) {
                window.close();
            }
            if (event.type == Event::KeyPressed) {
                if(Keyboard::isKeyPressed(Keyboard::Escape)) window.close();
            }
            GM->StartGameManager();
        }
        
    }
    delete GM;
    return 0;
}