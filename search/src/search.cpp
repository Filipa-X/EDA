#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#include "search/search.hpp"
#include "search/utils.hpp"
using namespace std;

int busquedaSecuencial(string* array_words, const string& key, int n) {
    int count = 0;
    for(int i = 0; i < n; i++) { 
        if(array_words[i] == key) {
            count++;
        }
    }
    return count;
}

int busquedaBinaria(string* words, int i, int j, const string& key) {
     if(i <= j) {
        int k = (i+j) / 2;
        if(key == words[k]) {
            return k;
        }
        if (key < words[k]) {
            return busquedaBinaria(words, i, k-1, key);
        } else {
            return busquedaBinaria(words, k+1, j, key);
        }
     }
    return -1;
}






