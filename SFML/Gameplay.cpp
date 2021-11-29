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
    isPaused = false;
    goToGame = false;
    gameOver = false;
    second = 0;
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
    shape.setPosition((float)(path1.getPosition().x + 4.5), (float)(shape.getPosition().y + 120 * 6));
    player = new Player(3, shape, true);

    fire0.setSize({ (float)window.getSize().x / 16,(float)window.getSize().y / 10 });
    fire0.setFillColor(Color::Transparent);
    fire0.setPosition((float)(path2.getPosition().x + 4.5), (float)(shape.getPosition().y - 120 * 7));
    fire1.setSize({ (float)window.getSize().x / 16,(float)window.getSize().y / 10 });
    fire1.setFillColor(Color::Transparent);
    fire1.setPosition((float)(path1.getPosition().x + 4.5), (float)(shape.getPosition().y - 120 * 8));
    fire2.setSize({ (float)window.getSize().x / 16,(float)window.getSize().y / 10 });
    fire2.setFillColor(Color::Transparent);
    fire2.setPosition((float)(path0.getPosition().x + 4.5), (float)(shape.getPosition().y - 120 * 9));
    fire3.setSize({ (float)window.getSize().x / 16,(float)window.getSize().y / 10 });
    fire3.setFillColor(Color::Transparent);
    fire3.setPosition((float)(path2.getPosition().x + 4.5), (float)(shape.getPosition().y - 120 * 10));
    fire4.setSize({ (float)window.getSize().x / 16,(float)window.getSize().y / 10 });
    fire4.setFillColor(Color::Transparent);
    fire4.setPosition((float)(path1.getPosition().x + 4.5), (float)(shape.getPosition().y - 120 * 11));
    fire5.setSize({ (float)window.getSize().x / 16,(float)window.getSize().y / 10 });
    fire5.setFillColor(Color::Transparent);
    fire5.setPosition((float)(path0.getPosition().x + 4.5), (float)(shape.getPosition().y - 120 * 12));
    fire6.setSize({ (float)window.getSize().x / 16,(float)window.getSize().y / 10 });
    fire6.setFillColor(Color::Transparent);
    fire6.setPosition((float)(path0.getPosition().x + 4.5), (float)(shape.getPosition().y - 120 * 13));
    coin0.setSize({ (float)window.getSize().x / 16,(float)window.getSize().y / 10 });
    coin0.setFillColor(Color::Transparent);
    coin0.setPosition((float)(path2.getPosition().x + 4.5), (float)(shape.getPosition().y - 120 * 8));
    coin1.setSize({ (float)window.getSize().x / 16,(float)window.getSize().y / 10 });
    coin1.setFillColor(Color::Transparent);
    coin1.setPosition((float)(path2.getPosition().x + 4.5), (float)(shape.getPosition().y - 120 * 10));
    coin2.setSize({ (float)window.getSize().x / 16,(float)window.getSize().y / 10 });
    coin2.setFillColor(Color::Transparent);
    coin2.setPosition((float)(path2.getPosition().x + 4.5), (float)(shape.getPosition().y - 120 * 12));
    wine.setSize({ (float)window.getSize().x / 16,(float)window.getSize().y / 10 });
    wine.setFillColor(Color::Transparent);
    wine.setPosition((float)(path2.getPosition().x + 4.5), (float)(shape.getPosition().y - 120 * 11));

    lava.loadFromFile("Lava.png");
    lava.setRepeated(true);
    path.loadFromFile("Stone.png");
    path.setRepeated(true);
    fireTexture.loadFromFile("SoulFire.png");
    coinTexture.loadFromFile("Coin.png");
    wineTexture.loadFromFile("Wine.png");
    unpausedTexture.loadFromFile("Unpaused.png");
    unpausedGreyTexture.loadFromFile("UnpausedGrey.png");
    pausedTexture.loadFromFile("Paused.png");
    pausedGreyTexture.loadFromFile("PausedGrey.png");
    restartTexture.loadFromFile("Restart.png");
    restartGreyTexture.loadFromFile("RestartGrey.png");
    halfScreen.setTexture(unpausedTexture);
    halfScreen.setPosition((float)(window.getSize().x / 2), 0);

    font.loadFromFile("greek.ttf");

    text.setFont(font);
    text.setCharacterSize(40);
    text.setFillColor({223, 154, 16, 255});
    text.setPosition((float)(window.getSize().x - 200), 120);

    spritePath0.setTexture(path);
    spritePath0.setTextureRect({ (int)150,(int)0,(int)path0.getSize().x+5,(int)path0.getSize().y });
    spritePath0.setPosition(path0.getPosition().x,0);
    spritePath1.setTexture(path);
    spritePath1.setTextureRect({ (int)150,(int)0,(int)path1.getSize().x+5,(int)path1.getSize().y });
    spritePath1.setPosition(path1.getPosition().x, 0);
    spritePath2.setTexture(path);
    spritePath2.setTextureRect({ (int)150,(int)0,(int)path2.getSize().x+5,(int)path2.getSize().y });
    spritePath2.setPosition(path2.getPosition().x, 0);
    spriteLava0.setTexture(lava);
    spriteLava0.setTextureRect({(int)0,(int)0,(int)lava0.getSize().x,(int)lava0.getSize().y});
    spriteLava0.setPosition(lava0.getPosition().x, 0);
    spriteLava1.setTexture(lava);
    spriteLava1.setTextureRect({ (int)lava1.getPosition().x,(int)0,(int)lava1.getSize().x,(int)lava1.getSize().y });
    spriteLava1.setPosition(lava1.getPosition().x, 0);
    spriteLava2.setTexture(lava);
    spriteLava2.setTextureRect({ (int)lava2.getPosition().x,(int)0,(int)lava2.getSize().x,(int)lava2.getSize().y });
    spriteLava2.setPosition(lava2.getPosition().x, 0);
    spriteLava3.setTexture(lava);
    spriteLava3.setTextureRect({ (int)lava3.getPosition().x,(int)0,(int)lava3.getSize().x,(int)lava3.getSize().y });
    spriteLava3.setPosition(lava3.getPosition().x, 0);

    objects.push_back(new Fire(fire0,fireTexture,0));
    objects.push_back(new Fire(fire1, fireTexture,1));
    objects.push_back(new Fire(fire2, fireTexture, 2));
    objects.push_back(new Fire(fire3, fireTexture, 3));
    objects.push_back(new Fire(fire4, fireTexture, 4));
    objects.push_back(new Fire(fire5, fireTexture, 5));
    objects.push_back(new Fire(fire6, fireTexture, 6));
    objects.push_back(new Coin(coin0, coinTexture, 7));
    objects.push_back(new Coin(coin1, coinTexture, 8));
    objects.push_back(new Coin(coin2, coinTexture, 9));
    objects.push_back(new Wine(wine, wineTexture, 10));
    objects[0]->SetPositionY(-1);
    objects[1]->SetPositionY(-2);
    objects[2]->SetPositionY(-3);
    objects[3]->SetPositionY(-4);
    objects[4]->SetPositionY(-5);
    objects[5]->SetPositionY(-6);
    objects[6]->SetPositionY(-7);
    objects[7]->SetPositionY(-2);
    objects[8]->SetPositionY(-4);
    objects[9]->SetPositionY(-6);
    objects[10]->SetPositionY(-5);

    menuButton = new Button((float)window.getSize().x-310, (float)window.getSize().y - 150, 120, 60);
    resumeButton = new Button((float)window.getSize().x - 320, (float)window.getSize().y - 230, 130, 60);

    initialBuffer.loadFromFile("Audio/SelectionSound.wav");
    initialSound.setBuffer(initialBuffer);
    deathBuffer.loadFromFile("Audio/DeathSound.wav");
    deathSound.setBuffer(deathBuffer);
    deathSound.setVolume(150);
    initialSound.play();
    gameMusic.openFromFile("Audio/GameMusic.wav");
    gameMusic.setVolume(80);
    gameMusic.setLoop(true);
    gameMusic.play();
}

void Gameplay::InputGame(RenderWindow& window, Event& events) {
    while (window.pollEvent(events)) {
        switch (events.type) {
        case Event::Closed:
            window.close();
            break;
        case Event::KeyPressed:
            if (!isPaused) {
                if (Keyboard::isKeyPressed(Keyboard::W)) {
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
            }
            break;
        case Event::MouseButtonPressed:
            if (menuButton->IsClicked(window)) {
                goToMenu = true;
            }
            else if (resumeButton->IsClicked(window)) {
                if (!gameOver) {
                    isPaused = !isPaused;
                }
                else {
                    goToGame = true;
                }
            }
            break;
        default:
            break;
        }
    }
}



void Gameplay::UpdateGame() {
    if(!isPaused && !gameOver){
        if (!player->GetIsAlive()) {
            gameOver = true;
        }
        player->Update(isPaused);
        if (player->GetShadowAvailable()) {
            halfScreen.setTexture(unpausedTexture);
        }
        else {
            halfScreen.setTexture(unpausedGreyTexture);
        }
        for (size_t i = 0; i < objects.size(); i++) {
            Wine* winee = dynamic_cast<Wine*>(objects[i]);
            Coin* coin = dynamic_cast<Coin*>(objects[i]);
            if (coin) {
                coin->JustSpawned();
            }
            else if (winee) {
                winee->JustSpawned();
            }
            objects[i]->InCollision(player);
            if (!player->GetIsAlive()) {
                gameMusic.stop();
                deathSound.play();
            }
            objects[i]->SetRandomPosition();
            objects[i]->UpdatePath(path0,path1,path2, objects);
        }
        if ((int)(clock.getElapsedTime().asSeconds()) % 1 == 0 && (int)(clock.getElapsedTime().asSeconds()) != 0 && second != (int)clock.getElapsedTime().asSeconds()) {
            for (size_t i = 0; i < objects.size(); i++) {
                objects[i]->Movement();
            }
            second = (int)clock.getElapsedTime().asSeconds();
        }
    }
    else if (isPaused) {
        player->Update(isPaused);
        if (player->GetShadowAvailable()) {
            halfScreen.setTexture(pausedTexture);
        }
        else {
            halfScreen.setTexture(pausedGreyTexture);
        }
        
    }
    else if (gameOver) {
        if (player->GetShadowAvailable()) {
            halfScreen.setTexture(restartTexture);
        }
        else {
            halfScreen.setTexture(restartGreyTexture);
        }
    }
    text.setString(to_string(player->GetPoints()));
}

void Gameplay::DrawGame(RenderWindow& window) {
    window.clear();
    window.draw(lava0);
    window.draw(spriteLava0);
    window.draw(lava1);
    window.draw(spriteLava1);
    window.draw(lava2);
    window.draw(spriteLava2);
    window.draw(lava3);
    window.draw(spriteLava3);
    window.draw(path0);
    window.draw(spritePath0);
    window.draw(path1);
    window.draw(spritePath1);
    window.draw(path2);
    window.draw(spritePath2);
    window.draw(player->GetCollider());
    window.draw(player->GetSprite());
    for (size_t i = 0; i < objects.size(); i++) {
        Wine* winee = dynamic_cast<Wine*>(objects[i]);
        Coin* coin = dynamic_cast<Coin*>(objects[i]);
        if (coin) {
            if (!coin->GetIsCollected()) {
                window.draw(coin->GetSprite());
            }   
        }
        else if (winee) {
            if (!winee->GetIsCollected()) {
                window.draw(winee->GetSprite());
            }
        }
        else {
            window.draw(objects[i]->GetSprite());
        }
        
    }
    window.draw(halfScreen);
    window.draw(text);
    window.display();
}

void Gameplay::DeInitGame() {
    
}


void Gameplay::UpdateDrawFrame(RenderWindow& window, Event& events) {
    Gameplay::InputGame(window, events);
    Gameplay::UpdateGame();
    Gameplay::DrawGame(window);
}

bool Gameplay::GoToMenu() {
    return goToMenu;
}

bool Gameplay::GoToGame() {
    return goToGame;
}
