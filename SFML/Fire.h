#pragma once
#include "SFML/Graphics.hpp"
#include <vector>

using namespace std;
using namespace sf;

class Fire {
private:
	Vector2f position;
	RectangleShape collider;
public:
	Fire(Vector2f position,RectangleShape collider);
	~Fire();
	void SetPosition(Vector2f position);
	Vector2f GetPosition();
};

