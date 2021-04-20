#include <ctime>
#include "raylib.h"
#include "spriteObjectPool.h"
#include <stdlib.h>

spriteObjectPool::spriteObjectPool() {
	r1.height = 25.0f;
	r1.width = 25.0f;
	r1.x = 25.0f;
	r1.y = 50.0f;
}

spriteObjectPool::~spriteObjectPool() {
}

void spriteObjectPool::draw() {
	DrawRectangle(r1.x, r1.y, r1.width, r1.height, BLACK);
}

void spriteObjectPool::update(float deltaTime) {
	r1.x = rand() % 960;
	r1.y += r1.y * deltaTime;
}
