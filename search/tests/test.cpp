#include "search/sort.hpp"
#include "search/utils.hpp"
#include "search/search.hpp"
#include <chrono>
#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
using namespace std;

long getElapsedTime(chrono :: time_point < chrono :: high_resolution_clock > t1,
		chrono :: time_point < chrono :: high_resolution_clock > t2) {
	auto int_ms = chrono :: duration_cast < chrono :: nanoseconds > ( t2 - t1);
	return static_cast<long>(int_ms.count());           
        }

int main(int argc, char* argv[]) {

    string archivoDiccionario = argv[1];

    string myText;

	// Read from the text file
	ifstream MyReadFile("Nc.txt");
	string keys[1000000];

	// Use a while loop together with the getline() function to read the file line by line
	int i = 0;
	while (getline (MyReadFile, myText)) {
	// Output the text from the file
		keys[i] = myText;
		i++;
	}
    cout << keys[0] << endl;
/******************
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


    vector<string> words_sort = words;
        int low = 0;
        int high = words_sort.size() - 1;
        quicksort(words_sort, low, high);
    int y = 0;
    for(int k = 0; k < keys.size() - 1; k++) {
        int x = busquedaBinaria(words, keys[k]);
        y += x;
        cout << "El elemento aparece " << x << " veces." << endl;

    }

    cout << y << endl;


    //double average = totalElapsedTime / 999999;
    //cout << "secuencial: " << average << endl;
*************************/
    return 0;
}