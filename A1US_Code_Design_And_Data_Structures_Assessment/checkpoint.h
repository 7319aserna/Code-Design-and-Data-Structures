#include "raylib.h"
#pragma once

class checkpoint {
public:
	checkpoint();
	~checkpoint();

	// What would we need to have checkpoints all over the map?
	Texture2D texture;
	Vector2 checkpointPosition;
	Rectangle checkpointRectangleObject;

	// In the update, we will put the checkpoints into a queue
	void update(float deltaTime);
	void draw();
};