#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include "search/search.hpp"

int main(int argc, char* argv[]) {

    string archivoDiccionario = argv[1];

    vector<string> keys = readFile("Nc.txt");
    vector<string> words = readFile(archivoDiccionario);

    for(int j = 0; j < 999999; j++) { //999.999 es fijo porque keys son 1.000.000
        int count = busquedaSecuencial(words, keys[j]);
    }

    return 0;
}