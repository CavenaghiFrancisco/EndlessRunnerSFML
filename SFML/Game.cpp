#include "Game.h"
#include <cmath>


Game::Game() {
    gameInited = false;
    shapePosition = 1;
}

Game::~Game() {
    
}

bool Game::GetInited() {
    return gameInited;
}

void Game::InitGame(RenderWindow& window) {
    gameInited = true;
    gameOver = false;
    goToMenu = false;
    replay = false;
    isPaused = false;
    goToGame = false;
    gameOver = false;
    victory = false;
    pause = false;
    timerPowerUp = 0.0f;
    lava0.setSize({(float)window.getSize().x/7,(float)window.getSize().y});
    lava1.setSize({(float)window.getSize().x/7,(float)window.getSize().y});
    lava2.setSize({(float)window.getSize().x/7,(float)window.getSize().y});
    lava3.setSize({(float)window.getSize().x/7,(float)window.getSize().y});
    path0.setSize({(float)window.getSize().x/7,(float)window.getSize().y});
    path1.setSize({(float)window.getSize().x/7,(float)window.getSize().y});
    path2.setSize({(float)window.getSize().x/7,(float)window.getSize().y});
    lava0.setPosition({ 0,0 });
    path0.setPosition({ lava0.getSize().x,0 });
    lava1.setPosition({ lava0.getSize().x*2,0 });
    path1.setPosition({ lava0.getSize().x * 3,0 });
    lava2.setPosition({ lava0.getSize().x*4,0 });
    path2.setPosition({ lava0.getSize().x * 5,0 });
    lava3.setPosition({ lava0.getSize().x*6,0 });
    lava0.setFillColor(Color::Red);
    lava1.setFillColor(Color::Red);
    lava2.setFillColor(Color::Red);
    lava3.setFillColor(Color::Red);
    path0.setFillColor(Color::Green);
    path1.setFillColor(Color::Green);
    path2.setFillColor(Color::Green);
    shape.setRadius(window.getSize().x / 14);
    shape.setFillColor(Color::Blue);
    shape.setPosition(path1.getPosition().x, shape.getPosition().y);
}

void Game::InputGame(RenderWindow& window, Event& events) {
    while (window.pollEvent(events)) {
        if (events.type == Event::Closed) {
            window.close();
        }
        if (events.type == Event::KeyPressed) {
            if (Keyboard::isKeyPressed(Keyboard::M)) {
                goToMenu = true;
            }
        }
        if (events.type == Event::KeyPressed) {
            if (Keyboard::isKeyPressed(Keyboard::W)) {
                shape.setPosition(shape.getPosition().x,shape.getPosition().y - 120);
            }
        }
        if (events.type == Event::KeyPressed) {
            if (Keyboard::isKeyPressed(Keyboard::S)) {
                shape.setPosition(shape.getPosition().x, shape.getPosition().y + 120);
            }
        }
        if (events.type == Event::KeyPressed) {
            if (Keyboard::isKeyPressed(Keyboard::A)) {
                if (shapePosition == 1) {
                    shape.setPosition(path0.getPosition().x, shape.getPosition().y);
                    shapePosition = 0;
                }
                else if (shapePosition == 2) {
                    shape.setPosition(path1.getPosition().x, shape.getPosition().y);
                    shapePosition = 1;
                }
                
            }
        }
        if (events.type == Event::KeyPressed) {
            if (Keyboard::isKeyPressed(Keyboard::D)) {
                if (shapePosition == 0) {
                    shape.setPosition(path1.getPosition().x, shape.getPosition().y);
                    shapePosition = 1;
                }
                else if (shapePosition == 1) {
                    shape.setPosition(path2.getPosition().x, shape.getPosition().y);
                    shapePosition = 2;
                }
            }
        }
    }
}



void Game::UpdateGame(RenderWindow& window) {
   
}

void Game::DrawGame(RenderWindow& window) {
    window.clear();
    window.draw(lava0);
    window.draw(lava1);
    window.draw(lava2);
    window.draw(lava3);
    window.draw(path0);
    window.draw(path1);
    window.draw(path2);
    window.draw(shape);
    window.display();
}

void Game::DeInitGame() {
    
}


void Game::UpdateDrawFrame(RenderWindow& window, Event& events) {
    Game::InputGame(window, events);
    Game::UpdateGame(window);
    Game::DrawGame(window);
}

bool Game::GoToMenu() {
    return goToMenu;
}

bool Game::GoToGame() {
    return goToGame;
}