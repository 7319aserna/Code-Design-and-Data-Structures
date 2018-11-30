#include "highScoreEntry.h"
#include "highScoreTable.h"
#include "libraries.h"

std::vector<highScoreEntry> highScoreTable::topNNScores(int topRows)
{
	// Run through the vector once to see how many numbers are there (Total)
	// If there are any that have the score of -1, then subtract
	int total = 0;
	for (int s = 0; s < hsVector.size(); s++) {
		if (hsVector[total].score != -1) {
			total++;
		}
	}

	for (int iteration = 0; iteration < hsVector.size(); iteration++) {
		int noSwapped = 0;

		highScoreEntry emptyHighScoreEntry;
		emptyHighScoreEntry.name = "-----";
		emptyHighScoreEntry.level = 0;
		emptyHighScoreEntry.score = -1;

		for (int leftBubble = 0; leftBubble < hsVector.size() - 1; leftBubble++) {
			int rightBubble = leftBubble + 1;

			// This will break out of the bubble loop and add one...
			// to the iteration.
			if (rightBubble > hsVector.size()) {
				break;
			}

			if (hsVector[leftBubble].score > hsVector[rightBubble].score == -1) {
				break;
			}

			// Bubble Sort
			/*
			if (hsVector[leftBubble].score > hsVector[rightBubble].score) {
			highScoreEntry tempScoreHolder;
			tempScoreHolder = hsVector[leftBubble];
			hsVector[leftBubble] = hsVector[rightBubble];
			hsVector[rightBubble] = tempScoreHolder;
			}
			else if (hsVector[leftBubble].score < hsVector[rightBubble].score) {
			noSwapped++;
			}
			*/

			// Insertion Sort
			/*
			for (hsVector[leftBubble].score; hsVector[leftBubble].score > hsVector[rightBubble].score; leftBubble--) {
			if (leftBubble < 0) {
			break;
			}
			highScoreEntry tempScoreHolder;
			tempScoreHolder = hsVector[leftBubble];
			hsVector[leftBubble] = hsVector[rightBubble];
			hsVector[rightBubble] = tempScoreHolder;
			}

			if (hsVector[leftBubble].score < hsVector[rightBubble].score) {
			noSwapped++;
			}
			*/

			// ----- Insert Sort Code Here ----- //
			for (hsVector[leftBubble].score; hsVector[leftBubble].score > hsVector[rightBubble].score; leftBubble--) {
				if (leftBubble < 0) {
					break;
				}
				highScoreEntry tempScoreHolder;
				tempScoreHolder = hsVector[leftBubble];
				hsVector[leftBubble] = hsVector[rightBubble];
				hsVector[rightBubble] = tempScoreHolder;
			}

			if (hsVector[leftBubble].score < hsVector[rightBubble].score) {
				noSwapped++;
			}
			// ----- End Of Sort Code ----- //
		}

		if (noSwapped == hsVector.size() - 1) {
			std::cout << "Name " << "Score" << '\n' << "---- -----" << std::endl;

			for (int i = topRows; i > hsVector.size(); hsVector.size() + 1) {
				hsVector.push_back(emptyHighScoreEntry);
			}

			for (int i = 0; i < topRows; i++) {
				std::cout << hsVector[i].name << ", " << hsVector[i].score << std::endl;
			}
			return hsVector;
		}
	}
}

std::vector<highScoreEntry> highScoreTable::bottomNNScores(int bottomRows)
{
	// Run through the vector once to see how many numbers are there (Total)
	// If there are any that have the score of -1, then subtract
	int total = 0;
	for (int s = 0; s < hsVector.size(); s++) {
		if (hsVector[total].score != -1) {
			total++;
		}
	}

	for (int iteration = 0; iteration < hsVector.size(); iteration++)
	{
		int noSwapped = 0;

		highScoreEntry emptyHighScoreEntry;
		emptyHighScoreEntry.name = "-----";
		emptyHighScoreEntry.level = 0;
		emptyHighScoreEntry.score = -1;

		for (int leftBubble = 0; leftBubble < hsVector.size() - 1; leftBubble++) {

			int rightBubble = leftBubble + 1;

			// This will break out of the bubble loop and add one...
			// to the iteration.
			if (rightBubble > hsVector.size()) {
				break;
			}

			if (hsVector[leftBubble].score > hsVector[rightBubble].score == -1) {
				break;
			}

			// Bubble Sort
			/*
			if (hsVector[leftBubble].score < hsVector[rightBubble].score) {
				highScoreEntry tempScoreHolder;
				tempScoreHolder = hsVector[rightBubble];
				hsVector[rightBubble] = hsVector[leftBubble];
				hsVector[leftBubble] = tempScoreHolder;
			}

			else if (hsVector[leftBubble].score > hsVector[rightBubble].score) {
				noSwapped++;
			}
			*/

			// Insertion Sort
			/*
			for (; hsVector[leftBubble].score < hsVector[rightBubble].score;) {

				highScoreEntry tempScoreHolder;
				tempScoreHolder = hsVector[leftBubble];
				hsVector[leftBubble] = hsVector[rightBubble];
				hsVector[rightBubble] = tempScoreHolder;

				if (leftBubble <= 0) {
					break;
				}

				leftBubble--;
				rightBubble--;
			}

			if (hsVector[leftBubble].score > hsVector[rightBubble].score) {
				noSwapped++;
			}
			*/

			// ----- Insert Sort Code Here ----- //
			for (; hsVector[leftBubble].score < hsVector[rightBubble].score;) {

				highScoreEntry tempScoreHolder;
				tempScoreHolder = hsVector[leftBubble];
				hsVector[leftBubble] = hsVector[rightBubble];
				hsVector[rightBubble] = tempScoreHolder;

				if (leftBubble <= 0) {
					break;
				}

				leftBubble--;
				rightBubble--;
			}

			if (hsVector[leftBubble].score > hsVector[rightBubble].score) {
				noSwapped++;
			}
			// ----- End Of Sort Code ----- //
		}

		if (noSwapped == total - 1) {
			std::cout << "Name " << "Score" << '\n' << "---- -----" << std::endl;

			for (int i = bottomRows; i > hsVector.size(); hsVector.size() + 1) {
				hsVector.push_back(emptyHighScoreEntry);
			}

			for (int i = 0; i < bottomRows; i++) {
				std::cout << hsVector[i].name << ", " << hsVector[i].score << std::endl;
			}
			return hsVector;
		}
	}
}

bool highScoreTable::pruneBottomNNScores(int bottomRows)
{
	for (int i = 0; i < bottomRows; i++) {
		hsVector.pop_back();
	}
	return false;
}

std::vector<highScoreEntry> highScoreTable::saveDataToDisk(std::string fileName)
{
	std::fstream file;
	file.open(fileName, std::ios::trunc | std::ios::out);

	if (!file.is_open()) {
		std::cerr << "File not found" << std::endl;
		return hsVector;
	}

	std::string buffer;
	while (std::getline(file, buffer)) {
		std::cout << buffer << std::endl;
	}
	file.clear();

	file.seekp(0, std::ios_base::end);

	file << "Name " << "Level " << "Score" << '\n' << "---- ----- -----" << std::endl;

	for (auto invIte = hsVector.begin(); invIte != hsVector.end(); invIte++)
	{
		file << invIte->name << ", " << invIte->score << ", " << invIte->level << std::endl;
	}

	file.flush();
	file.close();

	return hsVector;
}

highScoreTable::highScoreTable()
{
}

highScoreTable::highScoreTable(std::string fileName) {
	// Instantiate and initialize the whole highscore table
	std::fstream file(fileName, std::ios::in);
	std::string buffer;

	// Now I see where they get the Rtn from.
	std::vector <std::string> rtn;

	highScoreEntry tmphighScoreEntry;
	std::getline(file, buffer);

	// Iterates until error or EOF
	while (std::getline(file, buffer)) {
		rtn = split(buffer);
		tmphighScoreEntry.score = std::stoi(rtn.back().c_str());
		rtn.pop_back();
		tmphighScoreEntry.level = std::stoi(rtn.back().c_str());
		rtn.pop_back();
		// For string, you don't need std::stof, or std::stoi.
		tmphighScoreEntry.name = rtn.back();
		rtn.pop_back();
		hsVector.push_back(tmphighScoreEntry);
	}

	// Once each element has been organized, the file should close...
	// ending the while loop and continuing on.
	file.close();
}

std::vector<std::string> highScoreTable::split(std::string & line)
{
	std::vector<std::string> result;
	std::stringstream lineStream(line);
	std::string cell;

	while (std::getline(lineStream, cell, ',')) {
		result.push_back(cell);
	}

	if (!lineStream && cell.empty()) {
		result.push_back("");
	}
	return result;
}

highScoreTable::~highScoreTable()
{
}
