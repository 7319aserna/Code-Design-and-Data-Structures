#include <iostream>
#include "tile.h"
#include "raylib/raylib.h"

int screenWidth = 960;
int screenHeight = 540;

int main() {

	InitWindow(screenWidth, screenHeight, "Deep Vs Shallow Copy");
	SetTargetFPS(60);

	tile cactus("mappack/PNG/mapTile_035.png");
	tile popsicle("mappack/PNG/mapTile_045.png");
	tile snowman("mappack/PNG/mapTile_094.png");

	// grid width is now 8 in this instance
	int cellsPerRow = screenHeight / 64;
	// gird height is now 15 in this instance
	int cellsPerColumn= screenWidth / 64;

	// Use the tile class to make a new array which will then store...
	// ... the types of tiles there are.
	tile types[3];
	types[0] = cactus;
	types[1] = popsicle;
	types[2] = snowman;

	// You then make a new int array (grid) which will have positions...
	// ... to put your texture into it.
	int grid[3][3];
	grid[0][0] = 0;
	grid[1][0] = 1;
	grid[2][0] = 2;

	grid[0][1] = 2;
	grid[1][1] = 1;
	grid[2][1] = 2;

	grid[0][2] = 2;
	grid[1][2] = 1;
	grid[2][2] = 0;

	while (!WindowShouldClose()) {
		
		BeginDrawing();

		ClearBackground(WHITE);

		// The starter cell's x position
		int cellPositionX = 0;

		// Where the cell's x postition originally started
		int cellOriginalPositionX = cellPositionX;

		// The starter cell's y position
		int cellPositionY = 0;

		// Where the cell's y postition originally started
		int cellOriginalPositionY = cellPositionY;

		// This would start off at the first row
		for (int s = 0; s < 3; s++) {
			// Then it would iterate through each cell (Column)
			for (int j = 0; j < 3; j++) {

				DrawTexture(types[grid[s][j]].texture, cellPositionY, cellPositionX, WHITE);

				cellPositionX += 64;
			}
			cellPositionX = 0;
			cellPositionY += 64;
		}

		EndDrawing();
	}
}