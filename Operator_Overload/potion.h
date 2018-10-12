#pragma once

#include "raylib/raylib.h"

#include <string>

class potion {
public:

	std::string name;		// What the potion is called
	int hpModifier;			// How much health does the potion give or take (to/from) the player
	int quality;			// How effective the potion is
	std::string useByDate;	// How long the potion's effectivness lasts
};