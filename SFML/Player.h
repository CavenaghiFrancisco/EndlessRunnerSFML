#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

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
	float pausedTime;
	Texture texture;
	Texture textureShadow;
	Sprite sprite;
	Sprite spriteShadow;
	Clock shadowClock;
	Clock pausedClock;
	bool firstShadowStep;
	bool shadowAvailable;
	SoundBuffer shadowBuffer;
	Sound shadowSound;
public:
	//Linea bugeada
	Player(int lives, sf::RectangleShape collider, bool isAlive);
	//Linea bugeada
	~Player();
	int GetLives();
	void SetLives(int l);
	bool GetIsAlive();
	void SetIsAlive(bool alive);
	RectangleShape GetCollider();
	//Linea bugeada
	void MovePlayerUp();
	void MovePlayerDown();
	void MovePlayerLeft(RectangleShape path0, RectangleShape path1, RectangleShape path2);
	void MovePlayerRight(RectangleShape path0, RectangleShape path1, RectangleShape path2);
	Sprite GetSprite();
	bool GetIsShadow();
	void SetIsShadow(bool shadow);
	void ShadowStep();
	void Update(bool isPaused);
	int GetPositionX();
	int GetPositionY();
	int GetPoints();
	void SetPoints(int point);
	void SetShadowAvailable();
	bool GetShadowAvailable();
	
};

