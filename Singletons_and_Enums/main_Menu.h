#include <iostream>
#include "raylib.h"
#pragma once

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

	// STRETCH GOAL: MUSIC

	// LATER STRETCH GOAL: In the options menu, be able to change size of screen.44

};