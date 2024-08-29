#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#include "search/search.hpp"
#include "search/utils.hpp"

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
    for(int i = 0; i < array_words.size(); i++) { 
        if(array_words[i] == key) {
            count++;
        }
    }
    return count;
}








