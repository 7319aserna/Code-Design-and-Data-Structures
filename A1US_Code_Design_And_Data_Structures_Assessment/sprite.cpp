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

	// *****-----Car Movement & Turning-----***** //

	// For the Car's Movement, it will only go fowards and backwards...
	// ... In order for the car to turn, the mouse is the only one that...
	// ... make it turn.
	if (IsKeyDown(KEY_W)) {
		std::cout << "Mph: " << mph << std::endl;
		position.y -= mph++ * deltaTime;
		//position.y -= mph * deltaTime;
	}
	// When the W key is released, the car will slow down.
	while (IsKeyReleased(KEY_W)) {
		std::cout << mph << std::endl;
		mph--;
		if (mph == 0) {
			break;
		}
	}

	/*
	if (IsKeyDown(KEY_S)) {
		std::cout << "Mph: " << mph << std::endl;
		position.y += mph++ * deltaTime;
		//position.y += mph * deltaTime;
	}
	while (IsKeyReleased(KEY_S)) {
		std::cout << mph << std::endl;
		mph--;
		if (mph == 0) {
			break;
		}
	}
	*/

	//For rotation, wherever the mouse is hovering at, the car will rotate to that position.
	
	// Set the mouse's position to the car, but only be able to change...
	// ... the mouse's x position.
	SetMousePosition(position);

	rotation = GetMouseX();
	

	// For the Car to go faster, there will be a Dynamic Array implmented into...
	// ... it, when the car wants to go faster, the array will double in size...
	// ... to make it go faster. Now when the car starts to slow down...
	// ... the array's size will decrease.
}

void sprite::draw()
{
	DrawTextureEx(texture, position, rotation, 0.375f, WHITE);
	//DrawTexture(spriteCells[currentFrame], x, y, WHITE);
}