#include <iostream>
#include "raylib/raylib.h"
#include "sprite.h"

sprite::sprite()
{
}

sprite::sprite(const std::string * filename, const int cellCount, const float _frameRate)
{
	spriteCells = new Texture2D[cellCount];

	frameCount = cellCount;

	// For the cell count, as it increases by one, it would switch textures.
	for (int i = 0; i < cellCount; i++) {
		spriteCells[i] = LoadTexture(filename[i].c_str());
	}
}

sprite::~sprite()
{
	delete[] spriteCells;
}

void sprite::update(float deltaTime)
{
	timer += deltaTime;

	std::cout << "timer: " << timer << std::endl;

	if (timer >= 1.0f) {
		timer = 0.0f;
		currentFrame++;

		if (currentFrame >= frameCount) {
			currentFrame = 0;
		}
	}
}

void sprite::draw()
{
	DrawTexture(spriteCells[currentFrame], x, y, WHITE);
}