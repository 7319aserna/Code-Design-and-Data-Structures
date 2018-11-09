#pragma once
#include "raylib/raylib.h"
#include "SimpleSprite.h"

class FallingFactory {
	static SimpleSprite* spriteMasters;
	static size_t spriteCount;

public:
	static void init();

	static SimpleSprite * getRandom();
	static SimpleSprite * getFromType(const std::string & _sprType);

	FallingFactory();
	~FallingFactory();
};