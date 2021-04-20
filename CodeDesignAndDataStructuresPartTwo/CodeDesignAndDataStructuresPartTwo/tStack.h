#include "tVector.h"
#pragma once

template <typename T>
class tStack
{
	tVector<T> vec;                     // contains the data for a stack

public:
	tStack();                           // initializes the stack's default values

	void push(const T& value);          // adds an element to the top of the Stack
	void pop();                         // drops the top-most element of the Stack

	T& top();                           // returns the top-most element at the given element

	size_t size() const;                // returns current number of elements

	const T& top() const;				// Returns the top-most element at the given element and...
										// ... makes it constant.
};

template<typename T>
inline tStack<T>::tStack()
{
}

template<typename T>
inline void tStack<T>::push(const T & value)
{
	// When we input a Value, that will get added onto the top of the stack...
	// ... in the array, which would also then increase the size of the stack too.
	vec.push_back(value);
}

template<typename T>
inline void tStack<T>::pop()
{
	vec.pop_back();
}

template<typename T>
inline T & tStack<T>::top()
{
	return vec.at(vec.size() - 1);
}

template<typename T>
inline size_t tStack<T>::size() const
{
	return vec.size();
}

template<typename T>
inline const T & tStack<T>::top() const
{
	return vec.size() + 1;
}
