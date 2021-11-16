#include "Game.h"
#include <cmath>


bool gameOver = false;
bool pause = false;
bool victory = false;

Game::Game() {
    gameInited = false;
    gameOver = false;
}

Game::~Game() {
    
}

bool Game::GetInited() {
    return gameInited;
}

void Game::InitGame() {
    victory = false;
    pause = false;
    timerPowerUp = 0.0f;
    
}

void Game::InputGame() {
    if (pause) {
        
    }
    if (victory) {
        
    }
    if (gameOver) {
    
    }
}



void Game::UpdateGame() {
   
}

void Game::DrawGame() {
   
}

void Game::DeInitGame() {
    
}


void Game::UpdateDrawFrame() {
    Game::InputGame();
    Game::UpdateGame();
    Game::DrawGame();
}

bool Game::GoToMenu() {
    return goToMenu;
}

bool Game::GoToGame() {
    return goToGame;
}