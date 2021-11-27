#include "Fire.h"

Fire::Fire(RectangleShape collider, Texture &texture, int id) : Object(collider, texture, id) {
}

Fire::~Fire() {
}

void Fire::InCollision(Player* player) {
	if (player->GetPositionX() == positionX && player->GetPositionY() == positionY && !player->GetIsShadow()) {
		player->SetIsAlive(false);
	}
}





