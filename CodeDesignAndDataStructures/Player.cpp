#include <iostream>

#include "player.h"

player::player() {

	name = "";
	score = 0;
}

player::player(const std::string & const n, int scor) {
	name = std::string(n);
	score = scor;
}

player::~player() {
	std::cout << "Player destroyed" << std::endl;
}