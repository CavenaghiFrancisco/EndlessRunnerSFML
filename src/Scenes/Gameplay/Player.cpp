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
	this->texture.loadFromFile("Assets/Image/OrpheoIdle.png");
	this->sprite.setTexture(texture);
	this->textureShadow.loadFromFile("Assets/Image/OrpheoShadow.png");
	this->spriteShadow.setTexture(textureShadow);
	spriteShadow.setPosition({ this->collider.getPosition().x,this->collider.getPosition().y });
	spriteShadow.setTextureRect({ 0,0,64,80 });
	sprite.setPosition({ this->collider.getPosition().x,this->collider.getPosition().y });
	sprite.setTextureRect({ 0,0,64,80 });
	firstShadowStep = true;
	shadowAvailable = true;
	pausedTime = 0;
	points = 0;
	shadowBuffer.loadFromFile("Assets/Audio/ShadowSound.wav");
	shadowSound.setBuffer(shadowBuffer);
	shadowSound.setVolume(150);
}

Player::~Player() {
}

int Player::GetLives() {
	return lives;
}

void Player::SetLives(int l) {
	this->lives = l;
}

bool Player::GetIsAlive() {
	return isAlive;
}

void Player::SetIsAlive(bool alive) {
	this->isAlive = alive;
}

RectangleShape Player::GetCollider() {
	return collider;
}

void Player::MovePlayerUp() {
	if (positionY > 0)
	{
		collider.setPosition((float)collider.getPosition().x, (float)(collider.getPosition().y - 120));
		positionY--;
	}
}

void Player::MovePlayerDown() {
	if (positionY < 6)
	{
		collider.setPosition((float)collider.getPosition().x, (float)(collider.getPosition().y + 120));
		positionY++;
	}
}

void Player::MovePlayerLeft(RectangleShape path0, RectangleShape path1, RectangleShape path2) {
	if (positionX == 1) {
		collider.setPosition((float)(path0.getPosition().x + 4.5), (float)collider.getPosition().y);
		positionX = 0;
	}
	else if (positionX == 2) {
		collider.setPosition((float)(path1.getPosition().x + 4.5), (float)collider.getPosition().y);
		positionX = 1;
	}
}

void Player::MovePlayerRight(RectangleShape path0, RectangleShape path1, RectangleShape path2) {
	if (positionX == 0) {
		collider.setPosition((float)(path1.getPosition().x + 4.5), (float)collider.getPosition().y);
		positionX = 1;
	}
	else if (positionX == 1) {
		collider.setPosition((float)(path2.getPosition().x + 4.5), (float)collider.getPosition().y);
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

void Player::SetIsShadow(bool shadow) {
	this->isShadow = shadow;
}

void Player::ShadowStep() {
	if (firstShadowStep) {
		SetIsShadow(!isShadow);
		shadowClock.restart();
		firstShadowStep = false;
		shadowAvailable = false;
		pausedTime = 0;
		shadowSound.play();
	}
	else if(shadowClock.getElapsedTime().asSeconds() > 8) {
		SetIsShadow(!isShadow);
		shadowAvailable = false;
		shadowClock.restart();
		pausedTime = 0;
		shadowSound.play();
	}
}

void Player::Update(bool isPaused) {
	if (!isPaused) {
		pausedClock.restart();
	}
	if (pausedClock.getElapsedTime().asSeconds() > 0.3) {
		pausedTime = pausedClock.getElapsedTime().asSeconds();
	}
	sprite.setPosition({ collider.getPosition().x, collider.getPosition().y });
	spriteShadow.setPosition({ collider.getPosition().x, collider.getPosition().y });
	if (isShadow && shadowClock.getElapsedTime().asSeconds() - pausedTime > 3) {
		SetIsShadow(!isShadow);
	}
	SetShadowAvailable();
}

int Player::GetPositionX() {
	return positionX;
}

int Player::GetPositionY() {
	return positionY;
}

void Player::SetPoints(unsigned int point) {
	this->points += point;
}

unsigned int Player::GetPoints() {
	return points;
}

void Player::SetShadowAvailable() {
	if (shadowClock.getElapsedTime().asSeconds() - pausedTime > 8 || firstShadowStep) {
		shadowAvailable = true;
	}
}

bool Player::GetShadowAvailable() {
	return shadowAvailable;
}