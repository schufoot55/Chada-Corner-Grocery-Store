#include "grocery.h"

bool Grocery::openInputFile(ifstream& inputFile, const string& filename) {
	inputFile.open(filename);
	return inputFile.is_open();
} //whether or not the input file is open

bool Grocery::openOutputFile(ofstream& outputFile, const string& filename) {
	outputFile.open(filename);
	return outputFile.is_open();
}// output file open or not

map<string, int> Grocery::readInputFile(ifstream& inputFile) {
	map<string, int> groceryList;
	string item;
	while (inputFile >> item) {
		groceryList[item]++;
	}
	return groceryList; //reads and stores how many times the requested item is listed
}

void Grocery::writeOutputFile(ofstream& outputFile, const map<string, int>& grocList) {
	for (const auto& pair : grocList) {
		outputFile << pair.first << " " << pair.second << endl; //writes the contents of the list to an output file
	}
}

void Grocery::displayMenu() {
	cout << "===== Grocery Store Menu =====" << endl;
	cout << "1. Find an item" << endl;
	cout << "2. List all items and quantities" << endl;
	cout << "3. Print histogram" << endl;
	cout << "4. Exit" << endl;
	cout << "Please enter your choice: ";
}// displays the menu, prompting the user for inputs

void Grocery::findItem(const map<string, int>& grocList) {
	string searchItem;
	int itemCount = 0; //prompts the user for an item to search for

	cout << endl << "Enter the item you want to find: ";
	cin >> searchItem; //takes the input of item to search for

	if (!searchItem.empty()) {
		searchItem[0] = toupper(searchItem[0]); // translates lowercase to upper case ie. apples to Apples
	}

	if (grocList.count(searchItem)) {
		itemCount = grocList.at(searchItem);
		cout << searchItem << " appeared " << itemCount << " time(s)." << endl; // outputs how many times the item is listed
	}
	else {
		cout << searchItem << " was not found." << endl; // output if the item is not in the list
	}
}

void Grocery::printHistogram(const map<string, int>& grocList) {
	cout << endl;
	cout << "----------------------------------- " << endl;
	cout << "	Item Frequency Histogram		 " << endl;
	cout << "----------------------------------- " << endl; // prints the header for the histogram output

	for (const auto& pair : grocList) {
		cout << setw(14) << left << pair.first << " ";
		for (int i = 0; i < pair.second; ++i) {
			cout << "*"; 
		} //prints the actual histogram
		cout << endl;
	}
}

void Grocery::listItems(const map<string, int>& items) {
    cout << left << setw(20) << "Item" << "Count" << endl;
    cout << string(26, '-') << endl;
    for (const auto& pair : items) {
        cout << left << setw(20) << pair.first << pair.second << endl;
    }// prints the list items and their frequency on the list
}