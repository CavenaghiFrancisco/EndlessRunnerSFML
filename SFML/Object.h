#pragma once
#include "Player.h"

class Object {
protected:
	RectangleShape collider;
	Sprite sprite;
	int positionX;
	int positionY;
public:
	Object(RectangleShape collider, Texture &texture);
	~Object();
	RectangleShape GetCollider();
	Sprite GetSprite();
	void Movement();
	void SetRandomPosition();
	int GetPositionX();
	void SetPositionX(int positionX);
	int GetPositionY();
	void SetPositionY(int positionY);
	virtual void InCollision(Player* player) = 0;
};

