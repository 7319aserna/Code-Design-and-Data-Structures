#pragma once

#include <iostream>
#include "raylib/raylib.h"

class tile {
public:
	tile();
	tile(const char* imageFilename);
	~tile();

	Color tint;
	int positionX;
	int positionY;
	Texture2D texture;
};
