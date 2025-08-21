#ifndef GROCERY_H// makes sure the header file is only used once
#define GROCERY_H// tells the compiler that GROCERY_H has been included

#include <iostream> //allows for input and output
#include <iomanip> //allows for manipulation of the data
#include <fstream> //allows for the use of files
#include <map> //allows for the use of a map
#include <string> // allows for the use of strings

using namespace std; // tells the compiler to invisibly include std as a preface

class Grocery {
public: // public classes
	bool openInputFile(ifstream&, const string&); // declares openInputFile as a boolean
	bool openOutputFile(ofstream&, const string&);// declares openOutputFile as a boolean
	map<string, int> readInputFile(ifstream&); // tells the program what to do with the map
	void writeOutputFile(ofstream&, const map<string, int>&); //tells the program how to output the file
	void displayMenu(); //displays the menu
	void findItem(const map<string, int>&); // declares findItem and how to do it
	void listItems(const map<string, int>&);// declares listItems and how to do it
	void printHistogram(const map<string, int>&); //declares printHistogram and how to do it.
};
#endif //ends the ifndef block

