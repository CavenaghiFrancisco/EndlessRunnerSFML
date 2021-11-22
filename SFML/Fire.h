#pragma once
#include "SFML/Graphics.hpp"
#include <vector>

using namespace std;
using namespace sf;

class Fire {
private:
	RectangleShape collider;
	bool isInTheMap;
	Sprite sprite;
public:
	Fire(RectangleShape collider, Texture &texture);
	~Fire();
	RectangleShape GetCollider();
	bool GetIsInTheMap();
	void SetIsInTheMap(bool isInTheMap);
	Sprite GetSprite();
};

