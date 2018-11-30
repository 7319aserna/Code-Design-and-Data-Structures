#include "gameState.h"
#include "bestLapLevel.h"
#include "mainMenu.h"
#include "raylib.h"

bestLapLevel::bestLapLevel() {
		SetWindowSize(1000, 750);

		highScoreTexture = LoadTexture("PNG/blue_button00.png");
		buttonTexture = LoadTexture("PNG/blue_button13.png");
		texture = LoadTexture("PNG/Cars/car_red_3.png");
}

bestLapLevel::~bestLapLevel()
{
	UnloadTexture(highScoreTexture);
	UnloadTexture(buttonTexture);
	UnloadTexture(texture);
}

void bestLapLevel::draw(raceTrack& racetrackReference)
{
	// --- Buttons --- //
	// Title Button
	DrawTextureEx(buttonTexture, { 0.0f, 0.0f }, 0.0f, 2.625f, WHITE);
	// Back Button
	DrawTextureEx(buttonTexture, { 300.0f, 637.5f }, 0.0f, 2.25f, WHITE);

	// --- Text --- //
	// Title Text
	DrawText("Best Lap", 25.0f, 25.0f, 75.0f, BLACK);
	// Back Text
	DrawText("Back", 450.0f, 675.0f, 50.0f, BLACK);
	// Best Lap Text
	DrawText("Best Lap: ", 275.0f, 150.0f, 45, BLACK);
	DrawText(FormatText("%.02f", racetrackReference.fastestLap), 275, 200, 45, BLACK);

	// --- Image --- //
	DrawTextureEx(texture, { 250.0f, 150.0f }, 90.0f, 1.5f, WHITE);
	//DrawTexture(texture, 500.0f, 281.25f, WHITE);
}

void bestLapLevel::update(float deltaTime)
{
	Rectangle buttonRectangleObject;

	// Make One button (Back Button)
	buttonRectangleObject.x = 300.0f;
	buttonRectangleObject.y = 637.5f;
	buttonRectangleObject.width = 500;
	buttonRectangleObject.height = 125;

	mousePoint = GetMousePosition();

	// Check collision between the mouse and the Back Button
	if (CheckCollisionPointRec(mousePoint, buttonRectangleObject) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
		GameState::GetInstance().setState(0);
	}
}