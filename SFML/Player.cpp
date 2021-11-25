#include "Player.h"

const int shadowTimeMax = 2000;

Player::Player(int lives, sf::RectangleShape collider, bool isAlive) {
	this->lives = lives;
	this->collider = collider;
	this->isAlive = isAlive;
	this->isShadow = false;
	this->positionX = 1;
	this->positionY = 6;
	this->shadowTime = 0;
	this->texture.loadFromFile("OrpheoIdle.png");
	this->sprite.setTexture(texture);
	this->textureShadow.loadFromFile("OrpheoShadow.png");
	this->spriteShadow.setTexture(textureShadow);
	spriteShadow.setPosition({ this->collider.getPosition().x,this->collider.getPosition().y });
	spriteShadow.setTextureRect({ 0,0,64,80 });
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
	if (GetIsShadow()) {
		return spriteShadow;
	}
	else {
		return sprite;
	}
	
}

bool Player::GetIsShadow() {
	return isShadow;
}

void Player::SetIsShadow(bool isShadow) {
	this->isShadow = isShadow;
}

void Player::ShadowStep() {
	SetIsShadow(!isShadow);
}

void Player::Update() {
	sprite.setPosition({ collider.getPosition().x, collider.getPosition().y });
	spriteShadow.setPosition({ collider.getPosition().x, collider.getPosition().y });
	if (isShadow)
	{
		shadowTime++;
	}
	if (shadowTime%shadowTimeMax==0)
	{
		SetIsShadow(false);
		shadowTime = 0;
	}
}

int Player::GetPositionX() {
	return positionX;
}

int Player::GetPositionY() {
	return positionY;
}
