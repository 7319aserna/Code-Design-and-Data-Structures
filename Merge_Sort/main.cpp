#include <iostream>

void merge(int * arr, size_t p, size_t q, size_t r) {
	int leftEnd = q - p + 1;							
	int rightEnd = r - q;								

	int * L = new int [leftEnd];
	int * R = new int [rightEnd];

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

void mergeSort(int * arr, size_t p, size_t r);

int main() {
	int intArr[9] = { 22, 18, 73, 50, 75, 1, 40, 99, 5 };
	std::cout << "Unsorted List: " << std::endl;
	for (int i = 0; i < 9; i++) {
		std::cout << intArr[i] << " ";
	}
	mergeSort(intArr, 0, 8);

	std::cout << '\n' << "Sorted List: " << std::endl;
	for (int i = 0; i < 9; i++) {
		std::cout << intArr[i] << " ";
	}

	return 0;
	// Would I have to delete the new array ints in the main or not?
}

void mergeSort(int * arr, size_t p, size_t r) {
	if (p < r) {
		int q = (p + r) / 2;		
		mergeSort(arr, p, q);		
		mergeSort(arr, q + 1, r);	
		merge(arr, p, q, r);		
	}
}