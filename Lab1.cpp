/* Paul Badalian
   Lab1: Cities and sorting
   bad.alien7@gmail.com
*/
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#define MAX 1000

using namespace std;

//Function Prototypes
int getData(ifstream& infile, string city[], double costIndex[]);
void printAll(ofstream& outFile, string city[], double costIndex[], int num);
void reverseArr(string city[], double costIndex[], int num); //cout
double findCostIndex(string city[], double costIndex[], int size);
void insertionSort(string city[], double costIndex[], int size); 
int findIndex(string city[], string target, int n);
void deleteCityAndCost(string city[], double costIndex[], int n);

int main()
{
	//Variable declarations
	string city[MAX]; //holds the name, XX for each city
	double costIndex[MAX]; //cost of living index for that city
	int num; //number of cities in study

	ifstream inFile;
	ofstream outFile;

	//Open file
	inFile.open("cities.txt");
	//Tests if file exists
	if (inFile.fail())
	{
		//error to console
		cout << "Error: File not found!" << endl;
		system("pause");
		return 1;
	} 
	outFile.open("output.txt");

	//Function to input name of city and cost index; returns number of cities in study
	num = getData(inFile, city, costIndex);
	inFile.close();

	cout << findCostIndex(city, costIndex, num) << endl;

	reverseArr(city, costIndex, num);
	cout << "The array has been reversed" << endl;
	
	//Function to output name of city, cost index formatted in two tabular columns
	insertionSort(city, costIndex, num);
	cout << "The array has been sorted" << endl;	
	
	deleteCityAndCost(city, costIndex, num);
	
	
	printAll(outFile, city, costIndex, num);
	outFile.close();

	system("pause");
	return 0;
}

int getData(ifstream& infile, string city[], double costIndex[]){
	
	/*Pre: infile: reference to ifstream object
		   city: array of strings 
		   costIndex: array of doubles
	
	 Purpose: find the number of cities and cost indexes in the file
	
	 Post: return and int of the number of cities
	*/
	
	string readCity;
	double readCostIndex;
	int i = 0;
	
	while(infile >> readCostIndex && getline(infile, readCity) && i < MAX){
		
		costIndex[i] = readCostIndex;
		city[i] = readCity.substr(1);
		
		i++;
	}
	
	return i;
}

void printAll(ofstream& outfile, string city[], double costIndex[], int num){
	
	/*Pre outfile: reference to ofstream object
		  city: array of strings containing the citiess
		  costIndex: array of doubles containing the cost indexes
		  num: int representing the size of the arrays
		  
	  Purpose: output all of the cities and cost indexes to the outfile in tabular columns
	  
	  Post: return nothing
	*/
	outfile << "Paul Badalian" << endl;
	outfile << "Lab1: Cities and sorting" << endl;
	outfile << "bad.alien7@gmail.com" << endl << endl; 
	outfile << left << setw(50) << "City" << left << setw(12) << "Cost Index" << endl;
	outfile << left << setw(50) << "----" << left << setw(12) << "----------" << endl;
		
	for(int i = 0; i < num; i++){
		
		outfile << left << setw(50) << city[i] << right << setw(10) << costIndex[i] << endl;
		
	}
	
}

void reverseArr(string city[], double costIndex[], int num){
	
	/*Pre: city: array of strings containing the cities
		   costIndex: array of doubles containing the cost indexes
		   num: int representing the size of the arrays
		   
	  Purpose: reverse all of the elements in the city and costIndex arrays
	  
	  Post: return nothing
	*/
	
	for(int i = 0; i < num / 2; i++){
		string temp = city[i];
		city[i] = city[num - i - 1];
		city[num - i - 1] = temp;
	}
	
	for(int i = 0; i < num / 2; i++){
		double temp = costIndex[i];
		costIndex[i] = costIndex[num - i - 1];
		costIndex[num - i - 1] = temp;
	}
	
}
int findIndex(string city[], string target, int n){
	
	/*Pre: city: array of strings containing the cities
		   target: string to be searched in the array
		   n: int representing the size of the array
		   
	  Purpose: find the index of the found city
	  
	  Post: return the index of the found city or return -1 stipulating the city is not found
	*/
	
	int index = -1;
	for(int i = 0; i < n; i++){
		if(target.compare(city[i]) == 0){
			index = i;
			break;
		}
	}
	return index;
	
}
double findCostIndex(string city[], double costIndex[], int size){
	
	/*Pre: city: array of strings containing the cities
		   costIndex: array of doubles containing the cost indexes
		   size: int representing the number of elements in the arrays
		   
	  Purpose: find the costIndex corresponding to the city entered by the user
	  
	  Post: return the costIndex
	*/
	
	string target;
	int found = -1;
	
	cout << "Enter the name of the city: ";
	getline(cin, target);
	
	for(int i = 0; i < size; i++){
		if(city[i].compare(target) == 0){
			found = i;
			break;
		}
	}
	if(found == -1){
		cout << "No such city" << endl;
		return found;
	}
	return costIndex[found];
}
void insertionSort(string city[], double costIndex[], int n){

	/*Pre: city: array of strings containing the cities
		   costIndex: array of doubles containing the cost indexes
		   n: int representing the number of elements in the arrays
	  
	  Purpose: sort the elements in the arrays
	  
	  Post: return nothing
	*/

	double temp;
	string temp2;
	int current;
	int walker;
	bool found;

	for (current = 1; current < n; current++){

		found = false;
		temp = costIndex[current];
		temp2 = city[current];
		walker = current - 1;

		while (walker >= 0 && !found){
			if (temp < costIndex[walker]){
				costIndex[walker + 1] = costIndex[walker];
				city[walker + 1] = city[walker];
				walker--;
			}
		
			else
				found = true;

			costIndex[walker + 1] = temp;
			city[walker + 1] = temp2;
		}
	}//for
}
void deleteCityAndCost(string city[], double costIndex[], int n){
	
	/*Pre city: array of strings containing the cities
		  costIndex: array of doubles containing the cost indexes
		  n: int representing the number of elements in the arrays
		  
	  Purpose: delete the city and cost index corresponding to the city entered by the user
	  
	  Post: return nothing
	*/
	
	string target;
	cout << "Enter the city to delete: ";
	getline(cin, target);
	
	int deletedIndex = findIndex(city, target, n);
	if(deletedIndex == -1){
		cout << "No such city" << endl;
		return;
	}
	int walker = deletedIndex + 1;
	double temp = costIndex[n - 1];
	string temp2 = city[n - 1];
	
	while(walker <= n - 1){
		costIndex[walker - 1] = costIndex[walker];
		city[walker - 1] = city[walker];
		walker++;
		costIndex[walker - 1] = temp;
		city[walker - 1] = temp2;
	}
	
	
}

