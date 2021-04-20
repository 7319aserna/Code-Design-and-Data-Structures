#include "libraries.h"

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

			std::cout << "\nWhat instance would you like to view?" << "\n1. Set amount of numbers in linked list" << "\n2. One number in linked list" << std::endl;
			std::cout << "\nWhen ready, please input instance number and press enter." << std::endl;
			std::cin >> userInput;

			if (userInput == 1) {
				int linkedListUserAmount;
				std::cout << "\nHow many numbers would you like in the linked list?" << std::endl;
				std::cin >> linkedListUserAmount;

				for (int i = 0; i < linkedListUserAmount; i++) {
					std::cout << "\nWhat number would you like to input for the linked list?" << std::endl;
					std::cin >> userInput;
					linkedList.push_front(userInput);
				}
				// Numbers in our Linked List ( User Input )
				std::cout << "\nNumbers in our Linked List" << std::endl;
				std::cout << "--------------------------" << std::endl;
				std::cout << "Front: " << linkedList.front() << std::endl;

				// This would display all numbers from Linked List
				linkedList.display();

				// Iterators
				for (auto it = linkedList.begin(); it != linkedList.end(); ++it) {
					std::cout << (*it) << std::endl;
				}

				// Remove an number from the front
				std::cout << "\nThe front number will now be popped from the Linked List. Press enter to continue." << std::endl;
				std::cin.get() == '\n';
				std::cin.get() == '\n';
				linkedList.pop_front();

				// Remove an number(s) from the linked list
				std::cout << "\nWhat number(s) would you like to remove from the Linked List?" << std::endl;
				std::cin >> linkedListUserAmount;
				// This would remove any number(s) from Linked List dependent on userInput
				linkedList.remove(linkedListUserAmount);

				// This would display the updated Linked List
				std::cout << "\nNumbers in our updated Linked List" << std::endl;
				linkedList.display();
			}

			if (userInput == 2) {
				// Number in our Linked List (99)
				std::cout << "\nNumber in our Linked List" << std::endl;
				std::cout << "--------------------------" << std::endl;
				linkedList.push_front(99);

				std::cout << "Front: 99" << std::endl;

				// This would display all numbers from Linked List
				linkedList.display();

				std::cout << "\nRemove 99 from the Linked List. Press enter to continue." << std::endl;
				std::cin.get() == '\n';
				std::cin.get() == '\n';

				// This would remove 99 from Linked List
				linkedList.remove(99);

				// This would display the updated Linked List
				std::cout << "\nUpdated Linked List" << std::endl;
				linkedList.display();
			}

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
			tObjectPool<spriteObjectPool> sSObject(5);

			int screenWidth = 960;
			int screenHeight = 540;

			InitWindow(screenWidth, screenHeight, "Object Pool");
			SetTargetFPS(60);

			spriteObjectPool * lastSprite[5]; //= nullptr;
			for (int i = 0; i < sSObject.capacity(); i++) {
				lastSprite[i] = nullptr;
			}

			int counter = sSObject.capacity();

			while (!WindowShouldClose()) {
				BeginDrawing();
				ClearBackground(RAYWHITE);

				DrawText("Objects Remaining In Pool: ", 25, 25, 25, BLACK);
				DrawText(FormatText("%01i", sSObject.capacity()), 337, 25, 25, BLACK);

				if (IsKeyPressed(KEY_Q) && counter > 0) {
					// Make an array and store all of those pointers to the array.
					// Then when recycling find that specific pointer to the array and then return it.
					lastSprite[counter] = sSObject.retrieve();
					counter--;
				}

				if (IsKeyPressed(KEY_E) && lastSprite != nullptr && counter < 6)
				{
					counter++;
					sSObject.recycle(lastSprite[counter]);
					lastSprite[counter] = nullptr;
				}
				EndDrawing();
			}

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