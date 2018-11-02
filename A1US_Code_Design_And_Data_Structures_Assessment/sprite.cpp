#include <iostream>
#include "raylib/raylib.h"
#include "sprite.h"

sprite::sprite()
{
	texture = LoadTexture("car_blue_3.png");
}

/*
sprite::sprite(const std::string * filename, const int cellCount, const float _frameRate)
{
	spriteCells = new Texture2D[cellCount];

	frameCount = cellCount;

	// For the cell count, as it increases by one, it would switch textures.
	for (int i = 0; i < cellCount; i++) {
		spriteCells[i] = LoadTexture(filename[i].c_str());
	}
}
*/

sprite::~sprite()
{
	UnloadTexture(texture);
	//delete[] spriteCells;
}

void sprite::update(float deltaTime)
{
	/*
	timer += deltaTime;

	std::cout << "timer: " << timer << std::endl;

	if (timer >= 1.0f) {
		timer = 0.0f;
		currentFrame++;

		if (currentFrame >= frameCount) {
			currentFrame = 0;
		}
	}
	*/

	// For the Car's Movement, it will only go fowards and backwards...
	// ... In order for the car to turn, the mouse is the only one that...
	// ... make it turn.
	if (IsKeyDown(KEY_W)) {
		std::cout << "Mph: " << mph << std::endl;
		position.y -= mph++ * deltaTime;
		//position.y -= mph * deltaTime;
	}
	if (IsKeyReleased(KEY_W)) {
		mph = 0;
	}

	if (IsKeyDown(KEY_S)) {
		std::cout << "Mph: " << mph << std::endl;
		position.y += mph++ * deltaTime;
		//position.y += mph * deltaTime;
	}
	if (IsKeyReleased(KEY_S)) {
		mph = 0;
	}

	// For the Car to go faster, there will be a Dynamic Array implmented into...
	// ... it, when the car wants to go faster, the array will double in size...
	// ... to make it go faster. Now when the car starts to slow down...
	// ... the array's size will decrease.
}

void sprite::draw()
{
	DrawTextureEx(texture, position, 0.0f, 0.375f, WHITE);
	//DrawTexture(spriteCells[currentFrame], x, y, WHITE);
}