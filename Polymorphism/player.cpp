#include <iostream>
#include "player.h"
#include "raylib/raylib.h"
#include <string>

player::player() {

}

player::player(const std::string & fileName)
{
	mySprite = LoadTexture(fileName.c_str());
}

player::~player()
{
	UnloadTexture(mySprite);
}

bool player::moveTo(const Vector2 & dest)
{
	return false;
}

void player::draw()
{
	DrawTexture(mySprite, position.x, position.y, WHITE);
}
