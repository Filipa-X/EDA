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
    int count = 0;
    vector<string> copy_array_words = array_words;
    quicksort(copy_array_words, 0, array_words.size());
    int low = 0;
    int high = copy_array_words.size(); 

    while(low <= high){
        int mitad = (low+high)/2;
        if(copy_array_words[mitad] == key){
            count++;
        }
        if(copy_array_words[mitad] > key){
            high = mitad;
            mitad = (low+high)/2;
        }
        if(copy_array_words[mitad] < key){
            low = mitad;
            mitad = (low+high)/2;
        }
    }
    return count;
}

void swap(string &a, string &b){
    string temp = a;
    a = b;
    b = temp;
}

int partition(vector<string> &arr, int low, int high){
    string pivot = arr[high];
    int i = low - 1;

    for(int j = low; j <= high - 1; j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}

void quicksort(vector<string> &arr, int low, int high){
    if (low < high){
        int pi = partition(arr, low, pi-1);
        quicksort(arr,low,pi-1);
        quicksort(arr,pi+1,high);
    }
}








