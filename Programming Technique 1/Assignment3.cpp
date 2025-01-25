// Section 08						Date: 12/1/2025
// Name: SIVARAJ A/L SIVAKUMAR 		Matric No: A24CS0194
// Name: TAN JIAN XIN 				Matric No: A24CS0303

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

bool getInput(string [], int [], int [], int [], int &);
int calTotal(const int [], int);
int getLowest(const int [], int);
int getHighest(const int [], int);
void printInput(string[], int [], int [], int [], int &);
void printTot(int, int, int, double, double, double);
void printOut(string [], int [], int [], int [], int, int, int, int, int, int);

const int Maxuni = 100;

int main()
{
	string universities[Maxuni];
	int intake[Maxuni], enrolment[Maxuni], output[Maxuni], uniCount; 
	
	if (!getInput(universities, intake, enrolment, output, uniCount)) 
	{ 
		return 1; 
	}
	
	int totalIntake = calTotal(intake, uniCount); 
	int totalEnrolment = calTotal(enrolment, uniCount); 
	int totalOutput = calTotal(output, uniCount); 
	double avgIntake = static_cast<double>(totalIntake) / uniCount; 
	double avgEnrolment = static_cast<double>(totalEnrolment) / uniCount; 
	double avgOutput = static_cast<double>(totalOutput) / uniCount; 
	
	cout << "Now writing data to the file..." << endl;
	printInput(universities, intake, enrolment, output, uniCount);
	printTot(totalIntake, totalEnrolment, totalOutput, avgIntake, avgEnrolment, avgOutput);
	
	int lowestIntake = getLowest(intake, uniCount); 
	int highestIntake = getHighest(intake, uniCount); 
	int lowestEnrolment = getLowest(enrolment, uniCount); 
	int highestEnrolment = getHighest(enrolment, uniCount); 
	int lowestOutput = getLowest(output, uniCount); 
	int highestOutput = getHighest(output, uniCount); 

	printOut(universities, intake, enrolment, output, lowestIntake, highestIntake, lowestEnrolment, highestEnrolment, lowestOutput, highestOutput);
	cout << "Finish" << endl;
	
	return 0;
}

bool getInput(string universities[], int intake[], int enrolment[], int output[], int& count)
{
	ifstream inputFile("input.txt"); 
	if (!inputFile.is_open()) 
	{
		cout << "ERROR: Cannot open file" << endl;
		return false;
	}
	
	count = 0; 
	while (inputFile >> universities[count] >> intake[count] >> enrolment[count] >> output[count]) 
	{ 
		count++; 
		if (count >= Maxuni) 
		{ 
			cout << "Exceeded maximum number of universities." << endl; 
			return false; 
		}
	}
	
	inputFile.close(); 
	return true; 
}

int calTotal(const int arr[], int size) 
{
	int total = 0;
	for (int i = 0; i < size; i++) 
	{ 
		total += arr[i]; 
	}
	return total; 
}

int getLowest(const int arr[], int size) 
{
	int lowest = 0; 
	for (int i = 1; i < size; i++) 
	{ 
		if (arr[i] < arr[lowest]) 
		{ 
			lowest = i; 
		}
	}
	return lowest;
}

int getHighest(const int arr[], int size)
{
	int highest = 0; 
	for (int i = 1; i < size; i++) 
	{ 
		if (arr[i] > arr[highest])
		{ 
			highest = i; 
		}	
	}
	return highest; 
}

void printInput(string universities[], int intake[], int enrolment[], int output[], int &uniCount)
{
	ofstream outputFile("output.txt",ios::app); 
	outputFile << setw(8) << " " << "NUMBER OF STUDENTS' INTAKE, ENROLMENT AND OUTPUT" << endl;
	outputFile << setw(16) << " " << "IN PUBLIC UNIVERSITIES (2023)" << endl << endl;
	outputFile << "---------------------------------------------------------------" << endl;
	outputFile << setw(12) << "UNIVERSITY" << setw(18) << "INTAKE" << setw(17) << "ENROLMENT" << setw(13) << "OUTPUT" << endl;
	outputFile << "---------------------------------------------------------------" << endl;
	for (int i = 0; i < uniCount; i++) 
	{ 
		outputFile << setw(5) << " "  << left << setw(6) << universities[i] << right << setw(19) << intake[i] << setw(15) << enrolment[i] << setw(15) << output[i] << endl; 
	}
}

void printTot(int totalIntake, int totalEnrolment, int totalOutput, double avgIntake, double avgEnrolment, double avgOutput)
{
	ofstream outputFile("output.txt",ios::app); 
	outputFile << "---------------------------------------------------------------" << endl;
	outputFile << setw(5) << " " << left << setw(6) << "TOTAL" << right << setw(19) << totalIntake << setw(15) << totalEnrolment << setw(15) << totalOutput << endl; 
	outputFile << showpoint;
	outputFile << setw(5) << " " << left << setw(7) << "AVERAGE" << right << setw(18) << avgIntake << setw(15) << setprecision(7) << avgEnrolment << setw(15) << setprecision(6) << avgOutput << endl; 
	outputFile << "---------------------------------------------------------------" << endl << endl;
}

void printOut(string universities[], int intake[], int enrolment[], int output[], int lowestIntake, int highestIntake, int lowestEnrolment, int highestEnrolment, int lowestOutput, int highestOutput)
{
	ofstream outputFile("output.txt",ios::app); 
	outputFile << "THE LOWEST NUMBER OF STUDENTS' INTAKE    = " << intake[lowestIntake] << " (" << universities[lowestIntake] << ")" << endl; 
	outputFile << "THE LOWEST NUMBER OF STUDENTS' ENROLMENT = " << enrolment[lowestEnrolment] << " (" << universities[lowestEnrolment] << ")" << endl;
	outputFile << "THE LOWEST NUMBER OF STUDENTS' OUTPUT    = " << output[lowestOutput] << " (" << universities[lowestOutput] << ")" << endl << endl;  
	outputFile << "THE HIGHEST NUMBER OF STUDENTS' INTAKE    = " << intake[highestIntake] << " (" << universities[highestIntake] << ")" << endl;
	outputFile << "THE HIGHEST NUMBER OF STUDENTS' ENROLMENT = " << enrolment[highestEnrolment] << " (" << universities[highestEnrolment] << ")" << endl;
	outputFile << "THE HIGHEST NUMBER OF STUDENTS' OUTPUT    = " << output[highestOutput] << " (" << universities[highestOutput] << ")" << endl << endl;

	int rangeIntake = intake[highestIntake] - intake[lowestIntake];
	int rangeEnrolment = enrolment[highestEnrolment] - enrolment[lowestEnrolment]; 
	int rangeOutput = output[highestOutput] - output[lowestOutput]; 
	outputFile << "THE RANGE OF NUMBER OF STUDENTS' INTAKE    = " << rangeIntake << endl; 
	outputFile << "THE RANGE OF NUMBER OF STUDENTS' ENROLMENT = " << rangeEnrolment << endl; 
	outputFile << "THE RANGE OF NUMBER OF STUDENTS' OUTPUT    = " << rangeOutput << endl; 
	outputFile << "---------------------------------------------------------------" << endl;
	outputFile.close();
}
