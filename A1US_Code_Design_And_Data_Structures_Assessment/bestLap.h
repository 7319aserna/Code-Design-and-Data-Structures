#include <iostream>
#pragma once

class bestLap {
public:
	bestLap();
	~bestLap();
	void merge(float * arr, size_t p, size_t q, size_t r);
	void mergeSort(float * arr, size_t p, size_t r);
};

