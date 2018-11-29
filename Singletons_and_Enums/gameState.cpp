#include "gameState.h"
#include <iostream>

GameState::GameState() {
}

void GameState::operator=(GameState const &) {
}

int GameState::getState() {
	switch (state) {
		case 0: std::cout << "Main Menu" << std::endl;
			break;
		case 1: std::cout << "Start" << std::endl;
			break;
		case 2: std::cout << "Options" << std::endl;
			break;
		case 4: std::cout << "Gameplay in progress" << std::endl;
			break;
		case 5: std::cout << "Game Exit" << std::endl;
			break;
	}
	return state;	// This would return whatever state the...
					// ... game is in.
}

int GameState::setState(int newState) {
	// As a little note: If i wanted to make each menu, ...
	// ... wouldn't i wanted to make a void and make a new...
	// ... texture and load other things?
	state = newState;
	return state;
}

GameState & GameState::GetInstance() {
	static GameState instance;
	return instance;
}

GameState::~GameState() {
}
