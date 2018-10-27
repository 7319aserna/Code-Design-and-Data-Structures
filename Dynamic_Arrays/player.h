#pragma once

#include "raylib/raylib.h"

class player {
public:
	player();
	~player();
	
	int speed;

	Texture2D texture;

	Vector2 position;

	void draw();
	void update(float deltaTime);
};