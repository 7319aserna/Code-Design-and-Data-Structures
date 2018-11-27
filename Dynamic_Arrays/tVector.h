#include "raylib/raylib.h"
#pragma once

template <typename T>
class tVector
{
	const static size_t GROWTH_FACTOR = 2;

	T *arr;                             // pointer to underlying array
	size_t arrSize;                     // stores the number of elements currently used
	size_t arrCapacity;                 // stores the capacity of the underlying array

public:
	tVector();                          // initializes the vector's default values
	~tVector();                         // destroys the underlying array

	T *data();                          // returns a pointer to the underlying array

	void reserve(size_t newCapacity);   // resizes the vector to at least this many elements

	void push_back(const T &value);     // adds an element to the end of the vector
	void pop_back();                    // drops the last element of the vector

	T &at(size_t index);                // returns the element at the given element

	size_t size() const;                // returns current number of elements
	size_t capacity() const;            // returns maximum number of elements we can store
};

template<typename T>
inline tVector<T>::tVector()
{
	arr = new T[20];
	arrSize = 0;
	arrCapacity = 20;
}

template<typename T>
inline tVector<T>::~tVector()
{
	delete[] arr;
}

template<typename T>
inline T * tVector<T>::data()
{
	return arr;
}

template<typename T>
inline void tVector<T>::reserve(size_t newCapacity)
{
	// In this case, on the push_back function below, if the Array Size is bigger than the Array Capacity, ...
	// ... the Array Capacity will multiply by the Growth Factor which is 2. Now in the reserve function...
	// ... we haven't changed the Array just yet, which is what we have to do here.

	// In the reserve with a little bit of help, we cannot use the old array to just make it bigger... 
	// ... the reason this is because if we make that original array a bigger one, it would overwrite the...
	// ... previous numbers that we had. So what we have to do is make a Temporary array, and with the Original...
	// ... array, we would input those old numbers into the Temp array, then we would make the Temp array the...
	// ... original array.

	T *tempArr;
	tempArr = new T[newCapacity];

	for (int i = 0; i < arrCapacity; i++) {
		tempArr[i] = arr[i];
	}

	delete[] arr;

	arr = tempArr;

	arrCapacity = newCapacity;
}

template<typename T>
inline void tVector<T>::push_back(const T & value)
{	
	if (arrSize >= arrCapacity) {
		// This only changes the variable for the Array Capacity, not the Array (arr = new T[10]) itself.
		reserve(arrCapacity * GROWTH_FACTOR);
	}

	arr[arrSize] = value;
	arrSize++;
}

template<typename T>
inline void tVector<T>::pop_back()
{
	arrSize--;
}

template<typename T>
inline T & tVector<T>::at(size_t index)
{
	// In the Array, whatever is chosen as the index, the At function would go through the Array and...
	// ... check to see if that index matches the location whithin the Array and return the arr[index].

	return arr[index];
}

template<typename T>
inline size_t tVector<T>::size() const
{
	return size_t(arrSize);
}

template<typename T>
inline size_t tVector<T>::capacity() const
{
	return size_t(arrCapacity);
}