/*
*	Paul Badalian
*	CIS 22B
*	Professor Mary Pape
*/


#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;
#define MAX 50
#define COL 7

int getData(ifstream& infile, string element[], double sc[][COL]);
int findElement(string element[], double sc[][COL], int num, string skated);

int main()
{
    string element[MAX]; string skated; 
    double sc[MAX][COL];  int num; int goe; int row;
    ifstream inFile;
    inFile.open("scaleOfValues.txt");

	//Tests if file exists
	if (inFile.fail())
	{
       //error to console
       cout << "Error: File not found!" << endl;
       system("pause");
       return 1;
	}

	//Input data from file
	num = getData(inFile, element, sc);

	cout << "Programmer: Paul Badalian" << endl << endl;
	
	cout << "Enter element: "; cin >> skated;
	cout << "Enter GOE: "; cin >> goe;
 

	//Find element

	row = findElement(element, sc, num, skated);

	if(row == -1){
		cout << "Element not found" << endl;
	}else{
	
	cout << "Points on this element\n" << sc[row][goe] <<endl;
	}
	return 0;
}
int getData(ifstream& infile, string element[], double sc[][COL]){
	
	int index = 0;
	while(!infile.eof() && index < MAX){
		infile >> element[index];
		for(int i = 0; i < COL; i++){
			infile >> sc[index][i];
		}
		index++;
	}
	
	return index;
}
int findElement(string element[], double sc[][COL], int num, string skated){
	int row = -1;
	for(int i = 0; i < num; i++){
		if(element[i].compare(skated) == 0){
			row = i;
		}
	}
	return row;
}

/* Output

Programmer: Paul Badalian

Enter element: 2Lo
Enter GOE: 1
Points on this element
0.6

*/


