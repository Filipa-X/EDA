#include "search/sort.hpp"
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

    string keysText;

	ifstream keysReadFile("Nc.txt");
	string* keys = new string[1000000];

	int i = 0;
	while (getline (keysReadFile, keysText)) {
		keys[i] = keysText;
		i++;
	}

    string wordsText;

	ifstream wordsReadFile(archivoDiccionario);
	string* words = new string[10000]; //cambiar segun el test que se quiera realizar

	int j = 0;
	while (getline (wordsReadFile, wordsText)) {
		words[j] = wordsText;
		j++;
	}

    keysReadFile.close();
    wordsReadFile.close();

    long totalElapsedTime = 0;


    //for(int j = 0; j < 999999; j++) { //999.999 es fijo porque keys son 1.000.000
        cout << words[0] << endl;
        string* wordsCopy = words;
        auto start = chrono :: high_resolution_clock :: now();
        quickSort(wordsCopy, 0, 10000);
        auto end = chrono :: high_resolution_clock :: now();

        long elapsed = getElapsedTime(start, end);
        totalElapsedTime += elapsed;
        cout << words[0] << endl;
        cout << wordsCopy[0] << endl;
        cout << elapsed << endl;

    //}

/*************************

        string* words_sort = words;
        int low = 0;
        int high = 9999; //9999 hay que cambiarlo segun el test que se quiera hacer
        
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