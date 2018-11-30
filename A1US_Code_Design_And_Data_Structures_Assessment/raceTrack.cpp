#include "bestLap.h"
#include <iostream>
#include "player.h"
#include "raceTrack.h"
#include "tQueue.h"

tQueue<int> queueObject;
bestLap bL_Object;

raceTrack::raceTrack()
{
	texture = LoadTexture("PNG/Objects/barrier_red.png");

	// 1 - 4 are the checkpoints
	queueObject.push(1);
	queueObject.push(2);
	queueObject.push(3);
	queueObject.push(4);
	// 5 is the finish line
	queueObject.push(5);

	// raceTrack starts with no laps completed (Or on the first lap)
	lapCounter = 1;
	// Time is set to zero
	lapTimer = 0;
	// The time after the race ends is set to zero
	raceEndTimer = 0.0f;
}

raceTrack::~raceTrack()
{
	UnloadTexture(texture);
}

void raceTrack::update(float deltaTime, player& player, GameState& gamestate)
{
	lapTimer += deltaTime;
	// Here is where the Queue is located
	// When we push, it will spawn in a checkpoint, and as soon as the player crosses that checkpoint, it would move to the next one.
	std::cout << "Queue Size: " << queueObject.size() << std::endl;

	// 1st Checkpoint
	if (queueObject.front() == 1) {
		if (player.playerRectangleObject.x >= 404 && player.playerRectangleObject.y < 190 && player.playerRectangleObject.y > 180) {
			queueObject.pop();
		}
	}

	// 2nd Checkpoint
	if (queueObject.front() == 2) {
		if (player.playerRectangleObject.x <= 154 && player.playerRectangleObject.y < 190 && player.playerRectangleObject.y > 180) {
			queueObject.pop();
		}
	}

	// 3rd Checkpoint
	if (queueObject.front() == 3) {
		if (player.playerRectangleObject.x <= 154 && player.playerRectangleObject.y < 700 && player.playerRectangleObject.y > 690) {
			queueObject.pop();
		}
	}

	// 4th Checkpoint
	if (queueObject.front() == 4) {
		if (player.playerRectangleObject.x >= 404 && player.playerRectangleObject.y < 700 && player.playerRectangleObject.y > 690) {
			queueObject.pop();
		}
	}

	// Finish Line
	if (queueObject.front() == 5) {
		if (player.playerRectangleObject.x >= 404 && player.playerRectangleObject.y < 460 && player.playerRectangleObject.y > 440) {
			queueObject.pop();
		}
	}

	// Once the player has made all of the checkpoints, a lap would be completed.
	if (queueObject.size() == 0) {
		lapCounter++;
		if (lapCounter == 2) {
			firstLap = lapTimer;
		}
		if (lapCounter == 3) {
			secondLap = lapTimer;
		}
		if (lapCounter == 4) {
			thirdLap = lapTimer;
		}
		lapTimer = 0;

		if (lapCounter == 4) {
			float floatArr[3] = { firstLap, secondLap, thirdLap };
			bL_Object.mergeSort(floatArr, 0, 2);
			
			for (int i = 0; i < 1; i++) {
				fastestLap = floatArr[i];
				std::cout << (float)fastestLap << std::endl;
			}

			gamestate.setState(2);
		}
		else if (lapCounter < 4) {
			queueObject.push(1);
			queueObject.push(2);
			queueObject.push(3);
			queueObject.push(4);
			queueObject.push(5);
		}
	}
}

void raceTrack::draw()
{
	DrawText("Lap", 575, 0, 45, BLACK);
	DrawText(FormatText("%01i", lapCounter), 675, 0, 45, BLACK);
	DrawText("/3", 700, 0, 45, BLACK);

	if (lapCounter == 1) {
		DrawText(FormatText("Lap 1: %.02f", (float)lapTimer), 575, 50, 45, BLACK);
	}
	if (lapCounter == 2) {
		DrawText(FormatText("Lap 1: %.02f", (float)firstLap), 575, 50, 45, BLACK);
		DrawText(FormatText("Lap 2: %.02f", (float)lapTimer), 575, 100, 45, BLACK);
	}
	if (lapCounter == 3) {
		DrawText(FormatText("Lap 1: %.02f", (float)firstLap), 575, 50, 45, BLACK);
		DrawText(FormatText("Lap 2: %.02f", (float)secondLap), 575, 100, 45, BLACK);
		DrawText(FormatText("Lap 3: %.02f", (float)lapTimer), 575, 150, 45, BLACK);
	}
	if (lapCounter == 4) {

		DrawText(FormatText("Lap 1: %.02f", (float)firstLap), 575, 100, 45, BLACK);
		DrawText(FormatText("Lap 2: %.02f", (float)secondLap), 575, 150, 45, BLACK);
		DrawText(FormatText("Lap 3: %.02f", (float)thirdLap), 575, 200, 45, BLACK);
	}

	if (queueObject.size() == 5) {
		DrawTextureEx(texture, {404, 187}, 0.0f, 0.63f, WHITE);
	}
	if (queueObject.size() == 4) {
		DrawTextureEx(texture, { 30, 187 }, 0.0f, 0.63f, WHITE);
	}
	if (queueObject.size() == 3) {
		DrawTextureEx(texture, { 30, 705 }, 0.0f, 0.63f, WHITE);
	}
	if (queueObject.size() == 2) {
		DrawTextureEx(texture, { 404, 705 }, 0.0f, 0.63f, WHITE);
	}
	/*if (queueObject.size() == 1) {
		DrawTextureEx(texture, { 404, 450 }, 0.0f, 0.63f, WHITE);
	}*/
}
