#pragma once
#include "SFML/Graphics.hpp"

using namespace sf;

//hacerlo derivada de object
class Player {
private:
	int lives;
	RectangleShape collider;
	bool isAlive;
	bool isShadow;
	int points;
	int positionX;
	int positionY;
	int shadowTime;	
	Texture texture;
	Texture textureShadow;
	Sprite sprite;
	Sprite spriteShadow;
	Clock shadowClock;
	bool firstShadowStep;
public:
	//Linea bugeada
	Player(int lives, sf::RectangleShape collider, bool isAlive);
	//Linea bugeada
	~Player();
	int GetLives();
	void SetLives(int lives);
	bool GetIsAlive();
	void SetIsAlive(bool isAlive);
	RectangleShape GetCollider();
	//Linea bugeada
	void MovePlayerUp();
	void MovePlayerDown();
	void MovePlayerLeft(RectangleShape path0, RectangleShape path1, RectangleShape path2);
	void MovePlayerRight(RectangleShape path0, RectangleShape path1, RectangleShape path2);
	Sprite GetSprite();
	bool GetIsShadow();
	void SetIsShadow(bool isShadow);
	void ShadowStep();
	void Update();
	int GetPositionX();
	int GetPositionY();
	int GetPoints();
	void SetPoints(int points);
	
};

