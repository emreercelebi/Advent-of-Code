/*************************************************************
Advent of Code:
Day 3
Challenge 1

Input is a a text file where each line is a string that represents
a rectangular section of a large fabric. Each line follows the same
format. 
Example line: #9 @ 25,877: 23x13
this line has an id of 9, and specifies a rectangle 25 inches from 
the left edge, 877 inches from the top edge, 23 inches wide, and
13 inches tall.

There is one entry that does not overlap any other entry. This
code finds the id of that entry and prints it.

*************************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <unordered_set>

using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::vector;
using std::getline;
using std::unordered_set;

void stringParser(string, int *, int *, int *, int *);
void initializeFabricGrid(vector<vector<int>> &);


int main() {

	//initialize 2D vector (1000x1000) that will serve as the large fabric.
	vector<vector<int>> fabricGrid;
	initializeFabricGrid(fabricGrid); //initialize each fabric space to hold 0
	
	//get input file
	ifstream inputFile;
	inputFile.open("input.txt");

	if (!inputFile) {
		cout << "Error reading file" << endl;
		exit(0);
	}

	//this values will be updates as each string is parsed
	int startingRow;
	int startingCol;
	int width;
	int height;

	int id = 1;
	unordered_set<int> overlaps;
	//placeholder for each line of input.
	string line;
	while (!inputFile.eof()) {

		//use getline() to read entire line, since each line will include spaces.
		getline(inputFile, line);

		//parse the string
		stringParser(line, &startingRow, &startingCol, &width, &height);

		//update fabric grid. increment value at each space taken from the rectangular
		//region by 1.
		for (int i = startingRow; i < startingRow + height; i++) {
			for (int j = startingCol; j < startingCol + width; j++) {
				if (i >= 1000 || j >= 1000) {
					cout << "Out of vector range" << endl;
					exit(0);
				}
				if (fabricGrid.at(i).at(j) > 0) {
					overlaps.insert(fabricGrid.at(i).at(j));
					overlaps.insert(id);
				}
				fabricGrid.at(i).at(j) = id;
			}
		}
		id++;
	}

	//result to be printed
	int result = 0;

	for (int i = 1; i < id && result == 0; i++) {
		if (overlaps.count(i) == 0) result = i;
	}

	

	//print result.
	cout << result << endl;

}

/***************************************************************
Function to update the values of startingRow, startingCol, width,
and height by extracting those numbers from each input string. 
***************************************************************/
void stringParser(string line, int *startingRow, int *startingCol, int *width, int *height) {
	
	int index = line.size() - 1;

	//reset parameters
	*startingRow = 0;
	*startingCol = 0;
	*width = 0;
	*height = 0;

	//get height
	int multiplier = 1;
	while (line.at(index) != 'x') {
		*height += (line.at(index) - '0') * multiplier;
		multiplier *= 10;
		index--;
	}
	//cout << "height found" << endl;

	//get width
	multiplier = 1;
	index--; //move from 'x' index
	while (line.at(index) != ' ') {
		*width += (line.at(index) - '0') * multiplier;
		multiplier *= 10;
		index--;
	}
	//get starting row #
	multiplier = 1;
	index -= 2; //move past ' ' and ':' index
	while (line.at(index) != ',') {
		*startingRow += (line.at(index) - '0') * multiplier;
		multiplier *= 10;
		index--;
	}
	//get starting column #
	multiplier = 1;
	index--; //move past ',' index
	while (line.at(index) != ' ') {
		*startingCol += (line.at(index) - '0') * multiplier;
		multiplier *= 10;
		index--;
	}
}

/*************************************************************
Helper function that initializes the fabricGrid to a 1000x1000
grid with all spaces containing 0.
*************************************************************/
void initializeFabricGrid(vector<vector<int>> &fabricGrid) {
	for (int i = 0; i < 1000; i++) {
		vector<int> newVector;
		for (int j = 0; j < 1000; j++) {
			newVector.push_back(0);
		}
		fabricGrid.push_back(newVector);
	}
}