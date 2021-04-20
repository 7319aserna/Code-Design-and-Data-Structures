#pragma once
#include <iostream>
#include "raylib.h"

class spriteObjectPool {
public:
	spriteObjectPool();
	~spriteObjectPool();
	
	Rectangle r1;
	Vector2 pos;

	void draw();
	void update(float deltaTime);
};