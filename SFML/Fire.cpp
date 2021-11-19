#include "Fire.h"

Fire::Fire(RectangleShape collider) {
	this->collider = collider;
	this->texture.loadFromFile("SoulFire.png");
	this->sprite.setTexture(texture);
	sprite.setPosition({ this->collider.getPosition().x,this->collider.getPosition().y });
	sprite.setTextureRect({ 0,0,64,80 });
}

Fire::~Fire() {
}

RectangleShape Fire::GetCollider() {
	return collider;
}

bool Fire::GetIsInTheMap() {
	return isInTheMap;
}

void Fire::SetIsInTheMap(bool isInTheMap) {
	this->isInTheMap = isInTheMap;
}

Sprite Fire::GetSprite() {
	return sprite;
}


