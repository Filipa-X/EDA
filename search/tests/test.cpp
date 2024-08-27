#include <iostream>
#include <vector>
#include <string>
#include <chrono>

using namespace std;

#include "search/search.hpp"

long getElapsedTime(chrono :: time_point < chrono :: high_resolution_clock > t1,
		chrono :: time_point < chrono :: high_resolution_clock > t2) {
	auto int_ms = chrono :: duration_cast < chrono :: nanoseconds > ( t2 - t1);
	return static_cast<long>(int_ms.count());           
        }

int main(int argc, char* argv[]) {

    string archivoDiccionario = argv[1];

    vector<string> keys = readFile("Nc.txt");
    vector<string> words = readFile(archivoDiccionario);

    long totalElapsedTime = 0;

    for(int j = 0; j < 999999; j++) { //999.999 es fijo porque keys son 1.000.000
        auto start = chrono :: high_resolution_clock :: now();
        int count = busquedaSecuencial(words, keys[j]);
        auto end = chrono :: high_resolution_clock :: now();

        long elapsed = getElapsedTime(start, end);
        totalElapsedTime += elapsed;
        cout << elapsed << endl;
    }

    double average = totalElapsedTime / 999999;
    cout << "secuencial: " << average << endl;

    return 0;
}