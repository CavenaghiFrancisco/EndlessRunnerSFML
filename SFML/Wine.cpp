#include "Wine.h"

Wine::Wine(RectangleShape collider, Texture& texture, int id) : Object(collider,texture,id) {
    justSpawned == false;
    isCollected = false;
}

Wine::~Wine() {
}

void Wine::InCollision(Player* player) {
    if (player->GetPositionX() == positionX && player->GetPositionY() == positionY && !isCollected) {
        player->SetPoints(player->GetPoints() * 2 - player->GetPoints());
        isCollected = true;
    }
}

bool Wine::GetIsCollected() {
    return isCollected;
}

void Wine::JustSpawned() {
    if (positionY == 0 && !justSpawned) {
        isCollected = false;
        justSpawned = true;
    }
    else if (positionX == 1) {
        justSpawned = false;
    }
}
