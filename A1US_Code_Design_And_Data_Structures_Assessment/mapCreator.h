#include "raylib/raylib.h"
#pragma once

class mapCreator {
public:
	// What whould I need to make a map?
	mapCreator();
	mapCreator(const char* imageFilename);
	~mapCreator();

	// Tiles
	Texture2D texture;

	// Position of the tiles
	int positionX;
	int positionY;

	// Collision between object and tiles
	Rectangle rectangleObject;

	void update(float deltaTime, int screenWidth, int screenHeight);
};