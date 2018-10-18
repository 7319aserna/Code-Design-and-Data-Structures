#include <iostream>
#include "raylib/raylib.h"
#include "sprite.h"

int main() {
	int screenWidth = 910;
	int screenHeight = 540;

	InitWindow(screenWidth, screenHeight, "Inheritance");
	SetTargetFPS(60);

	std::string soliderFiles[] = { "soldier_walk1.PNG", "soldier_walk2.PNG" };
	sprite spriteObject(soliderFiles, 2, 60.0f);

	while (!WindowShouldClose()) {
		BeginDrawing();

		ClearBackground(WHITE);

		spriteObject.draw();

		EndDrawing();
	}
}