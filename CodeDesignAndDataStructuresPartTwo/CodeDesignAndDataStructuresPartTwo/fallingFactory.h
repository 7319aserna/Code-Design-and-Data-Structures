#pragma once
#include "raylib.h"
#include "simpleSprite.h"

class fallingFactory {
	static simpleSprite* spriteMasters;
	static size_t spriteCount;

public:
	static void init();

	static simpleSprite * getRandom();
	static simpleSprite * getFromType(const std::string & _sprType);

	fallingFactory();
	~fallingFactory();
};