#pragma once
#include "player.h"
#include "raylib/raylib.h"

class wizard :
	public player
{
public:
	wizard(const std::string &fileName);
	~wizard();

	bool moveTo(const Vector2 &dest) override;
};