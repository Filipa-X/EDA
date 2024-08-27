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

int busquedaSecuencial(const vector<string> array, const string& x) {
    int count = 0;
    return count;
}

int busquedaBinaria(const vector<string>& array, const string& x) {
    return 5;
}





