#pragma once
#include "Object.h"

using namespace std;
using namespace sf;

class Fire : public Object {
public:
	Fire(RectangleShape collider, Texture &texture);
	~Fire();
	void InCollision(Player* player);
};

