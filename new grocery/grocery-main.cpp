/*
* Douglas Schulte
* Project Three Grocery Store
* Date: 2025-08-14
* This program will do the following:
* open the required file, output a backup of the data, organized
* print how many times a requested item is in the list with numbers and a histogram 
*/

#include "grocery.h" //tells the program to use grocery.h
#include <limits> //tells the program to include the limits library for numbers

using namespace std; // tells the program to use this as a preface for strings and int and so on

int getInteger(int, int, string); // declares getInteger with three arguments of int, int and string
string printStars(int); //declares function that will use one int and show a string
void pause(string = "Press enter to continue "); //declares the function pause that returns nothing and can accept a string
void cls(); // clears the console screen


const string INPUT_FILE = "CS210_Project_Three_Input_File.txt"; //uses the file in " " as input file
const string OUTPUT_FILE = "frequency.dat"; //creates a .dat file as a backup once the program is run


int main() {

	Grocery myGrocery; // creates an object myGrocery from the class Grocery to be used later
	 
	ifstream inputFile; //allows for input files to be used
	ofstream outputFile;// allows for an output file to be created
	string item = ""; //creates and initializes an empty string
	int itemsAdded = 0; //declares itemsAdded as an int and initializes at 0
	int itemsUpdated = 0;//declares itemsUpdated as an int and initializes at 0
	map<string, int> grocList;// declares grocList as the map for the program
	int selection = 0;//declares selection as an int and initializes at 0
	bool notDone = true;// declares notDone as a boolean and initializes at true

	if (myGrocery.openInputFile(inputFile, INPUT_FILE)) {
		cout << "Input File Opened " << endl; //what the program will do if the input file is open
	}
	else {
		cerr << "Error in file " << endl;
		return EXIT_FAILURE;
	} //what the program will do if it does not or is not open

	if (myGrocery.openOutputFile(outputFile, OUTPUT_FILE)) {
		cout << "Output File Opened " << endl;
	}//what will be done if the output file is open
	else {
		cerr << "Error in file " << endl;
		return EXIT_FAILURE;
	}// what will be done if the output file is not open

	pause("Press enter to read the file ");// stops the program and tells the user what to do to continue the process
	cls(); //clears the console screen
	grocList = myGrocery.readInputFile(inputFile); // tells the program to read the input file and count the number of times each item is in the list
	myGrocery.writeOutputFile(outputFile, grocList);// tells the program to output the file with each item listed with the number of times it shows up next to it

	do { //shows the user the menu
		myGrocery.displayMenu();
		selection = getInteger(1, 4, "Please select menu option ");//takes the user's input of the menu

		switch (selection) {
		case 1:
			myGrocery.findItem(grocList);
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			pause();
			cls();
			break;// tells the program what to do for the first option
		case 2:
			myGrocery.listItems(grocList);
			break;// tells the program what to do for the second option
		case 3:
			myGrocery.printHistogram(grocList);
			break;// tells the program what to do for the third option
		case 4:
			notDone = false;
			break;// tells the program what to do for the fourth option
		default:
			cout << "Opps we should never get here ...." << endl;
			break;// acts as a safety net for the code so it doesn't throw an error
		}
	} while (notDone);

	inputFile.close(); //closes the input file

	return 0;
} //main

int getInteger(int lowest, int highest, string prompt)
{
	int number = 0; //initializes the int at 0
	bool needNumber = true; // initializes the boolean as true

	prompt = prompt + to_string(lowest) + " and " + to_string(highest) + " ";// limits the valid input ranges
	do {
		cout << prompt;
		cin >> number;
		//cout << "Peek " << (int)cin.peek() << "EOF" << EOF << endl;
		if (cin.fail()) {
			cout << "Must be a number " << endl;// makes sure the user inputs a number not letters or words or special characters
			cin.clear(); 
			cin.ignore(std::numeric_limits<std::streamsize>::max(), char(10));//clears the input buffer
			continue;
		}
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		needNumber = ((number < lowest) || (number > highest)); //check if in bounds
		if (needNumber) {
			cout << "\a Invalid number - please enter" << endl; //tells the user that the number they input is not valid
		}
	} while (needNumber);

	return number;
} //getInteger




string printStars(int numStars)
{
	return string(numStars, '*'); //prints the stars to seperate lines in the output
}

void pause(string prompt)
{
	cout << prompt;
	cin.get();
}

void cls()
{
	std::cout << "\x1B[2J\x1B[H";  // ANSI escape codes to clear screen and move cursor to top-left
	std::cout.flush();
}

void someFunction() {
    bool errorCondition = false; // Declare and initialize errorCondition
    if (errorCondition) {
        return; // Correct: exits the function
    }
}
