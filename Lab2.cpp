/*
*	Paul Badalian
*	Lab2
*	bad.alien7@gmail
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;

void getData(ifstream& infile, double** data, int* num);
double** setNewData(double* data, int num);
double calcStandardDeviation(double* mean, double** data, int num);
void outputData(ofstream& outfile, double* oldData, double** newData, int num);

int main(){
	
	
	ifstream infile;
	ofstream outFile;
	int num;
	double* oldData;
	double** newData;
	
	//Open the output data
	infile.open("Scientific Data.txt");
	
	if (infile.fail())
	{
		//error to console
		cout << "Error: File not found!" << endl;
		system("pause");
		return 1;
	} 
	outFile.open("output.txt");
	
	//Read the data and store it
	getData(infile, &oldData, &num);
	
	//Set the pointers to the data
	newData = setNewData(oldData, num);
	
	//Output all of the data
	outputData(outFile, oldData, newData, num);
	
	//Free the allocated data
	delete oldData;
	delete newData;
	
	system("pause");
	
	return 0;
}
void getData(ifstream& infile, double** data, int* num){
	
	/*Pre: infile: reference to ifstream object
		   data: double pointer to a double which will point to the input data 
		   num: number of data objects
	
	 Purpose: read the number of data objects and set the pointer to them
	
	 Post: return nothing
	*/
	
	infile >> *num;
	
	
	*data = new double[*num];
	
	for(int i = 0; i < *num; i++){
		infile >> *(*data + i);
	}
	
	
}

double** setNewData(double* data, int num){
	
	/*Pre: data: single pointer to a double which points to the original data 
		   num: number of data objects
	
	 Purpose: set newData to the pointers to the original data
	
	 Post: return a double pointer to a double which will be set to the original data
	*/
	
	double** newData;
	newData = new double*[num];
	for(int i = 0; i < num; i++){
		*(newData + i) = data + i;
	}
	return newData;
}
double calcStandardDeviation(double* mean, double** data, int num){
	
	/*Pre: mean: single pointer to a double which will contain the mean of all the data objects
		   data: double pointer to a double that contains the data 
		   num: number of data objects
	
	 Purpose: calculate the standard deviation of all the data
	
	 Post: return the standard deviation
	*/
	
	double sum = 0;
	double standardDeviation = 0;
	*mean = 0;
	
	for(int i = 0; i < num; i++){
		sum += **(data + i);
	}
	
	*mean = sum / num;
		
	for(int i = 0; i < num; i++){
		standardDeviation += ((**(data + i) - *mean) * (**(data + i) - *mean));
	}
	
	
	return sqrt(standardDeviation / num);
	
}
void sortSelect(double** arr, int num){
    
	/*Pre: arr: double pointer to a double that contains the data 
		   num: number of data objects
	
	 Purpose: sort the data using insertion sort
	
	 Post: return nothing
	*/
	
	int current; int walker;
    int smallestIndex;
    double* temp;
    
    for (current = 0; current < num - 1; current++)
    {
        smallestIndex = current;
        for (walker = current; walker < num; walker++)
          {
                if (**(arr + walker) < **(arr + smallestIndex))
                  smallestIndex = walker;
          }//for walker
        
        //Swap to position smallest at what is the current position
        temp = *(arr + current);
        *(arr + current) = *(arr + smallestIndex); 
        *(arr + smallestIndex) = temp;  
    }//for current 
	
}
void outputData(ofstream& outfile, double* oldData, double** newData, int num){
	
	/*Pre: outfile: reference to the output file object
		   oldData: single pointer to a double that points to the original data
		   newData: double pointer to a double that contains the data set to the original 
		   num: number of data objects
	
	 Purpose: calculate the standard deviation of all the data
	
	 Post: return the standard deviation
	*/
	
	double mean;
	int i;
	double standardDeviation = calcStandardDeviation(&mean, newData, num);
	
	
	outfile << "Paul Badalian" << endl;
	outfile << "Lab2" << endl;
	outfile << "bad.alien7@gmail.com" << endl << endl;
	
	outfile << "Standard Deviation = " << standardDeviation << endl << endl;
	
	//Set decimal precision to one
	outfile << setprecision(1) << fixed;
	
	i = 0;
	while(i < num){
		for(int j = 0; j < 8; j++){
			if(i < num){
				outfile << setw(7) << right << *(oldData + i);
				i++;
			}
		}
		outfile << endl;
	}
	outfile << endl;
	
	
	sortSelect(newData, num);
	
	//Output sorted data and check to see if the elements are out of range
	for(int j = 0; j < num; j++){
		if(**(newData + j) < mean - 1.5 * standardDeviation || **(newData + j) > mean + 1.5 * standardDeviation){
			outfile << setw(12) << left << "Out of range" << endl;
		}
		else{
			outfile << setw(12) << right << **(newData + j) << endl;
		}
	}
	
}