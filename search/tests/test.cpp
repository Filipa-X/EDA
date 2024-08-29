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

    int n = 200000;

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
	string* words = new string[n]; //cambiar segun el test que se quiera realizar

	int j = 0;
	while (getline (wordsReadFile, wordsText)) {
		words[j] = wordsText;
		j++;
	}

    keysReadFile.close();
    wordsReadFile.close();

    long totalElapsedTimeSecuential = 0;
    long totalElapsedTimeBinarie = 0;
    long PalabrasSecuencial = 0;
    long PalabrasBinomial = 0;

    for(int j = 0; j < 999999; j++) { //999.999 es fijo porque keys son 1.000.000

        auto start1 = chrono :: high_resolution_clock :: now();
        int count = busquedaSecuencial(words, keys[j], n);
        auto end1 = chrono :: high_resolution_clock :: now();

        long elapsed1 = getElapsedTime(start1, end1);

        totalElapsedTimeSecuential += elapsed1;

        if(count != 0){
            PalabrasSecuencial++;
    }
    }
/*******
    quickSort(words, n);

    for(int j = 0; j < 999999; j++) { //999.999 es fijo porque keys son 1.000.000
        auto start2 = chrono :: high_resolution_clock :: now();
        int count = busquedaBinaria(words, 0, n - 1, keys[j]);
        auto end2 = chrono :: high_resolution_clock :: now();
        long elapsed2 = getElapsedTime(start2, end2);
        totalElapsedTimeBinarie += elapsed2;

        if(count != -1){
            PalabrasBinomial++;
    }
    }
******/    


    totalElapsedTimeSecuential = totalElapsedTimeSecuential/1000000;
    totalElapsedTimeBinarie = totalElapsedTimeBinarie/1000000;
    cout << "El tiempo promedio de la busqueda Secuencial fue de: " << totalElapsedTimeSecuential << endl;
    cout << "La cantidad de elementos encontrados con la busqueda secuencial fue de: " << PalabrasSecuencial << endl;
    //cout << "El tiempo promedio de la busqueda Binaria fue de: " << totalElapsedTimeBinarie << endl;
    //cout << "La cantidad de elementos encontrados con la busqueda Binaria fue de: " << PalabrasBinomial << endl;


    return 0;
}