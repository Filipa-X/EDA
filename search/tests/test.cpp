#include <iostream>
#include <fstream>
#include <string>

#include "search/search.hpp"
#include "search/utils.hpp"/

using namespace std;

int main(int nargs, char** args){

	string myText;

	ifstream MyReadFile("D10000.txt");
	char words[10000];

	// Use a while loop together with the getline() function to read the file line by line
	int i = 0;
	while (getline (MyReadFile, myText)) {
	// Output the text from the file
		words[i] = myText;
		i++;
	}

	for(int i=0; i< 10000; i++){
		cout << words[i] << endl;
    }

	MyReadFile.close();

	return 0;
}
