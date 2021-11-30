#pragma once

#include "SFML/Graphics.hpp"

#include "Object.h"

using namespace std;
using namespace sf;

class Fire : public Object {
public:
	Fire(RectangleShape collider, Texture &texture, int id);
	~Fire();
	void InCollision(Player* player);
};

