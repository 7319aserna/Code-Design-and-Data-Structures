#pragma once
#include "raylib/raylib.h"

class player
{
public:
	player();
	~player();
	// What will the player have?
	// Movement
	int movementSpeed;
	// Position
	Vector2 playerPosition;
	// Image
	Texture2D texture;
	// Draw the image
	void draw();
	// Update
	void update(float deltaTime);
};