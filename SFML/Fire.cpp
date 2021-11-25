#include "Fire.h"

Fire::Fire(RectangleShape collider, Texture &texture) : Object(collider, texture) {
}

Fire::~Fire() {
}

void Fire::InCollision(Player* player) {
	if (player->GetPositionX() == positionX && player->GetPositionY() == positionY && !player->GetIsShadow()) {
		player->SetIsAlive(false);
	}
}





