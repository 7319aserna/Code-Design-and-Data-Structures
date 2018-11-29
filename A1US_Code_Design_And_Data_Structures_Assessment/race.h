#include "player.h"
#include "raylib.h"
#pragma once

class race {
public:
	race();
	~race();

	// What would we need to have all over the map?
	Texture2D texture;
	// Player goes through each checkpoint
	Vector2 checkpointPosition;
	int lapCounter;
	// How much time has past since the player has completed a lap.
	float lapTimer;
	// How much time was the first lap
	float firstLap;
	// How much time was the second lap
	float secondLap;
	// How much time was the third lap
	float thirdLap;
	// Out of all the laps, which one was the fastest?
	float fastestLap;

	// In the update, we will put the checkpoints into a queue
	void update(float deltaTime, player& player);
	void draw();
};