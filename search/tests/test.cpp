#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include "search/search.hpp"

int main(int argc, char* argv[]) {

    string archivoDiccionario = argv[1];

    vector<string> keys = readFile("Nc.txt");
    vector<string> words = readFile(archivoDiccionario);

    for (const auto& palabra : keys) {
        cout << palabra << endl;
    }

    return 0;
}