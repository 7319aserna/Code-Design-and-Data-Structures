#pragma once
#include "highScoreEntry.h"
#include <vector>

class highScoreTable
{
public:
	// For the table, we would want to have all of the highscores be ...
	// displayed, then have them sorted.
	std::vector<highScoreEntry> hsVector;
	// Displays the scores in ascending order
	std::vector<highScoreEntry> topNNScores(int topRows);
	// Displays the scores in descending order
	std::vector<highScoreEntry> bottomNNScores(int bottomRows);
	bool pruneBottomNNScores(int bottomRows);
	// Saves (Overwrites) the file
	std::vector<highScoreEntry> saveDataToDisk(std::string fileName);

	highScoreTable();
	highScoreTable(std::string fileName);
	std::vector<std::string> split(std::string& line);
	~highScoreTable();
};