#pragma once
#include "raylib/raylib.h"
#include <string>

class player
{
public:
	player();
	player(const std::string &fileName);		// loads a texture from the given path
	~player();									// unloads the texture

	Vector2 position = { 100,100 };				// current location
	float speed = 0;							// units per second to move
	Texture2D mySprite;							// texture used to draw the player

	virtual bool moveTo(const Vector2 &dest);	// moves the Player towards the given location
												// (returns true if the destination is reached)

	void draw();								// draws player to the screen
};