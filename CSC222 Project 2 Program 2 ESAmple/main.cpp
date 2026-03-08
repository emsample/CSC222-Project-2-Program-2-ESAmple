#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;
const int tests = 5;
const int students = 150;
bool readData(string[], int[][tests], int&);
void avgFinder(double[], const int[][tests], int&);
void gradeAssigned(char[], double[], int&);
void gradeReport(char[], string[], double[], int&);
int main()
{
	int number = 0;
	string names[students];
	int scores[students][tests];
	double average[students];
	char lettergrade[students];
}
bool readData(string llamo[], int grades[][tests], int& total)
{
	total = 0;
	ifstream infile("StudenGrades.txt");
	if (!infile)
		return false;
	while (total < students && infile >> llamo[total] >> grades[total][0] >> grades[total][1] >> grades[total][2]) //thought about a for loop but this was less typing and theoretically works
		total++;
	return true;
}
void avgFinder(double gpa[], const int data[][tests], int& size)
{
	for (int i = 0; i < size; i++)
	{
		int sum = 0;
		for (int data : data[i])
			sum += data;
		gpa[i] = static_cast<double>(sum) / tests;        //wanted to avoid integer division, an 89.5 is an A in my gradebook
	}
	return;
}
void gradeAssigned(char book[], double final[], int& max)
{
	for (int i = 0 ; i<max ; i++)
	{
		if (final[i] >= 89.5)
			book[i] = 'A';
		if (final[i] >= 79.5 && final[i] < 89.5)
			book[i] = 'B';
		if (final[i] >= 69.5 && final[i] < 79.5)
			book[i] = 'C';
		if (final[i] >= 59.5 && final[i] < 69.5)
			book[i] = 'D';
		if (final[i] < 59.5)
			book[i] = 'F';
	}
	return;
}
void gradeReport(char abc[], string nomen[], double testavg[], int& number)
{
	cout << left << setw(20) << "Student" << setw(10) << "|" << setw(10) << "Average Score" << setw(10) << "|" << setw(10) << "Final Grade" << endl;
	cout << "---------------------------------------------------------------------------------\n";
	for (int i = 0; i < number; i++)
	{
		cout << left << setw(20) << nomen[i] << setw(10) << "|" << setw(10) << fixed << setprecision(2) << testavg[i] << setw(10) << "|" << setw(10) << abc[i] << endl;
		cout << "---------------------------------------------------------------------------------\n";
	}
	return;
}