#include "currentState.h"
#include <iostream>

currentState::currentState() {
}

void currentState::operator=(currentState const &) {
}

int currentState::getState() {
	switch (state) {
		// Main Menu
		case 0: std::cout << "Main Menu" << std::endl;
		break;
		// Custom Containers
		case 1: std::cout << "Stack" << std::endl;
			break;
		case 2: std::cout << "Linked List" << std::endl;
			break;
		case 3: std::cout << "Object Pool" << std::endl;
			break;
		// Hashing, Sorting, and Search Algorithms
		case 4: std::cout << "Sorting Our High Score Table" << std::endl;
			break;
	}
	return state;	// This would return whatever state the...
					// ... game is in.
}

int currentState::setState(int newState) {
	state = newState;
	return state;
}

currentState & currentState::GetInstance() {
	static currentState instance;
	return instance;
}

currentState::~currentState() {
}
