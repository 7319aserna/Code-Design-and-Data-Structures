#pragma once
#include <iostream>
#include "raylib/raylib.h"

// For the Sprite class, my plan is to be able to apply this to multiple objects...
// ... to animate like for example, the Player (Car), and as well as...
// ... the Accelerometer.
class sprite :
	public Vector2
{
public:
	//Texture2D * spriteCells = NULL;
	float frameRate = 25.0;

	int frameCount = 0;
	int mph;
	int direction = 1;
	int currentFrame = 0;

	float timer = 0.0f;

	Texture2D texture;

	Vector2 position;

	void update(float deltaTime);

	void draw();

	//sprite(const std::string *filename, const  int cellCount = 1, const float _frameRate = 25.0);
	sprite();
	~sprite();
};