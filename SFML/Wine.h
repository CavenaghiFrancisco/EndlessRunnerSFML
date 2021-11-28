#pragma once
#include "Object.h"

using namespace std;
using namespace sf;

class Wine : public Object {
private:
	bool isCollected;
	bool justSpawned;
public:
	Wine(RectangleShape collider, Texture& texture, int id);
	~Wine();
	void InCollision(Player* player);
	bool GetIsCollected();
	void JustSpawned();
};
