#include <iostream>
#include "raylib/raylib.h"

//#include "originalClass.h"
//#include "newerClass.h"
//int main() {
//	originalClass ma;
//	newerClass mb = ma;
//
//	// For the Closed Exercise (Newer2Original),...
//	// ... <Step Four>: Now we create a new object for our...
//	// ... Newer Class, as well as our Original Class...
//	// ... than we make sure that whatever our Newer Class...
//	// ... is, it will be the same for our Original Class.
//	newerClass newerObject;
//	originalClass originalObject = newerObject;
//
//	return 0;
//}

// ---------------------- //
// This part on the bottom is seperate from the top, make sure if I...
// ... uncomment one then want to uncomment the other...
// ... make sure to comment the other one.
// ---------------------- //

//#include <iostream>
//
//#include "originalClass.h"
//#include "newerClass.h"
//int main() {
//	newerClass ma;
//	originalClass mb = ma;
//	return 0;
//}

// ---------------------- //
// This part on the bottom is seperate from the top, make sure if I...
// ... uncomment one then want to uncomment the other...
// ... make sure to comment the other one.
// ---------------------- //

#include "wizard.h"

int screenWidth = 960;
int screenHeight = 540;

int main() {

	InitWindow(screenWidth, screenHeight, "Implicit Conversions and Casting");
	SetTargetFPS(60);
	
	wizard wizardObject;
	wizardObject.name = "Steve The Wizard";
	wizardObject.health = 100;
	wizardObject.position = { 100, 100 };
	wizardObject.rotation = 0.0f;
	wizardObject.speed = 50;

	while (!WindowShouldClose()) {

		wizardObject.update(GetFrameTime());

		BeginDrawing();

		ClearBackground(RAYWHITE);

		wizardObject.draw();

		EndDrawing();
	}
}