#pragma once
#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"

#include "Object.h"

using namespace sf;

class Wine : public Object {
private:
	bool isCollected;
	bool justSpawned;
	SoundBuffer wineBuffer;
	Sound wineSound;
public:
	Wine(RectangleShape collider, Texture& texture, int id);
	~Wine();
	void InCollision(Player* player);
	bool GetIsCollected();
	void JustSpawned();
};
