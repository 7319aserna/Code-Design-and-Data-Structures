#include <iostream>
#include "tLinkedList.h"

int main() {
	tForwardList<int> tFLObject;
	tFLObject.push_front(10);
	tFLObject.push_front(22);
	tFLObject.push_front(42);
	tFLObject.push_front(33);
	tFLObject.push_front(56);
	
	tFLObject.display();
	
	tFLObject.pop_front();

	tFLObject.display();

	std::cout << tFLObject.front() << std::endl;
	return 0;
}