#include "my_Hero.h"
#include "potion.h"
#include "raylib/raylib.h"

#include <iostream>

float screenWidth = 1000.0f;
float screenHeight = 500.0f;

int main() {

	InitWindow(screenWidth, screenHeight, "Hero");
	SetTargetFPS(60);

	myHero hero;

	// Display Name
	hero.name = "Name: Alexis";

	// Display Special (Note: Gonna hardcode it for now, may give the option to let players add their own specials)
	hero.special = "Special: Fists of FURY!!!";

	// Display Age
	hero.age = "Age: 18";

	// Display Hit Points (Note: I'm assuming this is their damage dealt? This value will be randomized from a value of 0 to 25)
	hero.hitPoints = "Hit Points: 22";

	// Display Wealth (Note: This value will also be randomized from a certain amount)
	hero.wealth = "Wealth: -55555";

	while (!WindowShouldClose()) {

		BeginDrawing();

		hero.draw();

		ClearBackground(RAYWHITE);

		EndDrawing();
	}
}