#include "my_Hero.h"
#include "raylib/raylib.h"

#include <ctime>
#include <iostream>
#include <random>

myHero hero;

myHero::myHero()
{
	srand(time(NULL));
}

myHero::myHero(int _playerHealth, int _potionGiveOrTakeHealth)
{
	health = _playerHealth;
	potionHPModifier = _potionGiveOrTakeHealth;
}

myHero::~myHero()
{
}

myHero myHero::operator-(const myHero & rhs)
{
	myHero updatedHero;

	updatedHero.health = rhs.potionHPModifier - health;

	return myHero();
}

void myHero::draw()
{
	DrawText(name, 31.25f, 15.625f, 22, LIGHTGRAY);
	DrawText(special, 31.25f, 40.625f, 22, GOLD);
	DrawText(age, 31.25f, 65.625f, 22, PINK);
	DrawText(hitPoints, 31.25f, 90.625f, 22, GREEN);
	DrawText(wealth, 31.25f, 115.625f, 22, SKYBLUE);
}