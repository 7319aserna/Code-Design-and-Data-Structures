#include "gameState.h"
#include <iostream>

GameState::GameState() {
}

void GameState::operator=(GameState const &) {
}

int GameState::getState() {
	switch (state) {
	case 0: // Main Menu
		break;
	case 1: // Start
		break;
	case 2: // Options
		break;
	/*case 4: // Gameplay In Progress
		break;*/
	case 3: // Game Exit
		break;
	}
	return state;
}

int GameState::setState(int newState) {
	state = newState;
	return state;
}

GameState & GameState::GetInstance() {
	static GameState instance;
	return instance;
}

GameState::~GameState() {
}
