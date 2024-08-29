#ifndef SORT_UTILS_HPP
#define SORT_UTILS_HPP

namespace sort{
	float* createArray(int n);
	float* createRandomArray(int n);
	float* createRandomIntArray(int n, int minVal = 0, int maxVal = 100);
	void deleteArray(char* A);
	void swap(char* A, int i, int j);
	int getRandomInt(int min, int max);
}

#endif