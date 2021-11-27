#pragma once
#include "Object.h"

using namespace std;
using namespace sf;

class Coin : public Object {
private:
	bool isCollected;
public:
	Coin(RectangleShape collider, Texture& texture);
	~Coin();
	void InCollision(Player* player);
	bool GetIsCollected();
};

