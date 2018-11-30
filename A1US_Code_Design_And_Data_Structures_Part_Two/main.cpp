#include "currentState.h"
#include "highScoreTable.h"
#include <iostream>
#include <string>
#include "tLinkedList.h"
#include "tStack.h"

int main() {
	while (currentState::GetInstance().getState() != 5) {
		// This would set the current state to be the Main Menu
		currentState::GetInstance().setState(0);

		int userInput;

		if (currentState::GetInstance().getState() == 0) {
			std::cout << "\nHello, what section of A1US Code Design And Data Structures Part Two would you like to open?" << std::endl;
			std::cout << "Section 1: Stacks" << std::endl;
			std::cout << "Section 2: Linked List" << std::endl;
			std::cout << "Section 3: Object Pool" << std::endl;
			std::cout << "Section 4: Sorting Our High Score Table" << std::endl;
			std::cout << "Section 5: Exit A1US Code Design And Data Structures Part Two" << std::endl;
			std::cout << "\nWhen ready, please input selection number and press enter." << std::endl;
			std::cout << "Section ";
			std::cin >> userInput;
			std::cout << std::endl;

			currentState::GetInstance().setState(userInput);
		}

		// If 1 was inputted
		if (currentState::GetInstance().getState() == 1) {
			
			// ***---Stacks---*** //
			tStack<int> stackObject;

			// Numbers in our Stack (28, 91, 64, 61, 34)
			std::cout << "\nNumbers In Our Stack" << std::endl;
			stackObject.push(28);
			std::cout << stackObject.top() << std::endl;
			stackObject.push(91);
			std::cout << stackObject.top() << std::endl;
			stackObject.push(64);
			std::cout << stackObject.top() << std::endl;
			stackObject.push(61);
			std::cout << stackObject.top() << std::endl;
			stackObject.push(34);
			std::cout << stackObject.top() << std::endl;

			// Next we would display the size and the top of the stack
			std::cout << "Size: " << stackObject.size() << std::endl;
			std::cout << "Top: " << stackObject.top();
			std::cout << std::endl;

			// Remove(pop) two from top of stack
			std::cout << "\nRemove(pop) two from top of stack" << std::endl;
			stackObject.pop();
			stackObject.pop();

			// Update the changes that were made
			std::cout << "\nNew Size: " << stackObject.size() << std::endl;
			std::cout << "New Top: " << stackObject.top() << std::endl;

			// Back to Main Menu
			std::cout << "\nWhen ready, press enter to go back to the Main Menu." << std::endl;
			std::cin.get() == '\n';
			if (std::cin.get() == '\n') {
				currentState::GetInstance().setState(0);
				system("CLS");
			}
		}

		// If 2 was inputted
		if (currentState::GetInstance().getState() == 2) {
			
			// ***---Linked List---*** //
			tForwardList<float> linkedList;

			// Numbers in our Linked List (99, 86, 69, 83, 48, 86, 23, 29, 35, 3)
			std::cout << "\nNumbers in our Linked List" << std::endl;
			std::cout << "--------------------------" << std::endl;
			linkedList.push_front(99);
			linkedList.push_front(86);
			linkedList.push_front(69);
			linkedList.push_front(83);
			linkedList.push_front(48);
			linkedList.push_front(86);
			linkedList.push_front(23);
			linkedList.push_front(29);
			linkedList.push_front(35);
			linkedList.push_front(3);

			std::cout << "Back: 3" << " Front: 99" << std::endl;

			// This would display all numbers from Linked List
			linkedList.display();

			std::cout << "What number would you like to remove from the Linked List?" << std::endl;
			std::cin >> userInput;

			// This would remove any number(s) from Linked List dependent on userInput
			linkedList.remove(userInput);

			// This would display the updated Linked List
			std::cout << "\nNumbers in our updated Linked List" << std::endl;
			linkedList.display();

			// Back to Main Menu
			std::cout << "\nWhen ready, press enter to go back to the Main Menu." << std::endl;
			std::cin.get() == '\n';
			if (std::cin.get() == '\n') {
				currentState::GetInstance().setState(0);
				system("CLS");
			}
		}

		// If 3 was inputted
		if (currentState::GetInstance().getState() == 3) {

			// ***---Object Pool---*** //



			// Back to Main Menu
			std::cout << "\nWhen ready, press enter to go back to the Main Menu." << std::endl;
			std::cin.get() == '\n';
			if (std::cin.get() == '\n') {
				currentState::GetInstance().setState(0);
				system("CLS");
			}
		}
	
		// If 4 was inputted
		if (currentState::GetInstance().getState() == 4) {

			// ***---Sorting Our High Score Table---*** //
			std::string userSortInput;
			std::string userRemoveInput;

			std::cout << "\nIn the A1US Code Design And Data Structures Part Two folder, there will be a highscores.txt." << "\nDO NOT DELETE that file but, you can change the values to your heart's content." << std::endl;
			highScoreTable hst("highscores.txt");

			std::cout << "\nHow would you like to sort the scores? Ascending or Descending order?" << std::endl;
			std::cout << "Please input ascending or descending to sort the High Score Table in the order inputted." << std::endl;
			std::cin >> userSortInput;

			if (userSortInput == "ascending") {
				// Sorted list in ascending order
				std::cout << "Sorted list in ascending order" << std::endl;
				hst.topNNScores(11);
			}

			if (userSortInput == "descending") {
				// Sorted list in descending order
				std::cout << '\n' << "Sorted list in descending order" << std::endl;
				hst.bottomNNScores(11);
			}

			// Optional: Removing Scores
			std::cout << "\nWould you like to remove a set amount of scores? Yes or No?" << std::endl;
			std::cout << "Please input Yes or No remove a set amount of scores from the High Score Table." << std::endl;
			std::cin >> userRemoveInput;

			if (userRemoveInput == "Yes") {
				std::cout << "\nPlease input the amount of scores to remove from the bottom of the High Score Table. Max: 11" << std::endl;
				std::cin >> userInput;

				hst.pruneBottomNNScores(userInput);

				if (userSortInput == "ascending") {
					std::cout << std::endl;
					hst.topNNScores(11);
				}
				else {
					std::cout << std::endl;
					hst.bottomNNScores(11);
				}
			}

			if (userRemoveInput == "No") {
				if (userSortInput == "ascending") {
					std::cout << std::endl;
					hst.topNNScores(11);
				}
				else {
					std::cout << std::endl;
					hst.bottomNNScores(11);
				}
			}

			// Save changes to new file(Disk)
			std::cout << "\nPlease create a new text document file name to save your changes." << std::endl;
			std::cout << "Please be sure at the end of your filename, to include .txt" << std::endl;
			std::cin >> userSortInput;
			hst.saveDataToDisk(userSortInput);

			std::cout << "When you quit the application, be sure to check out your changes in the your A1US Code Design And Data Structures Part Two folder." << std::endl;

			// Back to Main Menu
			std::cout << "\nWhen ready, press enter to go back to the Main Menu." << std::endl;
			std::cin.get() == '\n';
			if (std::cin.get() == '\n') {
				currentState::GetInstance().setState(0);
				system("CLS");
			}
		}
}

	// If 5 was inputted
	if (currentState::GetInstance().getState() == 5) {
		return 0;
	}
}