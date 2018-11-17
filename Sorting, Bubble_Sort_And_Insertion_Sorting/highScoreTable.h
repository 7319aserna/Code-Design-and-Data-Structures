#pragma once
#include "HighScoreEntry.h"
#include <vector>

class HighScoreTable
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

	HighScoreTable();
	HighScoreTable(std::string fileName);
	std::vector<std::string> split(std::string& line);
	~HighScoreTable();
};