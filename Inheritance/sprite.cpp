#include <iostream>
#include "raylib/raylib.h"
#include "sprite.h"

sprite::sprite()
{
}

sprite::sprite(const std::string * filename, const int cellCount, const float _frameRate)
{
	spriteCells = new Texture2D[cellCount];

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

}

void sprite::draw()
{
	DrawTexture(spriteCells[1], 4, 4, WHITE);
}
