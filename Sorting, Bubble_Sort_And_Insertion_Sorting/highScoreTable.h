#pragma once
#include "HighScoreEntry.h"
#include <vector>

class HighScoreTable
{
public:
	// For the table, we would want to have all...
	// ... of the highscores be displayed here...
	// ... then have them sorted.

	// We have a vector that will use our highScoreEntries...
	// ... and then put them into a new vector.
	std::vector<highScoreEntry> hsVector;
	std::vector<highScoreEntry> topNNScores(int topRows);
	bool pruneBottomNNScores(int bottomRows);

	HighScoreTable();
	HighScoreTable(std::string fileName);
	~HighScoreTable();
};