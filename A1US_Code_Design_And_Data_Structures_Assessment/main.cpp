#include "race.h"
#include "mapCreator.h"
#include "player.h"
#include "raylib.h"
#include "tVector.h"
#include <iostream>
#include <string>
#include <vector>

using namespace::std;

int main() {
	int screenWidth = 1000;
	int screenHeight = 1000;

	InitWindow(screenWidth, screenHeight, "A1US - Code Design and Data Structures");
	SetTargetFPS(60);

	race r_Object;
	mapCreator mC_Object;
	player p_Object;

	while (!WindowShouldClose()) {
		// Update
		//----------------------------------------------------------------------------------
		mC_Object.update(GetFrameTime(), screenWidth / 2, screenHeight / 2);
		p_Object.update(GetFrameTime());
		r_Object.update(GetFrameTime(), p_Object);

		BeginDrawing();

		ClearBackground(WHITE);

		mC_Object.draw();
		p_Object.draw();
		r_Object.draw();

		EndDrawing();
	}
	CloseWindow();

	return 0;
}