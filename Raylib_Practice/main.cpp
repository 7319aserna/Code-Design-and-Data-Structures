#include <iostream>
#include "player.h"
#include "raylib/raylib.h"

int main() {
	int screenWidth = 960;
	int screenHeight = 540;

	InitWindow(screenWidth, screenHeight, "Raylib Practice");
		SetTargetFPS(60);

		player playerObject;
		playerObject.movementSpeed = 22;
		playerObject.playerPosition = { 25, 25 };

		while (!WindowShouldClose()) {
			BeginDrawing();

			ClearBackground(WHITE);

			playerObject.update(GetFrameTime());

			playerObject.draw();

			EndDrawing();
	}
	CloseWindow();

	return 0;
}
