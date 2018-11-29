#include <iostream>
#include "main_Menu.h"
#include "raylib.h"
#pragma once

class options :
	mainMenu {
public:
	options();
	~options();

	// Textures
	Texture2D optionsTexture;
	// Void Functions
	void draw();
	void update(float deltaTime);

};