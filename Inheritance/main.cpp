#include "button.h"
#include <iostream>
#include "raylib/raylib.h"
#include "sprite.h"
#include <string>

int main() {
	int screenWidth = 910;
	int screenHeight = 540;

	InitWindow(screenWidth, screenHeight, "Inheritance");
	SetTargetFPS(60);

	std::string soliderFiles[] = { "soldier_walk1.PNG", "soldier_walk2.PNG" };
	sprite spriteObject(soliderFiles, 2, 60.0f);

	spriteObject.x = 77.0f;
	spriteObject.y = 77.0f;

	std::string buttonFiles[] = {"green_button00.PNG", "green_button01.PNG"};
	button buttonObject;
	buttonObject.x = 455.0f;
	buttonObject.y = 270.0f;
	button(buttonFiles, { buttonObject.x, buttonObject.y }, 2);

	while (!WindowShouldClose()) {
		BeginDrawing();

		ClearBackground(WHITE);

		spriteObject.update(GetFrameTime());
		spriteObject.draw();

		buttonObject.update(GetFrameTime());
		buttonObject.draw();
		buttonObject.checkForClick();

		EndDrawing();
	}
}