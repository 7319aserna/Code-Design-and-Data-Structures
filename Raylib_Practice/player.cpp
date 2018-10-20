#include "player.h"
#include "raylib/raylib.h"

player::player() {
	texture = LoadTexture("mapTile_154.PNG");
}

player::~player() {
	UnloadTexture(texture);
}

void player::draw()
{
	DrawTexture(texture, playerPosition.x, playerPosition.y, WHITE);
}

void player::update(float deltaTime)
{
	if (IsKeyDown(KEY_W)) {
		movementSpeed -= playerPosition.y * deltaTime;
	}
	if (IsKeyDown(KEY_A)) {
		movementSpeed -= playerPosition.x * deltaTime;
	}
	if (IsKeyDown(KEY_S)) {
		movementSpeed += playerPosition.y * deltaTime;
	}
	if (IsKeyDown(KEY_D)) {
		movementSpeed += playerPosition.x * deltaTime;
	}
}
