#include <iostream>
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
	double* oldData = NULL;
	double** newData;
	
	infile.open("Scientific Data.txt");
	
	if (infile.fail())
	{
		//error to console
		cout << "Error: File not found!" << endl;
		system("pause");
		return 1;
	} 
	outFile.open("output.txt");
	
	
	getData(infile, &oldData, &num);
	
	
	newData = setNewData(oldData, num);
	
	
	outputData(outFile, oldData, newData, num);
	
	
	return 0;
}
void getData(ifstream& infile, double** data, int* num){
	
	infile >> *num;
	
	
	*data = new double[*num];
	
	for(int i = 0; i < *num; i++){
		infile >> *(*data + i);
	}
	
	
}

double** setNewData(double* data, int num){
	
	double** newData;
	newData = new double*[num];
	for(int i = 0; i < num; i++){
		*(newData + i) = data + i;
	}
	return newData;
}
double calcStandardDeviation(double* mean, double** data, int num){
	
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
	
	double mean;
	int i;
	double standardDeviation = calcStandardDeviation(&mean, newData, num);
	
	
	outfile << "Paul Badalian" << endl;
	outfile << "Lab2" << endl;
	outfile << "bad.alien7@gmail.com" << endl << endl;
	
	outfile << "Standard Deviation = " << standardDeviation << endl << endl;
	
	
	i = 0;
	while(i < num){
		for(int j = 0; j < 8; j++){
			if(i < num){
				outfile << *(oldData + i) << " ";
				i++;
			}
		}
		outfile << endl;
	}
	outfile << endl;
	
	
	sortSelect(newData, num);
	
	
	for(int j = 0; j < num; j++){
		if(**(newData + j) < mean - 1.5 * standardDeviation || **(newData + j) > mean + 1.5 * standardDeviation){
			outfile << "Out of range" << endl;
		}
		else{
			outfile << **(newData + j) << endl;
		}
	}
	
}