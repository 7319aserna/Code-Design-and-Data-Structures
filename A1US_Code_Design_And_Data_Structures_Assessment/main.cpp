#include "libraries.h"

using namespace::std;

int main() {
	int screenWidth = 1000;
	int screenHeight = 1000;

	InitWindow(screenWidth, screenHeight, "A1US - Code Design and Data Structures");
	SetTargetFPS(60);

	// Sets the game to start in the Main Menu
	GameState::GetInstance().setState(0);

	mapCreator mapCreatorObject;
	raceTrack raceTrackObject;
	player playerObject;

	while (!WindowShouldClose()) {
		// If the Game State is 0 (Main Menu)
		if (GameState::GetInstance().getState() == 0) {
			mainMenu mainMenuObject;
			mainMenuObject.update(GetFrameTime());
			BeginDrawing();
			ClearBackground(BEIGE);
			mainMenuObject.draw(screenWidth / 4, screenHeight / 16);
			EndDrawing();
		}

		// If the Game State is 1 (Start Game)
		if (GameState::GetInstance().getState() == 1) {
		mapCreatorObject.update(GetFrameTime(), screenWidth / 2, screenHeight / 2);
		playerObject.update(GetFrameTime());
		raceTrackObject.update(GetFrameTime(), playerObject);

		BeginDrawing();
		ClearBackground(WHITE);
		mapCreatorObject.draw();
		playerObject.draw();
		raceTrackObject.draw();
		EndDrawing();
		}

		// If the Game State is 2 (Exit Game)
		if (GameState::GetInstance().getState() == 2) {
			CloseWindow();
			return 0;
		}
	}
	CloseWindow();

	return 0;
}