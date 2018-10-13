#pragma once
#include <iostream>
#include "raylib/raylib.h"
class wizard
{
public:
	wizard();
	~wizard();

	bool isWizardAlive;

	const char *name;

	int gold;
	int health;
	int mana;
	int speed;
	
	Texture2D texture;
	
	Vector2 position;
	
	void draw();
	void update(float deltaTime);
};

