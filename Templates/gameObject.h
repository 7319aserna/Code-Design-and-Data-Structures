#include <iostream>
#pragma once
#include "raylib/raylib.h"

// Exercise 2 -	GameObject

template <typename T>
class gameObject :
	Vector2
{
public:
	gameObject() {
		object = new T;
	}

	~gameObject() {
		delete object;
	}
  
	T * object;	// pointer to underlying instance of type T
	bool enabled;

	void update(float delta)
	{
		// To Do: how to update the object?
		if (enabled) {
			object->update(delta);
		}
	}

	void render()
	{
		// To Do: how to render the object?
		if (enabled) {
			object->render();
		}
	}

	void setPosition() {

	}
};

class ninja
{
public:
	void update(float delta) {
		std::cout << "Ninja update enabled" << std::endl;
	}

	void setPosition() {

	}

	void render() {
		std::cout << "Ninja render enabled" << std::endl;
	}
};

class soldier
{
public:
	void update(float delta) {
		std::cout << "Soldier update enabled" << std::endl;
	}

	void setPosition() {
		
	}

	void render() {
		std::cout << "Soldier render enabled" << std::endl;
	}
};