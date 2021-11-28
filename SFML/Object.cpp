#include "Object.h"


Object::Object(RectangleShape collider, Texture &texture, int id) {
	srand(time(NULL));
	this->collider = collider;
	this->sprite.setTexture(texture);
	this->id = id;
	positionX = rand() % 3;
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
	collider.setPosition(collider.getPosition().x, collider.getPosition().y + 120);
	positionY++;
	sprite.setPosition({ collider.getPosition().x,collider.getPosition().y });
}

void Object::UpdatePath(RectangleShape path0, RectangleShape path1, RectangleShape path2, vector<Object*> objects) {
	srand(time(NULL));
	for (int i = 0; i < objects.size(); i++) {
		if (objects[i]->positionY == positionY && id != objects[i]->id) {
			while (positionX == objects[i]->positionX) {
				this->positionX = rand() % 3;
			}
		}
	}
	switch (positionX) {
	case 0:
		collider.setPosition(path0.getPosition().x + 4.5, collider.getPosition().y);
		break;
	case 1:
		collider.setPosition(path1.getPosition().x + 4.5, collider.getPosition().y);
		break;
	case 2:
		collider.setPosition(path2.getPosition().x + 4.5, collider.getPosition().y);
		break;
	}
	collider.setPosition(collider.getPosition().x, collider.getPosition().y);
	sprite.setPosition({ collider.getPosition().x,collider.getPosition().y });
}

void Object::SetRandomPosition() {
	srand(time(NULL));
	if (positionY >= 7) {
		positionY = 0;
		positionX = rand() % 3;
		collider.setPosition(collider.getPosition().x, 0);
		sprite.setPosition({ collider.getPosition().x,collider.getPosition().y });
	}
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
