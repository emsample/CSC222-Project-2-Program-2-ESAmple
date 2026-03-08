#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;
const int tests = 5;
const int students = 150;												//sets the max number of students it can handle, probably not needed but hey
bool readData(string[], int[][tests], int&);
void avgFinder(double[], const int[][tests], int&);
void gradeAssigned(char[], double[], const int);
void gradeReport(char[], string[], double[], const int);
int main()
{
	int size = 0;
	string names[students];
	int scores[students][tests];
	double average[students];
	char lettergrade[students];
	if (!readData(names, scores, size))													//this right here is why bool functions are so useful
	{
		cout << "Error opening file, check the file is in the correct location\n";
		return 1;
	}
	avgFinder(average, scores, size);
	gradeAssigned(lettergrade, average, size);
	gradeReport(lettergrade, names, average, size);
}
bool readData(string name[], int scores[][tests], int& size)
{
	ifstream infile("StudentGrades.txt");										//I'm glad I put the error message because this typo would've been hard to find
	if (!infile)
		return false;
	for (size; size < students; size++)										//changed this to for loop because hard coding each test looked ugly
	{
		if (!(infile >> name[size]))								
		{
			break;
		}
		for (int& scores : scores[size])				//ranged based loops are cool I always wondered why it wasn't a thing, turns out it was
		{
			infile >> scores;
		}
	}
	return true;
}
void avgFinder(double average[], const int scores[][tests], int& size)
{
	for (int i = 0; i < size; i++)
	{
		int sum = 0;
		for (int data : scores[i])
		{
			sum += data;
		}
		average[i] = static_cast<double>(sum) / tests;        //wanted to avoid integer division, an 89.5 is an A in my gradebook
	}
	return;
}
void gradeAssigned(char lettergrade[], double average[], const int size)
{
	for (int i = 0 ; i<size ; i++)
	{
		if (average[i] >= 89.5)													//normally I'd add brackets but this is really clean without them
			lettergrade[i] = 'A';
		if (average[i] >= 79.5 && average[i] < 89.5)
			lettergrade[i] = 'B';
		if (average[i] >= 69.5 && average[i] < 79.5)
			lettergrade[i] = 'C';
		if (average[i] >= 59.5 && average[i] < 69.5)
			lettergrade[i] = 'D';
		if (average[i] < 59.5)
			lettergrade[i] = 'F';
	}
	return;
}
void gradeReport(char lettergrade[], string name[], double average[], const int size)
{
	cout << left << setw(20) << "Student" << "|" << setw(19) << "Average Score" << "|" << setw(10) << "Final Grade" << endl;			//I pray this works out
	cout << "---------------------------------------------------------------------------------\n";
	for (int i = 0; i < size; i++)
	{
		cout << left << setw(20) << name[i] << setw(10) << "|" << setw(10) << fixed << setprecision(2) << average[i] << setw(10) << "|" << setw(10) << lettergrade[i] << endl;
		cout << "---------------------------------------------------------------------------------\n";
	}
	return;
}