#include <iostream>
#include "player.h"
#include "raylib.h"
#include "tQueue.h"
#include <vector>

std::vector<float> bottomlessInt;
int tVectorSize = bottomlessInt.size();
int tVectorCapacity = bottomlessInt.capacity();
tQueue<int> spawnQueueObject;

player::player()
{
	texture = LoadTexture("PNG/Cars/car_red_3.png");
	position = { 445, 445};

	playerRectangleObject.x = position.x;
	playerRectangleObject.y = position.y;
	playerRectangleObject.width = 50.0f;
	playerRectangleObject.height = 50.0f;

	speed = 0;

	spawnQueueObject.push(1);
	spawnQueueObject.push(2);
	spawnQueueObject.push(3);
	spawnQueueObject.push(4);
	spawnQueueObject.push(5);
}

player::~player()
{
}

void player::update(float deltaTime)
{
	bool isSpeedCapped = false;

	// For my speed variable, when the player starts to move, it pushes back the speed and makes it into a dynamic array.
	// The capacity will increase to the max speed, and as soon as the player's speed is at zero, then there would be nothing in the array.
	if (IsKeyDown(KEY_W) | IsKeyDown(KEY_A) | IsKeyDown(KEY_S) | IsKeyDown(KEY_D)) {
		bottomlessInt.push_back(speed);

		if (IsKeyDown(KEY_L)) {
			speed = 500;
		}

		// If speed is at 50
		if (bottomlessInt.size() == 50) {
			isSpeedCapped = true;
			DrawText("Press E to shift gear", 537, 900, 40, BLACK);

			if (IsKeyDown(KEY_W) | IsKeyDown(KEY_A) | IsKeyDown(KEY_S) | IsKeyDown(KEY_D) && IsKeyPressed(KEY_E)) {
				isSpeedCapped = false;
				bottomlessInt.push_back(speed);
				bottomlessInt.push_back(speed);
			}

			else if (isSpeedCapped == true) {
				speed = 49;
				bottomlessInt.pop_back();
			}
		}

		// If speed is at 100
		if (bottomlessInt.size() == 100) {
			isSpeedCapped = true;
			DrawText("Press E to shift gear", 537, 900, 40, BLACK);

			if (IsKeyDown(KEY_W) | IsKeyDown(KEY_A) | IsKeyDown(KEY_S) | IsKeyDown(KEY_D) && IsKeyPressed(KEY_E)) {
				isSpeedCapped = false;
				bottomlessInt.push_back(speed);
				bottomlessInt.push_back(speed);
			}

			else if (isSpeedCapped == true) {
				speed = 99;
				bottomlessInt.pop_back();
			}
		}

		// If speed is at 150
		if (bottomlessInt.size() == 150) {
			isSpeedCapped = true;
			DrawText("Press E to shift gear", 537, 900, 40, BLACK);

			if (IsKeyDown(KEY_W) | IsKeyDown(KEY_A) | IsKeyDown(KEY_S) | IsKeyDown(KEY_D) && IsKeyPressed(KEY_E)) {
				isSpeedCapped = false;
				bottomlessInt.push_back(speed);
				bottomlessInt.push_back(speed);
			}

			else if (isSpeedCapped == true) {
				speed = 149;
				bottomlessInt.pop_back();
			}
		}

		// If speed is at 200
		if (bottomlessInt.size() == 200) {
			isSpeedCapped = true;
			DrawText("Press E to shift gear", 537, 900, 40, BLACK);

			if (IsKeyDown(KEY_W) | IsKeyDown(KEY_A) | IsKeyDown(KEY_S) | IsKeyDown(KEY_D) && IsKeyPressed(KEY_E)) {
				isSpeedCapped = false;
				bottomlessInt.push_back(speed);
				bottomlessInt.push_back(speed);
			}

			else if (isSpeedCapped == true) {
				speed = 199;
				bottomlessInt.pop_back();
			}
		}

		// If speed is at 250
		if (bottomlessInt.size() == 250) {
			isSpeedCapped = true;

			if (isSpeedCapped == true) {
				speed = 249;
				bottomlessInt.pop_back();
			}
		}

		/*std::cout << "Size = " << bottomlessInt.size() << std::endl;
		std::cout << "Capacity = " << bottomlessInt.capacity() << std::endl;*/

		if (IsKeyDown(KEY_W)) {
			position.y -= speed * deltaTime;
			playerRectangleObject.y -= speed * deltaTime;
		}
		if (IsKeyDown(KEY_A)) {
			position.x -= speed * deltaTime;
			playerRectangleObject.x -= speed * deltaTime;
		}
		if (IsKeyDown(KEY_S)) {
			position.y += speed * deltaTime;
			playerRectangleObject.y += speed * deltaTime;
		}
		if (IsKeyDown(KEY_D)) {
			position.x += speed * deltaTime;
			playerRectangleObject.x += speed * deltaTime;
		}
		speed++;
	}

	if (IsKeyReleased(KEY_W) | IsKeyReleased(KEY_A) | IsKeyReleased(KEY_S) | IsKeyReleased(KEY_D) && isSpeedCapped == false) {
		bottomlessInt.resize(0);
		speed = 0;
		isSpeedCapped = false;
	}

	DrawText("Speed: ", 575, 850, 45, BLACK);
	DrawText(FormatText("%03i", speed), 725, 850, 45, BLACK);

	// If the player would leave out of the "Race Track"
	// Then depending on what checkpoint the player is currently at, then the player would be spawned there.
	if (spawnQueueObject.size() == 5) {
		if (playerRectangleObject.x < 0 | playerRectangleObject.x > 525 | playerRectangleObject.y < 0 | playerRectangleObject.y > 950) {
			position.x = 445;
			playerRectangleObject.x = 445;
			position.y = 445;
			playerRectangleObject.y = 445;
		}
		if (playerRectangleObject.x >= 404 && playerRectangleObject.y < 190 && playerRectangleObject.y > 180) {
			spawnPosition.x = 445;
			spawnPosition.y = 200;
			spawnQueueObject.pop();
		}
	}

	if (spawnQueueObject.size() == 4) {
		if (playerRectangleObject.x < 0 | playerRectangleObject.x > 525 | playerRectangleObject.y < 0 | playerRectangleObject.y > 950) {
			position.x = spawnPosition.x;
			playerRectangleObject.x = spawnPosition.x;
			position.y = spawnPosition.y;
			playerRectangleObject.y = spawnPosition.y;
		}
		if (playerRectangleObject.x <= 154 && playerRectangleObject.y < 190 && playerRectangleObject.y > 180) {
			spawnPosition.x = 75;
			spawnPosition.y = 200;
			spawnQueueObject.pop();
		}
	}

	if (spawnQueueObject.size() == 3) {
		if (playerRectangleObject.x < 0 | playerRectangleObject.x > 525 | playerRectangleObject.y < 0 | playerRectangleObject.y > 950) {
			position.x = spawnPosition.x;
			playerRectangleObject.x = spawnPosition.x;
			position.y = spawnPosition.y;
			playerRectangleObject.y = spawnPosition.y;
		}
		if (playerRectangleObject.x <= 154 && playerRectangleObject.y < 700 && playerRectangleObject.y > 690) {
			spawnPosition.x = 75;
			spawnPosition.y = 700;
			spawnQueueObject.pop();
		}
	}

	if (spawnQueueObject.size() == 2) {
		if (playerRectangleObject.x < 0 | playerRectangleObject.x > 525 | playerRectangleObject.y < 0 | playerRectangleObject.y > 950) {
			position.x = spawnPosition.x;
			playerRectangleObject.x = spawnPosition.x;
			position.y = spawnPosition.y;
			playerRectangleObject.y = spawnPosition.y;
		}
		if (playerRectangleObject.x >= 404 && playerRectangleObject.y < 700 && playerRectangleObject.y > 690) {
			spawnPosition.x = 445;
			spawnPosition.y = 695;
			spawnQueueObject.pop();
		}
	}

	if (spawnQueueObject.size() == 1) {
		if (playerRectangleObject.x < 0 | playerRectangleObject.x > 525 | playerRectangleObject.y < 0 | playerRectangleObject.y > 950) {
			position.x = spawnPosition.x;
			playerRectangleObject.x = spawnPosition.x;
			position.y = spawnPosition.y;
			playerRectangleObject.y = spawnPosition.y;
		}
		if (playerRectangleObject.x < 0 | playerRectangleObject.x > 525 | playerRectangleObject.y < 0 | playerRectangleObject.y > 950) {
			position.x = 445;
			playerRectangleObject.x = 445;
			position.y = 445;
			playerRectangleObject.y = 445;
			spawnQueueObject.pop();
		}
	}

	if (spawnQueueObject.size() == 0) {
		spawnQueueObject.push(1);
		spawnQueueObject.push(2);
		spawnQueueObject.push(3);
		spawnQueueObject.push(4);
		spawnQueueObject.push(5);
	}
}

void player::draw() {
	//DrawRectangle(playerRectangleObject.x, playerRectangleObject.y, playerRectangleObject.width, playerRectangleObject.height, SKYBLUE);
	
	// If no Keys are Pressed 
	if (IsKeyUp(KEY_W) && IsKeyUp(KEY_A) && IsKeyUp(KEY_S) && IsKeyUp(KEY_D)) {
		DrawTexturePro(texture, Rectangle{ 0,0,(float)(texture.width), (float)(texture.height) }, Rectangle{ playerRectangleObject.x + playerRectangleObject.width / 2, playerRectangleObject.y + playerRectangleObject.height / 2,(float)(texture.width) * 0.75f, (float)(texture.height) * 0.75f }, { (float)(texture.width) / 2, (float)(texture.height) / 2 }, 0.0f, WHITE);
		//DrawTextureEx(texture, { playerRectangleObject.x, playerRectangleObject.y }, 0.0f, 0.75f, WHITE);
	}

	// If only the W Key is Pressed 
	if (IsKeyDown(KEY_W) && IsKeyUp(KEY_A) && IsKeyUp(KEY_S) && IsKeyUp(KEY_D)) {
		DrawTexturePro(texture, Rectangle{0,0,(float)(texture.width), (float)(texture.height) }, Rectangle{ playerRectangleObject.x + playerRectangleObject.width / 2, playerRectangleObject.y + playerRectangleObject.height / 2,(float)(texture.width) * 0.75f, (float)(texture.height) * 0.75f }, { (float)(texture.width) / 2, (float)(texture.height) / 2 }, 0.0f, WHITE);
		//DrawTextureEx(texture, { playerRectangleObject.x, playerRectangleObject.y }, 0.0f, 0.75f, WHITE);
	}
	// If only the W and A Key is Pressed 
	if (IsKeyDown(KEY_W) && IsKeyDown(KEY_A) && IsKeyUp(KEY_S) && IsKeyUp(KEY_D)) {
		DrawTexturePro(texture, Rectangle{ 0,0,(float)(texture.width), (float)(texture.height) }, Rectangle{ playerRectangleObject.x + playerRectangleObject.width / 2, playerRectangleObject.y + playerRectangleObject.height / 2,(float)(texture.width) * 0.75f, (float)(texture.height) * 0.75f }, { (float)(texture.width) / 2, (float)(texture.height) / 2 }, -45.0f, WHITE);
		//DrawTextureEx(texture, { playerRectangleObject.x, playerRectangleObject.y }, -45.0f, 0.75f, WHITE);
	}

	// If only the A Key is pressed
	if (IsKeyUp(KEY_W) && IsKeyDown(KEY_A) && IsKeyUp(KEY_S) && IsKeyUp(KEY_D)) {
		DrawTexturePro(texture, Rectangle{ 0,0,(float)(texture.width), (float)(texture.height) }, Rectangle{ playerRectangleObject.x + playerRectangleObject.width / 2, playerRectangleObject.y + playerRectangleObject.height / 2,(float)(texture.width) * 0.75f, (float)(texture.height) * 0.75f }, { (float)(texture.width) / 2, (float)(texture.height) / 2 }, -90.0f, WHITE);
		//DrawTextureEx(texture, { playerRectangleObject.x, playerRectangleObject.y }, -90.0f, 0.75f, WHITE);
	}
	// If only the A and S Key is pressed
	if (IsKeyUp(KEY_W) && IsKeyDown(KEY_A) && IsKeyDown(KEY_S) && IsKeyUp(KEY_D)) {
		DrawTexturePro(texture, Rectangle{ 0,0,(float)(texture.width), (float)(texture.height) }, Rectangle{ playerRectangleObject.x + playerRectangleObject.width / 2, playerRectangleObject.y + playerRectangleObject.height / 2,(float)(texture.width) * 0.75f, (float)(texture.height) * 0.75f }, { (float)(texture.width) / 2, (float)(texture.height) / 2 }, -135.0f, WHITE);
		//DrawTextureEx(texture, { playerRectangleObject.x, playerRectangleObject.y }, -135.0f, 0.75f, WHITE);
	}

	// If only the S Key is Pressed 
	if (IsKeyUp(KEY_W) && IsKeyUp(KEY_A) && IsKeyDown(KEY_S) && IsKeyUp(KEY_D)) {
		DrawTexturePro(texture, Rectangle{ 0,0,(float)(texture.width), (float)(texture.height) }, Rectangle{ playerRectangleObject.x + playerRectangleObject.width / 2, playerRectangleObject.y + playerRectangleObject.height / 2,(float)(texture.width) * 0.75f, (float)(texture.height) * 0.75f }, { (float)(texture.width) / 2, (float)(texture.height) / 2 }, -180.0f, WHITE);
		//DrawTextureEx(texture, { playerRectangleObject.x, playerRectangleObject.y }, -180.0f, 0.75f, WHITE);
	}
	// If only the S and D Key is Pressed 
	if (IsKeyUp(KEY_W) && IsKeyUp(KEY_A) && IsKeyDown(KEY_S) && IsKeyDown(KEY_D)) {
		DrawTexturePro(texture, Rectangle{ 0,0,(float)(texture.width), (float)(texture.height) }, Rectangle{ playerRectangleObject.x + playerRectangleObject.width / 2, playerRectangleObject.y + playerRectangleObject.height / 2,(float)(texture.width) * 0.75f, (float)(texture.height) * 0.75f }, { (float)(texture.width) / 2, (float)(texture.height) / 2 }, -225.0f, WHITE);
		//DrawTextureEx(texture, { playerRectangleObject.x, playerRectangleObject.y }, -225.0f, 0.75f, WHITE);
	}

	// If only the D Key is Pressed 
	if (IsKeyUp(KEY_W) && IsKeyUp(KEY_A) && IsKeyUp(KEY_S) && IsKeyDown(KEY_D)) {
		DrawTexturePro(texture, Rectangle{ 0,0,(float)(texture.width), (float)(texture.height) }, Rectangle{ playerRectangleObject.x + playerRectangleObject.width / 2, playerRectangleObject.y + playerRectangleObject.height / 2,(float)(texture.width) * 0.75f, (float)(texture.height) * 0.75f }, { (float)(texture.width) / 2, (float)(texture.height) / 2 }, -270.0f, WHITE);
		//DrawTextureEx(texture, { playerRectangleObject.x, playerRectangleObject.y }, -270.0f, 0.75f, WHITE);
	}
	// If only the D and W Key is Pressed 
	if (IsKeyDown(KEY_W) && IsKeyUp(KEY_A) && IsKeyUp(KEY_S) && IsKeyDown(KEY_D)) {
		DrawTexturePro(texture, Rectangle{ 0,0,(float)(texture.width), (float)(texture.height) }, Rectangle{ playerRectangleObject.x + playerRectangleObject.width / 2, playerRectangleObject.y + playerRectangleObject.height / 2,(float)(texture.width) * 0.75f, (float)(texture.height) * 0.75f }, { (float)(texture.width) / 2, (float)(texture.height) / 2 }, -315.0f, WHITE);
		//DrawTextureEx(texture, { playerRectangleObject.x, playerRectangleObject.y }, -315.0f, 0.75f, WHITE);
	}
}