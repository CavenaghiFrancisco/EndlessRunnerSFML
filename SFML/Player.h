#pragma once
#include "SFML/Graphics.hpp"

using namespace sf;

class Player {
private:
	int lives;
	RectangleShape collider;
	bool isAlive;
public:
	Player(int lives, sf::RectangleShape collider, bool isAlive);

	~Player();
	int GetLives();
	void SetLives(int lives);
	bool GetIsAlive();
	void SetIsAlive(bool isAlive);
	RectangleShape GetCollider();
	
};

