#include <iostream>
#pragma once
#include "raylib.h"

class mainMenu {
public:
	mainMenu();
	~mainMenu();

	// Buttons
	Texture2D buttonTexture;

	// Collision
	bool active;
	Vector2 mousePoint;

	// Textures
	Texture2D mainMenuTexture;

	// Void Functions
	void draw(float width, float height);
	void update(float deltaTime);
};