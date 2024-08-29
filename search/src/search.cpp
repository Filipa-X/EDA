#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#include "search/search.hpp"
#include "search/utils.hpp"
using namespace std;

int busquedaSecuencial(string* array_words, const string& key) {
    int count = 0;
    for(int i = 0; i < 10000; i++) { 
        if(array_words[i] == key) {
            count++;
        }
    }
    return count;
}








