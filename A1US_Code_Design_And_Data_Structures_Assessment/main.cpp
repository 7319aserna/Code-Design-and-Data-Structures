#include "raylib/raylib.h"
#include <iostream>
#include "sprite.h"
#include <string>

using namespace::std;

int main() {
	int screenWidth = 910;
	int screenHeight = 540;

	InitWindow(screenWidth, screenHeight, "A1US - Code Design and Data Structures");
	SetTargetFPS(60);

	sprite playerCarObject;
	playerCarObject.mph = 0;
	playerCarObject.position = { 22.0f, 22.0f };

	while (!WindowShouldClose()) {
		BeginDrawing();

		ClearBackground(WHITE);

		playerCarObject.update(GetFrameTime());

		playerCarObject.draw();

		EndDrawing();
	}
	CloseWindow();

	return 0;
	/*
	// TODO: Make sure to put the race car files into the folder.
	string playerRaceCarFiles[] = {"car_blue_3.png"}
	*/
}