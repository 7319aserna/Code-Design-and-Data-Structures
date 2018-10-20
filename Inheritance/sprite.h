#include <iostream>
#include "raylib/raylib.h"
#pragma once

class sprite : 
	public Vector2
{
public:
	Texture2D * spriteCells = NULL;
	float frameRate = 25.0;
	int frameCount = 0;
	int direction = 1;
	int currentFrame = 0;

	float timer = 0.0f;

	void update(float deltaTime);

	void draw();

	sprite(const std::string *filename, const  int cellCount = 1, const float _frameRate = 25.0);
	sprite();
	~sprite();
};