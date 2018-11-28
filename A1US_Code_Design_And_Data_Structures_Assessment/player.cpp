#include <iostream>
#include "player.h"
#include "raylib.h"
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

		// If speed is at 20
		if (bottomlessInt.size() == 20) {
			isSpeedCapped = true;
			DrawText("Press E to shift gear", 685, 1210, 29, BLACK);

			if (IsKeyDown(KEY_W) && IsKeyPressed(KEY_E)) {
				isSpeedCapped = false;
				bottomlessInt.push_back(speed);
				bottomlessInt.push_back(speed);
			}

			else if (isSpeedCapped == true) {
				speed = 20;
				bottomlessInt.pop_back();
			}
		}

		// If speed is at 40
		if (bottomlessInt.size() == 40) {
			isSpeedCapped = true;
			DrawText("Press E to shift gear", 685, 1210, 29, BLACK);

			if (IsKeyDown(KEY_W) && IsKeyPressed(KEY_E)) {
				isSpeedCapped = false;
				bottomlessInt.push_back(speed);
				bottomlessInt.push_back(speed);
			}

			else if (isSpeedCapped == true) {
				speed = 40;
				bottomlessInt.pop_back();
			}
		}

		// If speed is at 60
		if (bottomlessInt.size() == 60) {
			isSpeedCapped = true;
			DrawText("Press E to shift gear", 685, 1210, 29, BLACK);

			if (IsKeyDown(KEY_W) && IsKeyPressed(KEY_E)) {
				isSpeedCapped = false;
				bottomlessInt.push_back(speed);
				bottomlessInt.push_back(speed);
			}

			else if (isSpeedCapped == true) {
				speed = 60;
				bottomlessInt.pop_back();
			}
		}

		// If speed is at 80
		if (bottomlessInt.size() == 80) {
			isSpeedCapped = true;
			DrawText("Press E to shift gear", 685, 1210, 29, BLACK);

			if (IsKeyDown(KEY_W) && IsKeyPressed(KEY_E)) {
				isSpeedCapped = false;
				bottomlessInt.push_back(speed);
				bottomlessInt.push_back(speed);
			}

			else if (isSpeedCapped == true) {
				speed = 80;
				bottomlessInt.pop_back();
			}
		}

		// If speed is at 100
		if (bottomlessInt.size() == 100) {
			isSpeedCapped = true;

			if (isSpeedCapped == true) {
				speed = 100;
				bottomlessInt.pop_back();
			}
		}

		//	std::cout << "Size = " << bottomlessInt.size() << std::endl;
		//	std::cout << "Capacity = " << bottomlessInt.capacity() << std::endl;
			playerRectangleObject.y -= speed * deltaTime;
			speed++;
		}

	if (IsKeyReleased(KEY_W) && isSpeedCapped == false) {
		bottomlessInt.resize(0);
		speed = 0;
		isSpeedCapped = false;

		std::cout << "Size = " << bottomlessInt.size() << std::endl;
		std::cout << "Capacity = " << bottomlessInt.capacity() << std::endl;
		std::cout << "Speed = " << speed << std::endl;
	}

	if (IsKeyDown(KEY_S)) {

		playerRectangleObject.y += speed * deltaTime;

	}
	DrawText("Speed: ", 750, 125, 45, BLACK);
	DrawText(FormatText("%03i", speed), 900, 125, 45, BLACK);
}

void player::draw()
{
	DrawRectangle(playerRectangleObject.x, playerRectangleObject.y, playerRectangleObject.width, playerRectangleObject.height, SKYBLUE);
}