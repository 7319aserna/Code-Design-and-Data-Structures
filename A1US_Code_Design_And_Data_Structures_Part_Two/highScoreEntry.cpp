#include "highScoreEntry.h"

highScoreEntry::highScoreEntry(const std::string & _name, int _score, int _level)
{
	name = _name;
	score = _score;
	level = _level;
}

highScoreEntry::highScoreEntry()
{
}

highScoreEntry::~highScoreEntry()
{
}
