#include <iostream>
#include "player.h"
#include "raylib/raylib.h"
#include "wizard.h"

int main() {
	int screenWidth = 960;
	int screenHeight = 540;

	InitWindow(screenWidth, screenHeight, "Raylib Practice");
	SetTargetFPS(60);

	player playerObject;

	playerObject.position.x = 750;
	playerObject.position.y = 500;
	//playerObject.playerFileName = "knight_f_idle_anim_f0.png";

	player("knight_f_idle_anim_f0.png");

	while (!WindowShouldClose()) {
		BeginDrawing();

		ClearBackground(WHITE);

		playerObject.draw();

		EndDrawing();
	}
	CloseWindow();

	return 0;
}