#pragma once

#include <string>

class player {
public:
	player();
	player(const std::string &n, int scor);

	~player();

	std::string name;
	int score;
};