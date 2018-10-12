#pragma once

#include <iostream>
#include "raylib/raylib.h"

class tile {
public:
	tile();
	tile(const char* imageFilename);
	~tile();

	Color tint;
	Texture2D texture;
};
