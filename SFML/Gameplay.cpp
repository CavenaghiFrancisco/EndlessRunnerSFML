#include "Gameplay.h"
#include <cmath>


Gameplay::Gameplay() {
    gameInited = false;
}

Gameplay::~Gameplay() {
    delete player;
}

bool Gameplay::GetInited() {
    return gameInited;
}

void Gameplay::InitGame(RenderWindow& window) {
    gameInited = true;
    gameOver = false;
    goToMenu = false;
    replay = false;
    isPaused = false;
    goToGame = false;
    gameOver = false;
    victory = false;
    pause = false;
    second = 0;
    timerPowerUp = 0.0f;
    lava0.setSize({ (float)window.getSize().x / 14,(float)window.getSize().y });
    lava1.setSize({ (float)window.getSize().x / 14,(float)window.getSize().y });
    lava2.setSize({ (float)window.getSize().x / 14,(float)window.getSize().y });
    lava3.setSize({ (float)window.getSize().x / 14,(float)window.getSize().y });
    path0.setSize({ (float)window.getSize().x / 14,(float)window.getSize().y });
    path1.setSize({ (float)window.getSize().x / 14,(float)window.getSize().y });
    path2.setSize({ (float)window.getSize().x / 14,(float)window.getSize().y });
    lava0.setPosition({ 0,0 });
    path0.setPosition({ lava0.getSize().x,0 });
    lava1.setPosition({ lava0.getSize().x * 2,0 });
    path1.setPosition({ lava0.getSize().x * 3,0 });
    lava2.setPosition({ lava0.getSize().x * 4,0 });
    path2.setPosition({ lava0.getSize().x * 5,0 });
    lava3.setPosition({ lava0.getSize().x * 6,0 });
    lava0.setFillColor(Color::Red);
    lava1.setFillColor(Color::Red);
    lava2.setFillColor(Color::Red);
    lava3.setFillColor(Color::Red);
    path0.setFillColor(Color::Green);
    path1.setFillColor(Color::Green);
    path2.setFillColor(Color::Green);
    shape.setSize({ (float)window.getSize().x / 16,(float)window.getSize().y / 10 });
    shape.setFillColor(Color::Transparent);
    shape.setPosition(path1.getPosition().x + 4.5, shape.getPosition().y + 120 * 6);
    player = new Player(3, shape, true);

    fire0.setSize({ (float)window.getSize().x / 16,(float)window.getSize().y / 10 });
    fire0.setFillColor(Color::Transparent);
    fire0.setPosition(path2.getPosition().x + 4.5, shape.getPosition().y - 120 * 6);
    fire1.setSize({ (float)window.getSize().x / 16,(float)window.getSize().y / 10 });
    fire1.setFillColor(Color::Transparent);
    fire1.setPosition(path1.getPosition().x + 4.5, shape.getPosition().y - 120 * 5);
    fire2.setSize({ (float)window.getSize().x / 16,(float)window.getSize().y / 10 });
    fire2.setFillColor(Color::Transparent);
    fire2.setPosition(path0.getPosition().x + 4.5, shape.getPosition().y - 120 * 3);

    fireTexture.loadFromFile("SoulFire.png");

    objects.push_back(new Fire(fire0,fireTexture));
    objects.push_back(new Fire(fire1, fireTexture));
    objects.push_back(new Fire(fire2, fireTexture));
    objects[2]->SetPositionX(0);
    objects[2]->SetPositionY(3);
    objects[1]->SetPositionX(1);
    objects[1]->SetPositionY(1);
    objects[0]->SetPositionX(2);
    objects[0]->SetPositionY(0);
}

void Gameplay::InputGame(RenderWindow& window, Event& events) {
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
            else if (Keyboard::isKeyPressed(Keyboard::Space)) {
                player->ShadowStep();
            }
            break;
        default:
            break;
        }
    }
}



void Gameplay::UpdateGame(RenderWindow& window) {
    player->Update();
    for (int i = 0; i < objects.size(); i++) {
        objects[i]->InCollision(player);
        objects[i]->SetRandomPosition();
    }
    if (!player->GetIsAlive()) {
        goToMenu = true;
    }
    if ((int)(clock.getElapsedTime().asSeconds()) % 1 == 0 && (int)(clock.getElapsedTime().asSeconds()) != 0 && second != (int)clock.getElapsedTime().asSeconds()) {
        for (int i = 0; i < objects.size(); i++) {
            objects[i]->Movement();
        }
        second = clock.getElapsedTime().asSeconds();
    }
}

void Gameplay::DrawGame(RenderWindow& window) {
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
    for (int i = 0; i < objects.size(); i++) {
        window.draw(objects[i]->GetSprite());
    }
    window.display();
}

void Gameplay::DeInitGame() {
    
}


void Gameplay::UpdateDrawFrame(RenderWindow& window, Event& events) {
    Gameplay::InputGame(window, events);
    Gameplay::UpdateGame(window);
    Gameplay::DrawGame(window);
}

bool Gameplay::GoToMenu() {
    return goToMenu;
}

bool Gameplay::GoToGame() {
    return goToGame;
}