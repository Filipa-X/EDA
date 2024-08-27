#pragma once
#include <vector>
#include <string>
using namespace std;

int busquedaSecuencial(const vector<string>& array_words, const string& key);
int busquedaBinaria(const vector<string>& array_words, const string& key);
vector<string> readFile(const string& fileName);