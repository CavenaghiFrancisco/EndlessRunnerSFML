#include "Player.h"

Player::Player(int lives, sf::RectangleShape collider, bool isAlive) {
	this->lives = lives;
	this->collider = collider;
	this->isAlive = isAlive;
	this->position = 1;
    this->texture.loadFromFile("OrpheoIdle.png");
    this->sprite.setTexture(texture);
    sprite.setPosition({ this->collider.getPosition().x,this->collider.getPosition().y });
    sprite.setTextureRect({ 0,0,64,80 });
}

Player::~Player() {
}

int Player::GetLives() {
	return lives;
}

void Player::SetLives(int lives) {
	this->lives = lives;
}

bool Player::GetIsAlive() {
	return isAlive;
}

void Player::SetIsAlive(bool isAlive) {
	this->isAlive = isAlive;
}

RectangleShape Player::GetCollider() {
	return collider;
}

void Player::MovePlayerUp() {
    collider.setPosition(collider.getPosition().x, collider.getPosition().y - 120);
}

void Player::MovePlayerDown() {
    collider.setPosition(collider.getPosition().x, collider.getPosition().y + 120);
}

void Player::MovePlayerLeft(RectangleShape path0, RectangleShape path1, RectangleShape path2) {
    if (position == 1) {
        collider.setPosition(path0.getPosition().x + 4.5, collider.getPosition().y);
        position = 0;
    }
    else if (position == 2) {
        collider.setPosition(path1.getPosition().x + 4.5, collider.getPosition().y);
        position = 1;
    }
}

void Player::MovePlayerRight(RectangleShape path0, RectangleShape path1, RectangleShape path2) {
    if (position == 0) {
        collider.setPosition(path1.getPosition().x + 4.5, collider.getPosition().y);
        position = 1;
    }
    else if (position == 1) {
        collider.setPosition(path2.getPosition().x + 4.5, collider.getPosition().y);
        position = 2;
    }
}

Sprite Player::GetSprite() {
    return sprite;
}

void Player::Update() {
    sprite.setPosition({ collider.getPosition().x, collider.getPosition().y });
}