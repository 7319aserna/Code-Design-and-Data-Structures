#include <iostream>
#include "tile.h"
#include "raylib/raylib.h"

float screenWidth = 960.0f;
float screenHeight = 540.0f;

int main() {

	InitWindow(screenWidth, screenHeight, "Deep Vs Shallow Copy");
	SetTargetFPS(60);

	tile cactus("mappack/PNG/mapTile_035.png");
	tile popsicle("mappack/PNG/mapTile_045.png");
	tile snowman("mappack/PNG/mapTile_094.png");

	while (!WindowShouldClose()) {
		
		BeginDrawing();

		ClearBackground(WHITE);

		DrawTexture(cactus.texture, 0, 0, WHITE);

		EndDrawing();
	}
}