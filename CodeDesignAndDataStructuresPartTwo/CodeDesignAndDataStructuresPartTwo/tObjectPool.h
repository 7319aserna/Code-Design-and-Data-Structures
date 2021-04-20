#include "raylib.h"
#include "spriteObjectPool.h"
#pragma once

template<typename T>
class tObjectPool
{
	T* pool;                            // all objects stored in the pool
	bool* free;                         // indicates whether an object is available

public:
	tObjectPool();                       // default initializes the object pool
	tObjectPool(size_t initialCapacity); // initializes the pool to have a set number of objects

	~tObjectPool();                      // destroys all objects

	T* retrieve();                      // returns a pointer to an object that will be used (returns null if none available)
	void recycle(T* obj);               // accepts a pointer that can be used in the future

	size_t capacity();                  // returns the total number of objects that this pool can provide          
	
	int objectPoolCapacity;

	int objectsRemainingInPool;

	spriteObjectPool sOPObject;
};

template<typename T>
tObjectPool<T>::tObjectPool() {
}

template<typename T>
inline tObjectPool<T>::tObjectPool(size_t initialCapacity) {
	pool = new T[initialCapacity];
	free = new bool[initialCapacity];

	for (int i = 0; i < initialCapacity; i++) {
		free[i] = true;
	}

	objectPoolCapacity = initialCapacity;
	objectsRemainingInPool = initialCapacity;
}

template<typename T>
inline tObjectPool<T>::~tObjectPool() {
	delete pool;
	delete free;
}

template<typename T>
inline T * tObjectPool<T>::retrieve() {
	for (int i = 0; i < objectPoolCapacity; i++) {
		if (free[i] == true) {
			free[i] = false;

			sOPObject.draw();
			sOPObject.update(GetFrameTime());

			objectsRemainingInPool--;

			DrawText(FormatText("%01i", &pool[i]), 250, 100, 25, BLACK);

			return &pool[i];
		}
	}
	return NULL;
}

template<typename T>
inline void tObjectPool<T>::recycle(T * obj) {
	for (int i = 0; i < objectPoolCapacity; i++) {
		if (&pool[i] == obj) {
			free[i] = true;

			objectsRemainingInPool++;

			return;
		}
	}
}

template<typename T>
inline size_t tObjectPool<T>::capacity() {
	return size_t(objectsRemainingInPool);
}