#include "main_Menu.h"
#include "gameState.h"
#include "raylib.h"

mainMenu::mainMenu()
{
	if (GameState::GetInstance().getState() == 0) {
		mainMenuTexture = LoadTexture("PNG/blue_button00.png");
		buttonTexture = LoadTexture("PNG/blue_button13.png");
	}
}

mainMenu::~mainMenu()
{
	UnloadTexture(mainMenuTexture);
	UnloadTexture(buttonTexture);
}

void mainMenu::draw(float width, float height)
{
	// --- Buttons --- //
	DrawTextureEx(mainMenuTexture, { width, height }, 0.0f, 2.5f, WHITE);
	// Start Button
	DrawTextureEx(buttonTexture, { width, height * 4.75f }, 0.0f, 2.5f, WHITE);
	// Options Button
	DrawTextureEx(buttonTexture, { width, height * 8.75f }, 0.0f, 2.5f, WHITE);
	// Exit Button
	DrawTextureEx(buttonTexture, { width, height * 12.75f }, 0.0f, 2.5f, WHITE);

	// --- Text --- //
	// Title Text
	DrawText("Place_Holder_The_Game", width * 1.05, height * 2, 38.5, BLACK);
	// Start Text
	DrawText("Start", width * 1.75f, height * 6.0f, 38.5, BLACK);
	// Options Text
	DrawText("Options", width * 1.75f, height * 10.0f, 38.5, BLACK);
	// Exit Text
	DrawText("Exit", width * 1.75f, height * 14.0f, 38.5, BLACK);
}

void mainMenu::update(float deltaTime)
{
	if (GameState::GetInstance().getState() == 0) {
		// Make three buttons
		Rectangle buttonRectangleObject[3];

		for (int i = 0; i < 3; i++) {
			// Start Button
			if (i == 0) {
				buttonRectangleObject[i].x = 230;
				buttonRectangleObject[i].y = 160;
				buttonRectangleObject[i].width = 470;
				buttonRectangleObject[i].height = 110;
			}
			// Options Button
			if (i == 1) {
				buttonRectangleObject[i].x = 230;
				buttonRectangleObject[i].y = 295;
				buttonRectangleObject[i].width = 470;
				buttonRectangleObject[i].height = 110;
			}
			// Exit Button
			if (i == 2) {
				buttonRectangleObject[i].x = 230;
				buttonRectangleObject[i].y = 425;
				buttonRectangleObject[i].width = 470;
				buttonRectangleObject[i].height = 110;
			}
		}
		mousePoint = GetMousePosition();

		// Check collision between the mouse and the buttons
		for (int i = 0; i < 3; i++) {

			// Start Menu
			if (CheckCollisionPointRec(mousePoint, buttonRectangleObject[0]) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
				GameState::GetInstance().setState(1);
			}
			// Options Menu
			if (CheckCollisionPointRec(mousePoint, buttonRectangleObject[1]) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
				GameState::GetInstance().setState(2);
			}
			// Exit
			if (CheckCollisionPointRec(mousePoint, buttonRectangleObject[2]) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
				GameState::GetInstance().setState(6);
			}
		}
	}
}