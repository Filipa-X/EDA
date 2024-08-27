#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#include "search/search.hpp"

vector<string> readFile(const string& fileName) {
    vector<string> array;
    ifstream file(fileName);
    string line;

    while(getline(file, line)) {
        array.push_back(line);
    }
    file.close();
    return array;
}

int busquedaSecuencial(const vector<string>& array_words, const string& key) {
    int count = 0;
    for(int i = 0; i < 9999; i++) { //9.999 es solo para el archivo D10000
        if(array_words[i] == key) {
            count++;
        }
    }
    return count;
}

int busquedaBinaria(const vector<string>& array_words, const string& key) {
    return 5;
}





