#pragma once
#include "tVector.h"
#include <queue>

template <typename T>
class tQueue
{
	tVector<T> vec;                       // contains the data for a queue

public:
	tQueue();                             // default initializes the queue
	tQueue(size_t count, const T& value); // constructs a queue with the given number of elements 
										  // each element is initialized by copying the given value

	void push(const T& value);            // adds an element to the top of the Queue
	void pop();                           // drops the top-most element of the Queue

	T& front();                           // returns the front-most element
	T& back();                            // returns the back-most element

	size_t size() const;                  // returns current number of elements

	const T& front() const;
	const T& back() const;

	bool empty() const;
};

template<typename T>
inline tQueue<T>::tQueue()
{
}

template<typename T>
inline tQueue<T>::tQueue(size_t count, const T & value)
{
	// For the count, it is the amount of the value, so if the count...
	// ... for example is 50 and the value is 22, there will be 50 spaces(count) that...
	// ... would be filled by 22(value) in each space.
	for (int i = 0; i < count; i++) {
		vec.push_back(value);
		std::cout << value << std::endl;
	}
}

template<typename T>
inline void tQueue<T>::push(const T & value)
{
	// Adds a value to the back of the queue
	vec.push_back(value);
	std::cout << value << std::endl;
}

template<typename T>
inline void tQueue<T>::pop()
{
	// Removes a value from the beginning of the queue
	// You would have to overwrite all of the values and move them.
	// Note: Maybe make a for loop and then have a temp index...
	for (int i = 0; i < size() - 1; i++) {
		vec.at(i) = vec.at(i + 1);
		std::cout << vec.at(i + 1) << std::endl;
	}
}

template<typename T>
inline T & tQueue<T>::front()
{
	// Return the first element
	return vec.at(0);
}

template<typename T>
inline T & tQueue<T>::back()
{
	// Return the last element
	return vec.at(vec.size() - 1);
}

template<typename T>
inline size_t tQueue<T>::size() const
{
	return vec.size();
}

template<typename T>
inline const T & tQueue<T>::front() const
{
	// Whatever value is at the front, it will be constant and would no longer...
	// ... be able to change
	return vec.at(0);
}

template<typename T>
inline const T & tQueue<T>::back() const
{
	return vec.at(vec.size() - 1);
}

template<typename T>
inline bool tQueue<T>::empty() const
{
	if (size() == 0) {
		return false;
	}
	else
	{
		return true;
	}
}
