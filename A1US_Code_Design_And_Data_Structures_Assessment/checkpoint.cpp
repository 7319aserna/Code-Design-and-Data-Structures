#include "checkpoint.h"
#include <iostream>
#include "player.h"
#include "tQueue.h"

tQueue<int> queueObject;
player p_Object;

checkpoint::checkpoint()
{
	texture = LoadTexture("PNG/Objects/barrier_red.png");

	queueObject.push(1);
}

checkpoint::~checkpoint()
{
	UnloadTexture(texture);
}

void checkpoint::update(float deltaTime)
{
	// When we push, it will spawn in a checkpoint, and as soon as the player crosses that 
	std::cout << "Size: " << queueObject.size() << std::endl;
	DrawTexture(texture, 515, 215, WHITE);
	DrawTexture(texture, 25, 215, WHITE);
	DrawTexture(texture, 25, 975, WHITE);
	DrawTexture(texture, 515, 975, WHITE);

	if (queueObject.size() == 1) {
		/*checkpointRectangleObject.x = 515;
		checkpointRectangleObject.y = 215;
		checkpointRectangleObject.height = 50;
		checkpointRectangleObject.width = 900;*/

		DrawTexture(texture, 25, 215, WHITE);
		DrawTexture(texture, 25, 975, WHITE);
		DrawTexture(texture, 515, 975, WHITE);

		if (CheckCollisionRecs(p_Object.playerRectangleObject, checkpointRectangleObject)) {
				DrawTexture(texture, 25, 215, WHITE);
				DrawTexture(texture, 25, 975, WHITE);
				DrawTexture(texture, 515, 975, WHITE);
			}
	}

	if (queueObject.size() == 2) {

	}
	if (queueObject.size() == 3) {

	}
	if (queueObject.size() == 4) {

	}

	std::cout << "Size: " << queueObject.size() << std::endl;

}

void checkpoint::draw()
{
	if (queueObject.size() == 1) {
		DrawTexture(texture, 515, 215, WHITE);
	}
	if (queueObject.size() == 2) {
		DrawTexture(texture, 25, 215, WHITE);
	}
	if (queueObject.size() == 3) {
		DrawTexture(texture, 25, 975, WHITE);
	}
	if (queueObject.size() == 4) {
		DrawTexture(texture, 515, 975, WHITE);
	}
}
