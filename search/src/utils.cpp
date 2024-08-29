#include <iostream>
#include <ctime>
#include <cstdlib>
#include <ctime>
#include <cmath>

#include "search/utils.hpp"

namespace sort{

    void swap(char* A, int i, int j){
        float aux = A[i];
        A[i] = A[j];
        A[j] = aux;
    }

    int getRandomInt(int min, int max){
        float a = rand() / static_cast<float>(RAND_MAX);
        return static_cast<int>(a * (max - min) + min + 0.5);
    }
    void deleteArray(char* A){
		delete[] A;
	}
}