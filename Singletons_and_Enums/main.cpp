#include "gameState.h"
#include <iostream>
#include "main_Menu.h"
#include "options.h"
#include "raylib/raylib.h"

// -----***** Game Idea *****----- //
// This is gonna be the main menu for the game, I would have...
// ... to port this to my Assessable.
int main() {

	int screenWidth = 910;
	int screenHeight = 540;

	InitWindow(screenWidth, screenHeight, "Singletons & Enums");
	SetTargetFPS(60);
	
	// Sets the game to start in the Main Menu
	GameState::GetInstance().setState(0);
	if (GameState::GetInstance().getState() == 0) {
		std::cout << GameState::GetInstance().getState() << std::endl;
	}

	mainMenu mainMenuObject;
	options optionsObject;

	while (!WindowShouldClose()) {
		BeginDrawing();

		ClearBackground(SKYBLUE);
		
		SetWindowPosition(screenWidth / 2, screenHeight / 2);

		// If the Game State is 0 (Main Menu)
		if (GameState::GetInstance().getState() == 0) {
			mainMenuObject.update(GetFrameTime());
			mainMenuObject.draw(screenWidth / 4, screenHeight / 16);
		}

		//// If the Game State is 1 (Start -> Character Select)
		//if (GameState::GetInstance().getState() == 1) {
		//	mainMenuObject.update(GetFrameTime());
		//	mainMenuObject.draw(screenWidth / 4, screenHeight / 16);
		//}

		// If the Game State is 2 (Options)
		if (GameState::GetInstance().getState() == 2) {
			optionsObject.update(GetFrameTime());
			optionsObject.draw();
		}

		//// If the Game State is 6 (Game Exit)
		//if (GameState::GetInstance().getState() == 6) {
		//	CloseWindow();
		//	
		//	return 0;
		//}

		EndDrawing();
	}
	CloseWindow();

	return 0;
}