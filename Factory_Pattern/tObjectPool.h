#pragma once

template<typename T>
class tObjectPool {
	ObjectPool();						// Default initializes the Object Pool

	ObjectPool(size_t initialCapacity);	// Initializes the pool to have a ...
										// set number of objects

	~ObjectPool();						// Destroys all objects

	T* pool;							// All objects stored in the pool

	bool* free;							// Indicates whether an object is ...
										// avaliable
	
	T* retrieve();						// Returns a pointer to an object ...
										// that will be used (returns ...
										// null if none avaliable)

	void recycle(T* obj);				// accepts a pointer that can be ...
										// used in the future

	size_t capacity();					// returns the total number of ...
										// objects that this pool can provide
};

template<typename T>
inline tObjectPool<T>::ObjectPool() {
}

template<typename T>
inline tObjectPool<T>::ObjectPool(size_t initialCapacity) {
	// Initializes the pool to have a set number of objects
	// I believe that is the limit, so only have a set number if objects
	initialCapacity = pool;
}

template<typename T>
inline tObjectPool<T>::~ObjectPool()
{
}

template<typename T>
inline T * tObjectPool<T>::retrieve()
{
	if (free == true) {
		retrieve pool;
	}
	else {
		return nullptr;
	}
}

template<typename T>
inline void tObjectPool<T>::recycle(T * obj)
{
}

template<typename T>
inline size_t tObjectPool<T>::capacity()
{
	return size_t(pool);
}
