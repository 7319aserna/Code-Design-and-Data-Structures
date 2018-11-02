// We can import a file that contains comma-separated values (csv) and use it...
// ... to populate a vector that holds High Score objects.
#include <algorithm>
#include <fstream>
#include "highScoreEntry.h"
#include "highScoreTable.h"
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

std::vector<std::string> split(std::string& line);
int main() {
	std::vector <highScoreEntry> highScores;
	std::vector <highScoreEntry> highScoreTable;

	std::fstream file("highscores.txt", std::ios::in);
	std::string buffer;
	std::vector <std::string> rtn;			// Now I see where they get the Rtn from.

	highScoreEntry tmphighScoreEntry;
	std::getline(file, buffer);
	std::cout << "Unsorted High Score Table" << '\n' << std::endl;
	int size = 0;
	while (std::getline(file, buffer)) {	// Iterates until error or EOF
		rtn = split(buffer);
		tmphighScoreEntry.level = std::stoi(rtn.back().c_str());
		rtn.pop_back();
		tmphighScoreEntry.score = std::stoi(rtn.back().c_str());
		rtn.pop_back();
		tmphighScoreEntry.name = rtn.back();	// For string, you don't ...
												// ... need std::stof, or std::stoi.
		rtn.pop_back();
		highScores.push_back(tmphighScoreEntry);
		size++;
		std::cout << "Name: " << tmphighScoreEntry.name << '\n' << "Score: " << tmphighScoreEntry.score << '\n' << "Level: " << tmphighScoreEntry.level << '\n' << "Size: " << size << '\n' << std::endl;
	}

	// After the while loop has finished(When all of the lines have...
	// ... been created), We would create a new while loop which will...
	// ... sort all of those lines and push them back.
		// TODO: Bubble Sort Implementation goes here.
		for (int start = 0; start != size; start++) {	// Size would equal 11 at this point.
			for (int end = size; end != start; end--) {	// At the beginning, end = 11
				if (highScores.at(end /*or tmphighScoreEntry.score?*/ /*11th index*/) < highScores.at(end - 1 /*10th index*/)) {
				// Compare The SCORESSSSSSSSSDSSS		
				}
			}
			/* Once each element has been organized, the file should close...
			... ending the while loop and continuing on.*/
			file.close();
			std::cout << "File has been closed." << std::endl;
		}	

	/*for (auto invIte = highScores.begin(); invIte != highScores.end(); invIte++) {
		std::cout << invIte->name << "," << invIte->score << "," << invIte->level << '\n' << std::endl;
	}*/

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