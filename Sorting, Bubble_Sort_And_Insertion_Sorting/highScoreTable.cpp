#include "highScoreEntry.h"
#include "highScoreTable.h"

// So for the highscoreEntry will make one and then...
// ... will get added to a table
std::vector<highScoreEntry> HighScoreTable::topNNScores(int topRows)
{
	// In this case, instead of making another array...
	// ... I can just pop and push back each individual...
	// ... entry into a new one.
	return std::vector<highScoreEntry>();
}

bool HighScoreTable::pruneBottomNNScores(int bottomRows)
{
	return false;
}

HighScoreTable::HighScoreTable()
{
}

HighScoreTable::HighScoreTable(std::string fileName)
{
}

HighScoreTable::~HighScoreTable()
{
}
