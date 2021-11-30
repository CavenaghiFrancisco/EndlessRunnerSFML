#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

using namespace sf;

class Player {
private:
	int lives;
	unsigned int points;
	int positionX;
	int positionY;
	int shadowTime;	
	float pausedTime;
	bool isAlive;
	bool isShadow;
	bool firstShadowStep;
	bool shadowAvailable;
	RectangleShape collider;
	Texture texture;
	Texture textureShadow;
	Sprite sprite;
	Sprite spriteShadow;
	Clock shadowClock;
	Clock pausedClock;
	SoundBuffer shadowBuffer;
	Sound shadowSound;
public:
	Player(int lives, sf::RectangleShape collider, bool isAlive);
	~Player();
	int GetLives();
	void SetLives(int l);
	bool GetIsAlive();
	void SetIsAlive(bool alive);
	RectangleShape GetCollider();
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
	unsigned int GetPoints();
	void SetPoints(unsigned int point);
	void SetShadowAvailable();
	bool GetShadowAvailable();
};

