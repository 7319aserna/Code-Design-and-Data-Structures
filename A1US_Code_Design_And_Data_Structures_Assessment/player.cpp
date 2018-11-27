#include <iostream>
#include "player.h"
#include <vector>

std::vector<float> bottomlessInt;
int tVectorSize = bottomlessInt.size();
int tVectorCapacity = bottomlessInt.capacity();

player::player()
{
	texture = LoadTexture("PNG/Cars/car_red_3");
	position = { 612, 1255 / 2};

	playerRectangleObject.x = position.x;
	playerRectangleObject.y = position.y;
	playerRectangleObject.width = 50.0f;
	playerRectangleObject.height = 50.0f;

	speed = 0;
}

player::~player()
{
}

void player::update(float deltaTime)
{
	bool isSpeedCapped = false;

	if (IsKeyDown(KEY_W)) {
		bottomlessInt.push_back(speed);

		// If speed is at 200
		if (bottomlessInt.size() == 200) {
			isSpeedCapped = true;

			if (IsKeyDown(KEY_W) && IsKeyPressed(KEY_E)) {
				isSpeedCapped = false;
				bottomlessInt.push_back(speed);
				bottomlessInt.push_back(speed);
			}
			
			else if (isSpeedCapped == true) {
				speed = 200;
				bottomlessInt.pop_back();
			}
		}

		// If speed is at 400
		if (bottomlessInt.size() == 400) {
			isSpeedCapped = true;

			if (IsKeyDown(KEY_W) && IsKeyPressed(KEY_E)) {
				isSpeedCapped = false;
				bottomlessInt.push_back(speed);
				bottomlessInt.push_back(speed);
			}

			else if (isSpeedCapped == true) {
				speed = 400;
				bottomlessInt.pop_back();
			}
		}

		// If speed is at 600
		if (bottomlessInt.size() == 600) {
			isSpeedCapped = true;

			if (IsKeyDown(KEY_W) && IsKeyPressed(KEY_E)) {
				isSpeedCapped = false;
				bottomlessInt.push_back(speed);
				bottomlessInt.push_back(speed);
			}

			else if (isSpeedCapped == true) {
				speed = 600;
				bottomlessInt.pop_back();
			}
		}

		// If speed is at 800
		if (bottomlessInt.size() == 800) {
			isSpeedCapped = true;

			if (IsKeyDown(KEY_W) && IsKeyPressed(KEY_E)) {
				isSpeedCapped = false;
				bottomlessInt.push_back(speed);
				bottomlessInt.push_back(speed);
			}

			else if (isSpeedCapped == true) {
				speed = 800;
				bottomlessInt.pop_back();
			}
		}

		// If speed is at 1000
		if (bottomlessInt.size() == 1000) {
			isSpeedCapped = true;

			if (isSpeedCapped == true) {
				speed = 1000;
				bottomlessInt.pop_back();
			}
		}

		if (IsKeyReleased(KEY_W)) {
			speed = 0;
			isSpeedCapped = false;
		}

		if (IsKeyDown(KEY_W)) {
			bottomlessInt.push_back(speed);

		/*std::cout << "Size = " << bottomlessInt.size() << std::endl;
		std::cout << "Capacity = " << bottomlessInt.capacity() << std::endl;*/
		std::cout << "Speed = " << speed << std::endl;

		playerRectangleObject.y -= speed * deltaTime;

		speed++;
	}

	if (IsKeyDown(KEY_S)) {

		playerRectangleObject.y += speed * deltaTime;

	}

//std::vector<int> bottomlessInt;
//
//	bottomlessInt.push_back(1);
//	bottomlessInt.push_back(2);
//	bottomlessInt.push_back(3);
//	bottomlessInt.push_back(4);
//	bottomlessInt.push_back(5);
//	bottomlessInt.push_back(6);
//	bottomlessInt.push_back(7);
//	bottomlessInt.push_back(8);
//	bottomlessInt.push_back(9);
//	bottomlessInt.push_back(10);
//	bottomlessInt.reserve(20);
//
//
//	int tVectorSize = bottomlessInt.size();
//	int tVectorCapacity = bottomlessInt.capacity();
//
//	for (int i = 0; i < bottomlessInt.size(); i++) {
//		std::cout << bottomlessInt.at(i) << std::endl;
//	}
//	std::cout << std::endl;
//	std::cout << "Size = " << bottomlessInt.size() << std::endl;
//	std::cout << "Capacity = " << bottomlessInt.capacity() << std::endl;
}

void player::draw()
{
	DrawRectangle(playerRectangleObject.x, playerRectangleObject.y, playerRectangleObject.width, playerRectangleObject.height, SKYBLUE);
}