#include "Player.h"



Player::Player(int lives, sf::RectangleShape collider, bool isAlive) {
	this->lives = lives;
	this->collider = collider;
	this->isAlive = isAlive;
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
