#include <iostream>
#include "player.h"
#include "tQueue.h"
#include "tStack.h"
#include "tVector.h"
#include <vector>

/*
void printTop(const tStack<int> &stack)
{
	std::cout << std::endl;
	std::cout << "Const Top: " << stack.top() << std::endl;
}
*/

int screenWidth = 960;
int screenHeight = 540;

int main()
{
	// In order to make an array using the tVector class, we would have to make...
	// ... a Vector that would be able to use a type (int, float, etc) and in this...
	// ... instance, we will call it BottomlessInt.
	std::vector<int> bottomlessInt;

	// In the tVector class, we have a push_back class that will take a Value...
	// ... and as long as the size of the array is less than the array capacity...
	// ... we will add that into the array.
	bottomlessInt.push_back(5);
	bottomlessInt.push_back(11);
	bottomlessInt.push_back(13);
	bottomlessInt.push_back(66);
	bottomlessInt.push_back(1); // In this instance, we will have 5 Values.

	// Next, we will make two new integers which we will call number and capacity, ...
	// ... and set them equal to the vector bottomlessInt's size and capacity respectivley.
	int number = bottomlessInt.size();
	int storage = bottomlessInt.capacity();

	// Similar to a static array, we would have a for loop and then have it iterate...
	// ... through each push back as long as we have enough space/memory.
	for (int i = 0; i < bottomlessInt.size(); ++i)
	{
		std::cout << bottomlessInt[i] << std::endl;
	}

	std::cout << std::endl;

	// Using the tVector to make my array.
	tVector<int> myFries;

	myFries.push_back(1);
	myFries.push_back(18);
	myFries.push_back(22);
	myFries.push_back(55555);
	myFries.push_back(2);
	myFries.push_back(3);
	myFries.push_back(50);
	myFries.push_back(99);
	myFries.push_back(123);
	myFries.push_back(22);
	myFries.push_back(250); // Total number of elements = 11

	// So what Terry told me to keep as a note later, if i want make this...
	// ... a little bit easier and instead of having all these push backs, ...
	// ... In the constructer in the tVector, have an array which will store...
	// ... the values and then also take in the size. If I have more experience...
	// ... in this, try to do it.
	int tVectorSize = myFries.size();
	int tVectorCapacity = myFries.capacity();

	for (int i = 0; i < myFries.size(); i++) {
		std::cout << myFries.at(i) << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Size = " << myFries.size() << std::endl;
	std::cout << "Capacity = " << myFries.capacity() << std::endl;
	/*
	// In order to make an array using the tVector class, we would have to make...
	// ... a Vector that would be able to use a type (int, float, etc) and in this...
	// ... instance, we will call it BottomlessInt.
	std::vector<int> bottomlessInt;

	// In the tVector class, we have a push_back class that will take a Value...
	// ... and as long as the size of the array is less than the array capacity...
	// ... we will add that into the array.
	bottomlessInt.push_back(5);
	bottomlessInt.push_back(11);
	bottomlessInt.push_back(13);
	bottomlessInt.push_back(66);
	bottomlessInt.push_back(1); // In this instance, we will have 5 Values.

	// Next, we will make two new integers which we will call number and capacity, ...
	// ... and set them equal to the vector bottomlessInt's size and capacity respectivley.
	int number = bottomlessInt.size();
	int storage = bottomlessInt.capacity();

	// Similar to a static array, we would have a for loop and then have it iterate...
	// ... through each push back as long as we have enough space/memory.
	for (int i = 0; i < bottomlessInt.size(); ++i)
	{
		std::cout << bottomlessInt[i] << std::endl;
	}

	std::cout << std::endl;

	// Using the tVector to make my array.
	tVector<int> myFries;

	myFries.push_back(1);
	myFries.push_back(18);
	myFries.push_back(22);
	myFries.push_back(55555);
	myFries.push_back(2);
	myFries.push_back(3);
	myFries.push_back(50);
	myFries.push_back(99);
	myFries.push_back(123);
	myFries.push_back(22);
	myFries.push_back(250); // Total number of elements = 11

	// So what Terry told me to keep as a note later, if i want make this...
	// ... a little bit easier and instead of having all these push backs, ...
	// ... In the constructer in the tVector, have an array which will store...
	// ... the values and then also take in the size. If I have more experience...
	// ... in this, try to do it.
	int tVectorSize = myFries.size();
	int tVectorCapacity = myFries.capacity();

	for (int i = 0; i < myFries.size(); i++) {
		std::cout << myFries.at(i) << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Size = " << myFries.size() << std::endl;
	std::cout << "Capacity = " << myFries.capacity() << std::endl;
	*/

	/*
	// ***---Stacks Exercise---*** //
	tStack<int> bottomlessStackObject;

	bottomlessStackObject.push(22);
	bottomlessStackObject.push(5);

	std::cout << "Size: " << bottomlessStackObject.size() << std::endl;
	std::cout << "Top: " << bottomlessStackObject.top();
	std::cout << std::endl;

	bottomlessStackObject.pop();

	std::cout << std::endl;
	std::cout << "Size: " << bottomlessStackObject.size() << std::endl;
	std::cout << "Top: " << bottomlessStackObject.top();

	const tStack<int> constBottomlessStackObject;
	printTop(constBottomlessStackObject);
	*/
	
	/*
	// ***---Queue Exercise---*** //
	tQueue<int> queueObject;

	queueObject.push(10);
	queueObject.push(454);
	queueObject.push(22);

	std::cout << '\n' << "Front: " << queueObject.front() << std::endl;
	std::cout << "Back: " << queueObject.back() << std::endl;
	
	std::cout << std::endl;
	queueObject.pop();

	std::cout << '\n' << "Front: " << queueObject.front() << std::endl;
	std::cout << "Back: " << queueObject.back() << std::endl;

	std::cout << "Size: " << queueObject.size();

	std::cout << std::endl;
	tQueue<int>(10, 22);
	*/

	/*InitWindow(screenWidth, screenHeight, "Queues");
	SetTargetFPS(60);

	player playerObject;
	playerObject.position = { 100, 100 };
	playerObject.speed = 18;

	while (!WindowShouldClose()) {

		playerObject.update(GetFrameTime());

		BeginDrawing();

		ClearBackground(RAYWHITE);

		playerObject.draw();

		EndDrawing();
	}*/
}