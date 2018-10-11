//meep.h
#pragma once
#include "raylib.h"

class meep
{
public:

	//Vars
	bool enabled = true;
	Texture2D texture;

	// Constructors & Destructors
	meep();					// This is the constructor declaration
	meep(bool _enabled);
	~meep();				// This is the destructor declaration

	// Misc Functions
	void refresh();
};