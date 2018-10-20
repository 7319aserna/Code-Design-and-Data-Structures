#include "gameObject.h"
#include <iostream>
#include "raylib/raylib.h"

// Function Templates
// There may be some situations where we have a function... 
// ... defined which works well for one particular data-type but would...
// ... work equally well for others with little modification. For example:
template<typename t>
t add(t v1, t v2) {
	return v1 + v2;
}

// In addition we can specify multiple input types and even...
// ... a seperate output data-type.
template<typename t1, typename t2, typename t3>
t1 sub(t2 v1, t3 v2) {
	return v1 - v2;
}

// You can even specify an actual specific data-type as follows
template<typename t1, typename t2, int v2>
t1 sub2(t2 v1) {
	return v1 = v2;
}

// Closed Exercises
// Exercise 1 - Min and Max
// Goal: Min function takes in two parameters and returns the smaller of the two
template<typename t>
t min(t v1, t v2) {
	if (v1 < v2) {
		return v1;
	}
	else {
		return v2;
	}
}

// Goal: Max function does the opposite of the Min function, and returns the larger of two values
template<typename t1, typename t2, typename t3>
t1 max(t2 v1, t3 v2) {
	if (v1 > v2) {
		return v1;
	}
	else {
		return v2;
	}
}

int main() {
	std::cout << add(2, 4) << std::endl;						// template<typename t>
	std::cout << sub<float>(2.5, 4) << std::endl;				// template<typename t1, typename t2, typename t3>
	std::cout << sub2<float, float, 12>(15.5f) << std::endl;	// template<typename t1, typename t2, int v2>

	system("CLS");

// Closed Exercises
// Exercise 1 - Min and Max
// Goal: Min function takes in two parameters and returns the smaller of the two
	// Min Functions
	std::cout << min(3, 4) << std::endl;	// 3
	std::cout << min(3, 3) << std::endl;	// 3
	std::cout << min(99, 0) << std::endl;	// 0

// Goal: Max function does the opposite of the Min function, and returns the larger of two values
	// Max Functions
	std::cout << max<int>(7, 10) << std::endl;	// 10
	std::cout << max<int>(5, 0) << std::endl;	// 5
	std::cout << max<int>(6, 6) << std::endl;	// 6

// Exercise 2 -	GameObject
	gameObject<ninja>ninjaObject;
	ninjaObject.enabled = true;
	ninjaObject.update(7.0f);
	ninjaObject.render();

	gameObject<soldier>soldierObject;
	soldierObject.enabled = true;
	soldierObject.update(7.0f);
	soldierObject.render();
}