/*************************************************************
Advent of Code:
Day 2
Challenge 2

Input is a a text file where each line is a string of lowercase
letters (all of the same length). The goal is to find the two
strings in the file that differ by only one character. Then 
the code prints either of the two strings omitting the mismatching
character.
*************************************************************/

#include <fstream>
#include <iostream>
#include <string> 
#include <vector>

using std::ifstream;
using std::string;
using std::vector;
using std::cout;
using std::endl;

bool stringCompare(string, string);

int main() {

	//get input file
	ifstream inputFile;
	inputFile.open("input.txt");

	if (!inputFile) {
		cout << "Error reading file" << endl;
		exit(0);
	}

	vector<string> stringVector; //strings from file will be stored in this 

	//add each line to the vector
	string line;
	while (inputFile >> line) {
		stringVector.push_back(line);
	}

	//placeholders
	string s1;
	string s2;

	//for each string, compare it to every other string
	for (int i = 0; i < stringVector.size(); i++) {
		bool found = false;
		for (int j = 0; j < stringVector.size(); j++) {
			if (i == j) continue;
			s1 = stringVector.at(i);
			s2 = stringVector.at(j);
			if (stringCompare(s1, s2)) {
				found = true;
				break;
			}
		}
		if (found) break;
	}

	//print out one of the result strings, omitting the mismatching character
	for (int i = 0; i < s1.size(); i++) {
		if (s1.at(i) == s2.at(i)) cout << s1.at(i);
	}
	cout << endl;

}

/*********************************************************
Function that takes two strings, and returns true if they
differe by only one character, false otherwise
*********************************************************/
bool stringCompare(string s1, string s2) {
	int mismatches = 0;
	for (int i = 0; i < s1.size(); i++) {
		if (s1.at(i) != s2.at(i)) mismatches++;
	}
	return mismatches == 1;
}