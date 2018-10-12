#pragma once

#include "raylib/raylib.h"

#include <iostream>
#include <string>

class myHero {
public:

	myHero();
	myHero(int, int);
	~myHero();

	myHero operator-(const myHero &rhs);

	// Variables
	bool isPlayerAlive;			// Does the player have health?
	const char* name;			// Name
	const char* special;		// Special (text)
	const char* age;			// How old the player is
	const char* hitPoints;		// How much damage the player deals
	const char* wealth;			// How much money the player has
	int health;					// How much health does the player have
	int potionHPModifier;		// Health taken or given to the player by the potion

	void draw();
};

// Note: Have a while loop 
// Depending on the potion and how much health it took or gave,
// Show that sprite
// If they restart, delete the sprite and let them try again