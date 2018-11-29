#include "bestLap.h"
#include <iostream>

bestLap::bestLap() {
}

bestLap::~bestLap() {
}

void bestLap::merge(float * arr, size_t p, size_t q, size_t r) {
	int leftEnd = q - p + 1;
	int rightEnd = r - q;

	float * L = new float[leftEnd];
	float * R = new float[rightEnd];

	for (int i = 0; i < leftEnd; i++) {
		L[i] = arr[p + i];
	}
	for (int j = 0; j < rightEnd; j++) {
		R[j] = arr[q + j + 1];
	}

	int i = 0;
	int j = 0;

	for (int k = p; k <= r; k++) {
		if ((j >= rightEnd) || (i < leftEnd && L[i] <= R[j])) {
			arr[k] = L[i];
			i = i++;
		}
		else {
			arr[k] = R[j];
			j = j + 1;
		}
	}
	delete[] L;
	delete[] R;
}

void bestLap::mergeSort(float * arr, size_t p, size_t r) {
	if (p < r) {
		float q = (p + r) / 2;
		mergeSort(arr, p, q);
		mergeSort(arr, q + 1, r);
		merge(arr, p, q, r);
	}
}
