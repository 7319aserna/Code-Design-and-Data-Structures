#include "gameState.h"
#include "options.h"
#include "raylib.h"

options::options()
{
	optionsTexture = LoadTexture("PNG/green_button00_photoshopped.png");
	buttonTexture = LoadTexture("PNG/green_button13.png");
}

options::~options()
{
	UnloadTexture(optionsTexture);
	UnloadTexture(buttonTexture);
}

void options::draw(int screenWidth, int screenHeight)
{
	// --- Background --- //
	DrawTextureEx(optionsTexture, { 0.0f , 0.0f }, 0.0f, 13.875f, WHITE);
	DrawTextureEx(optionsTexture, { screenWidth, 0.0f }, 0.0f, 13.875f, WHITE);
	// --- Buttons --- //
	// Back Button
	DrawTextureEx(buttonTexture, { 275.5f , 350.0f }, 0.0f, 1.875f, WHITE);
	// Options Button
	DrawTextureEx(buttonTexture, { 275.5f , 405.0f * 8.75f }, 0.0f, 2.5f, WHITE);
	// Exit Button
	DrawTextureEx(buttonTexture, { 275.5f , 405.0f * 12.75f }, 0.0f, 2.5f, WHITE);

	//// --- Text --- //
	//// Title Text
	//DrawText("Place_Holder_The_Game", width * 1.05, height * 2, 38.5, BLACK);
	//// Start Text
	//DrawText("Start", width * 1.75f, height * 6.0f, 38.5, BLACK);
	//// Options Text
	//DrawText("Options", width * 1.75f, height * 10.0f, 38.5, BLACK);
	//// Exit Text
	//DrawText("Exit", width * 1.75f, height * 14.0f, 38.5, BLACK);
}

void options::update(float deltaTime)
{
	//if (GameState::GetInstance().getState() == 2) {
	//	// Make three buttons
	//	Rectangle buttonRectangleObject[3];

	//	for (int i = 0; i < 3; i++) {
	//		// Start Button
	//		if (i == 0) {
	//			buttonRectangleObject[i].x = 230;
	//			buttonRectangleObject[i].y = 160;
	//			buttonRectangleObject[i].width = 470;
	//			buttonRectangleObject[i].height = 110;
	//		}
	//		// Options Button
	//		if (i == 1) {
	//			buttonRectangleObject[i].x = 230;
	//			buttonRectangleObject[i].y = 295;
	//			buttonRectangleObject[i].width = 470;
	//			buttonRectangleObject[i].height = 110;
	//		}
	//		// Exit Button
	//		if (i == 2) {
	//			buttonRectangleObject[i].x = 230;
	//			buttonRectangleObject[i].y = 425;
	//			buttonRectangleObject[i].width = 470;
	//			buttonRectangleObject[i].height = 110;
	//		}
	//	}
	//	mousePoint = GetMousePosition();

	//	// Check collision between the mouse and the buttons
	//	for (int i = 0; i < 3; i++) {

	//		// Start Menu
	//		if (CheckCollisionPointRec(mousePoint, buttonRectangleObject[0]) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
	//			GameState::GetInstance().setState(1);
	//		}
	//		// Options Menu
	//		if (CheckCollisionPointRec(mousePoint, buttonRectangleObject[1]) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
	//			GameState::GetInstance().setState(2);
	//		}
	//		if (CheckCollisionPointRec(mousePoint, buttonRectangleObject[2]) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
	//			GameState::GetInstance().setState(6);
	//		}
	//	}
	//}
}