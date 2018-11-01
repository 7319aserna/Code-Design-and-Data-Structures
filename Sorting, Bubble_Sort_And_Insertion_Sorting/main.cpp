// We can import a file that contains comma-separated values (csv) and use it...
// ... to populate a vector that holds High Score objects.
#include <algorithm>
#include <fstream>
#include "highScoreEntry.h"
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

std::vector<std::string> split(std::string& line);
int main() {
	std::vector <highScoreEntry> highScores;

	std::fstream file("highscores.txt", std::ios::in);
	std::string buffer;
	std::vector <std::string> rtn;			// Now I see where they get the Rtn from.

	highScoreEntry tmphighScoreEntry;
	
	while (std::getline(file, buffer)) {	// Iterates until error or EOF
		rtn = split(buffer);
		tmphighScoreEntry.level = std::stoi(rtn.back());
		rtn.pop_back();
		tmphighScoreEntry.score = std::stof(rtn.back());
		rtn.pop_back();
		tmphighScoreEntry.name = rtn.back();	// For string, you don't ...
												// ... need std::stof, or std::stoi.
		rtn.pop_back();
		highScores.push_back(tmphighScoreEntry);
	}
	file.close();

	for (auto invIte = highScores.begin(); invIte != highScores.end(); invIte++) {
		std::cout << invIte->name << "," << invIte->score << "," << invIte->level << std::endl;
	}

	return 0;
}

std::vector<std::string> split(std::string& line) {
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