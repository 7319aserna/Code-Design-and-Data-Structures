#include "gameState.h"
#include <iostream>
#pragma once
#include "raceTrack.h"
#include "raylib.h"

class bestLapLevel {
public:
	bestLapLevel();
	~bestLapLevel();

	// Buttons
	Texture2D buttonTexture;

	// Collision
	bool active;
	Vector2 mousePoint;

	// Textures
	Texture2D highScoreTexture;
	Texture2D texture;

	// Void Functions
	void draw(raceTrack& racetrackReference);
	void update(float deltaTime);
};