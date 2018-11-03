#include <iostream>
#include "main_Menu.h"
#include "raylib/raylib.h"
#pragma once

class options : 
	mainMenu {
public:
	options();
	~options();
	// Buttons
	Texture2D buttonTexture;

	// Collision
	Vector2 mousePoint;

	// Textures
	Texture2D optionsTexture;

	// Void Functions
	void draw();
	void update(float deltaTime);
};