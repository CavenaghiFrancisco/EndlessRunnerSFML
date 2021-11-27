#include "Coin.h"

Coin::Coin(RectangleShape collider, Texture& texture) : Object(collider,texture){
}

Coin::~Coin() {
}

void Coin::InCollision(Player* player) {
	if(!isCollected){
		player->SetPoints(1);
		isCollected = true;
	}
	
}

bool Coin::GetIsCollected() {
	return isCollected;
}
