#pragma once
#include <iostream>
#include "raylib/raylib.h"
#include <string>

class wizardProjectile {
public:
	wizardProjectile();
	~wizardProjectile();

	bool projectileSpawned;

	int timer;

	Texture2D projectile;

	Vector2 projectilePosition;

	void draw();
	void update(float deltaTime);
};

class wizard
{
public:
	wizard();
	~wizard();

	wizardProjectile wPObject;

	bool isWizardAlive;

	const char *name;

	float rotation;
	float rotation_Timer;

	int attack;
	int gold;
	int health;
	int mana;
	int speed;
	
	Texture2D texture;
	
	Vector2 position;
	
	void draw();
	void update(float deltaTime);
};