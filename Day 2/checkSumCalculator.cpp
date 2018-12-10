/*************************************************************
Advent of Code:
Day 2
Challenge 1
Take an input file where each line is a string of lowercase
letters. The task is to count how many lines have exactly two 
of any character, and how many lines have exactly three of any
character, then calculate the product of those two values.
*************************************************************/

#include <fstream>
#include <iostream>
#include <string> 

using std::ifstream;
using std::string;
using std::cout;
using std::endl;

void resetCharFreq(int *);

int main() {

	//get input file
	ifstream inputFile;
	inputFile.open("input.txt");

	if (inputFile) {
		int *charFreq = new int[26]; //array to store character frequencies for each line
		
		//these two results will be incremented as we traverse the file and be multiplies
		//together to produce the final result.
		int twoCount = 0;
		int threeCount = 0;


		string line;
		while (inputFile >> line) {
			resetCharFreq(charFreq); //reset frequency array to all 0's (see function below)

			//increment frequency table at each letter
			for (int i = 0; i < line.size(); i++) {
				charFreq[line.at(i) - 'a']++;
			}

			//determine whether current line has exactly two or exactly three
			//of any character (if both, then it counts for both)
			bool twoFound = false;
			bool threeFound = false;
			for (int i = 0; i < 26; i++) {
				if (charFreq[i] == 2 && !twoFound) {
					twoCount++;
					twoFound = true;
				}
				if (charFreq[i] == 3 && !threeFound) {
					threeCount++;
					threeFound = true;
				}
			}
		}
		delete [] charFreq; //delete dynamically allocated array
		cout << twoCount << " * " << threeCount << " = " <<twoCount * threeCount << endl; //print result
	}
}

void resetCharFreq(int *charFreq) {
	for (int i  = 0; i < 26; i++) {
		charFreq[i] = 0;
	}
}