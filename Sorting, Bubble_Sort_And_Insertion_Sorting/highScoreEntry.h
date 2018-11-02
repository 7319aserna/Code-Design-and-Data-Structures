#pragma once
#include <iostream>
#include <string>

// Let's suppose we create a High Score class which stores the name, score, and the level.
class highScoreEntry
{
public:
	highScoreEntry(const std::string & _name, int _score = 1, int _level = 1);

	std::string name;
	int score = 0;
	int level = 1;

	highScoreEntry();
	~highScoreEntry();
};