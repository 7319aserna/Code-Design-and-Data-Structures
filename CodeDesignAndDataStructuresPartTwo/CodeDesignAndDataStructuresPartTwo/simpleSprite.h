#pragma once
#include <iostream>
#include "raylib.h"
class simpleSprite {
public:
	std::string sprType;
	Vector2 pos;
	float rot;
	Rectangle r1, r2;
	Texture2D texture;

	void translate(Vector2 delta);	// Move the sprites position by delta.
	void draw();
	simpleSprite();
	simpleSprite(const std::string & filename, const std::string _sprType = "", float _scale = 1);
	simpleSprite * Clone();
};