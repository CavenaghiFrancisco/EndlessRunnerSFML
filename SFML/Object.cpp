#include "Object.h"

Object::Object(RectangleShape collider, Texture &texture) {
	this->collider = collider;
	this->sprite.setTexture(texture);
	positionX = 0;
	positionY = 0;
	sprite.setPosition({ this->collider.getPosition().x,this->collider.getPosition().y });
	sprite.setTextureRect({ 0,0,64,80 });
}

Object::~Object() {
}

RectangleShape Object::GetCollider() {
	return collider;
}

Sprite Object::GetSprite() {
	return sprite;
}

void Object::Movement() {
}

void Object::SetRandomPosition() {
}

int Object::GetPositionX() {
	return positionX;
}

void Object::SetPositionX(int positionX) {
	this->positionX = positionX;
}

int Object::GetPositionY() {
	return positionY;
}

void Object::SetPositionY(int positionY) {
	this->positionY = positionY;
}
