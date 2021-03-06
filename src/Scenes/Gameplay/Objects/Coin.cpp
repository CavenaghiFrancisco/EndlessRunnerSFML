#include "Coin.h"

Coin::Coin(RectangleShape collider, Texture& texture, int id) : Object(collider,texture,id){
	justSpawned = false;
	isCollected = false;
}

Coin::~Coin() {
}

void Coin::InCollision(Player* player) {
	if(player->GetPositionX() == positionX && player->GetPositionY() == positionY && !isCollected){
		player->SetPoints(10);
		isCollected = true;
	}
}

bool Coin::GetIsCollected() {
	return isCollected;
}

void Coin::JustSpawned() {
	if (positionY == 7 && !justSpawned) {
		isCollected = false;
		justSpawned = true;
	}
	else if (positionX == 0) {
		justSpawned = false;
	}
}


