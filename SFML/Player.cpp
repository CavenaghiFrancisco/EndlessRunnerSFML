#include "Player.h"


Player::Player(int lives, sf::RectangleShape collider, bool isAlive) {
	this->lives = lives;
	this->collider = collider;
	this->isAlive = isAlive;
	this->positionX = 1;
	this->positionY = 6;
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
	if (positionY > 0)
	{
		collider.setPosition(collider.getPosition().x, collider.getPosition().y - 120);
		positionY--;
	}
}

void Player::MovePlayerDown() {
	if (positionY < 6)
	{
		collider.setPosition(collider.getPosition().x, collider.getPosition().y + 120);
		positionY++;
	}
}

void Player::MovePlayerLeft(RectangleShape path0, RectangleShape path1, RectangleShape path2) {
	if (positionX == 1) {
		collider.setPosition(path0.getPosition().x + 4.5, collider.getPosition().y);
		positionX = 0;
	}
	else if (positionX == 2) {
		collider.setPosition(path1.getPosition().x + 4.5, collider.getPosition().y);
		positionX = 1;
	}
}

void Player::MovePlayerRight(RectangleShape path0, RectangleShape path1, RectangleShape path2) {
	if (positionX == 0) {
		collider.setPosition(path1.getPosition().x + 4.5, collider.getPosition().y);
		positionX = 1;
	}
	else if (positionX == 1) {
		collider.setPosition(path2.getPosition().x + 4.5, collider.getPosition().y);
		positionX = 2;
	}
}

Sprite Player::GetSprite() {
	return sprite;
}

void Player::Update() {
	sprite.setPosition({ collider.getPosition().x, collider.getPosition().y });
}