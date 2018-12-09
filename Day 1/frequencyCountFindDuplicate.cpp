/*************************************************************
Advent of Code:
Day 1
Challenge 1
Take an input file where each line is a positive or negative 
integer and compute the net sum at each line to determine the 
net frequency. The goal is to find the first frequency that 
appears twice. The program will keep loopig through the same 
input file (with each iteration, the previous frequency will be 
carried over to begin the next iteration) until a duplicate 
value is found. This will be done by tracking previous frequencies
in an unordered set.

Note: this program only works if a duplicate does occur, if the 
input does not produce a duplicate, the while loop will not end.
*************************************************************/

#include <fstream>
#include <iostream>
#include <string>
#include <unordered_set>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::unordered_set;

int convert(std::string);

int main() {

	bool duplicateFound = false;
	int sum = 0;
	unordered_set<int> alreadySeen; //used to track already seen sums
	alreadySeen.insert(0);

	while (!duplicateFound) {


		//get input file
		ifstream inputFile;
		inputFile.open("input.txt"); 

		//if input file was read without errors
		if (inputFile) {

			string number;

			while (inputFile >> number) {
				if (number.size() > 0) {
					int numericValue = convert(number);
					sum += numericValue; //add each value to sum
					if (alreadySeen.count(sum) != 0) {
						cout << "First value seen twice: " << sum << endl;
						duplicateFound = true;
						break;
					}
					alreadySeen.insert(sum);
				}
			}
		}
		//error when reading file.
		else {
			cout << "Error reading file." << endl;
		}
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