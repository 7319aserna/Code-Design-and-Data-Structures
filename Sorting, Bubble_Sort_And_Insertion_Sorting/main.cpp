#include "libraries.h"
#include "highScoreTable.h"

int main() {
	/*
	// Unsorted List
	HighScoreTable hst("highscores.txt");

	// Sorted list in ascending order
	std::cout << "Sorted list in ascending order" << std::endl;
	std::vector<highScoreEntry> topScores = hst.topNNScores(5);

	// Remove the bottom scores
	std::cout << '\n' << "Remove the bottom scores" << std::endl;
	hst.pruneBottomNNScores(6);

	// Display the scores with the prune scores included
	hst.topNNScores(11);

	// Sorted list in descending order
	std::cout << '\n' << "Sorted list in descending order" << std::endl;
	hst.bottomNNScores(18);

	hst.saveDataToDisk("SJ.txt");
	*/

	HighScoreTable hst("highscores.txt");

	//hst.pruneBottomNNScores(6);
	//hst.topNNScores(11);
	hst.bottomNNScores(11);

	hst.saveDataToDisk("SJ.txt");

	return 0;
}