#pragma once
#include "Object.h"

using namespace std;
using namespace sf;

class Coin : public Object {
private:
	bool isCollected;
	bool justSpawned;
public:
	Coin(RectangleShape collider, Texture& texture, int id);
	~Coin();
	void InCollision(Player* player);
	bool GetIsCollected();
	void JustSpawned();
};

