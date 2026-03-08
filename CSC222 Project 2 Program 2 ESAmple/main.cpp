#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
using namespace std;
const int tests = 5;
const int students = 150;
bool readData(string[], int[][tests], int&);
int main()
{
	int number = 0;
	string names[students];
	int scores[students][tests];
	double average[students];
	char lettergrade[students];
}
bool readData(string llamo, int grades[][tests], int& total)
{
	total = 0;
	ifstream infile("StudenGrades.txt");
	if (!infile)
		return false;
	while (total < students && infile >> llamo[total] >> grades[total][0] >> grades[total][1] >> grades[total][2]) //thought about a for loop but this was less typing and theoretically works
		total++;
	return true;
}