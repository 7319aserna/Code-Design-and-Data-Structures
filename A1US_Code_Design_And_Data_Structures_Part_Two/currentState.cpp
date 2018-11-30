#include "currentState.h"
#include <iostream>

currentState::currentState() {
}

void currentState::operator=(currentState const &) {
}

int currentState::getState() {
	switch (state) {
		// Main Menu
	case 0: std::cout << "Current State: Main Menu" << std::endl;
		break;
		// Custom Containers
	case 1: std::cout << "Current State: Stack" << std::endl;
		break;
	case 2: std::cout << "Current State: Linked List" << std::endl;
		break;
	case 3: std::cout << "Current State: Object Pool" << std::endl;
		break;
		// Hashing, Sorting, and Search Algorithms
	case 4: std::cout << "Current State: Sorting Our High Score Table" << std::endl;
		break;
	case 5: std::cout << "Current State: Exit A1US Code Design And Data Structures Part Two" << std::endl;
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
