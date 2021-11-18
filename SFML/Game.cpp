#include "Game.h"
#include <cmath>


Game::Game() {
    gameInited = false;
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
    shape.setSize({ (float)window.getSize().x / 8,(float)window.getSize().y / 10 });
    shape.setFillColor(Color::Transparent);
    shape.setPosition(path1.getPosition().x + 4.5, shape.getPosition().y + 120 * 6);
    player = new Player(3, shape, true);
}

void Game::InputGame(RenderWindow& window, Event& events) {
    while (window.pollEvent(events)) {
        switch (events.type) {
        case Event::Closed:
            window.close();
            break;
        case Event::KeyPressed:
            if (Keyboard::isKeyPressed(Keyboard::M)) {
                goToMenu = true;
            }
            else if (Keyboard::isKeyPressed(Keyboard::W)) {
                player->MovePlayerUp();
            }
            else if (Keyboard::isKeyPressed(Keyboard::S)) {
                player->MovePlayerDown();
            }
            else if (Keyboard::isKeyPressed(Keyboard::D)) {
                player->MovePlayerRight(path0, path1, path2);
            }
            else if (Keyboard::isKeyPressed(Keyboard::A)) {
                player->MovePlayerLeft(path0, path1, path2);
            }
            break;
        default:
            break;
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
    window.draw(player->GetCollider());
    window.draw(player->GetSprite());
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