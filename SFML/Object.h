#pragma once
#include "Player.h"
#include <vector>

using namespace std;

class Object {
protected:
	RectangleShape collider;
	Sprite sprite;
	int positionX;
	int positionY;
	int id;
public:
	Object(RectangleShape collider, Texture &texture, int id);
	~Object();
	RectangleShape GetCollider();
	Sprite GetSprite();
	void Movement();
	void UpdatePath(RectangleShape path0, RectangleShape path1, RectangleShape path2, vector<Object*> objects);
	void SetRandomPosition();
	int GetPositionX();
	void SetPositionX(int positionX);
	int GetPositionY();
	void SetPositionY(int positionY);
	virtual void InCollision(Player* player) = 0;
};

