/*************************************************************
Advent of Code:
Day 1
Challenge 1
Take an input file where each line is a positive or negative 
integer and compute the net sum.
*************************************************************/

#include <fstream>
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::ifstream;

int convert(std::string);

int main() {

	//get input file
	ifstream inputFile;
	inputFile.open("input.txt"); 

	//if input file was read without errors
	if (inputFile) {
		int sum = 0; //value to be returned
		string number;

		while (inputFile >> number) {
			if (number.size() > 0) {
				int numericValue = convert(number);
				sum += numericValue; //add each value to sum
			}
		}
		cout << sum << endl; //print result
	}
	//error when reading file.
	else {
		cout << "Error reading file." << endl;
	}

}

/*******************************************
helper function to convert a string to an
integer
*******************************************/
int convert(std::string number) {
	int result = 0; //value to be returned.
	int multiplier = 1; //will multiply 10x after each iteration for ones place, tens place, etc...
	for (int i = number.size() - 1; i >= 1; i--) {
		result += multiplier * (number.at(i) - '0'); //get value through ASCII char math
		multiplier *= 10;
	}
	if (number.at(0) == '-') result *= -1; //make negative if necessary
	return result;
}