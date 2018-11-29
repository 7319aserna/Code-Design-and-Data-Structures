#include "player.h"
#include "raylib.h"
#pragma once

class raceTrack {
public:
	raceTrack();
	~raceTrack();

	// What would we need to have in a Race Track?
	Texture2D texture;
	
	// As the vehicle moves through each checkpoint, it's position moves. 
	Vector2 checkpointPosition;
	
	// How many laps have been completed?
	int lapCounter;

	// How much time has been past since the vehicle completed a lap?
	float lapTimer;

	// How much time was the first lap?
	float firstLap;

	// How much time was the second lap?
	float secondLap;

	// How much time was the third lap?
	float thirdLap;

	// Out of all the laps, which one was the fastest?
	float fastestLap;

	void update(float deltaTime, player& player);
	void draw();
};