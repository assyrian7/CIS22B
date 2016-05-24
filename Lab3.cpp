/*
*	Paul Badalian
*	Lab3
*	bad.alien7@gmail
*/
#include <iostream>
#include <fstream>
#include <iomanip>
#define MAX 50
#define SCORES 5

using namespace std;

struct Score{
	
	double difficulty;
	double scores[SCORES];
	double totalScore;
	
};

struct Diver{
	
	string name;
	Score score;
	
};

int getData(ifstream& infile, Diver divers[]);
void bubbleSort(Diver divers[], int num);
double calcTotalScore(double scores[], double difficulty);
void outputDivers(ofstream& outfile, int num, Diver divers[]);

int main(){
	
	int num;
	ifstream infile;
	ofstream outfile;
	Diver divers[MAX];
	infile.open("DIV1.txt");
	
	if(infile.fail()){
		cout << "Input file could not be opened" << endl;
		return 1;
	}
	outfile.open("outDiver.txt");
	
	num = getData(infile, divers);
	bubbleSort(divers, num);
	outputDivers(outfile, num, divers);
	
	return 0;
}


int getData(ifstream& infile, Diver divers[]){
	
	/*Pre: infile: reference to ifstream object
		   divers: struct array to hold data for the divers
	
	 Purpose: read the data for each diver and store it in the array
	
	 Post: return the number of divers read
	*/
	
	int index = 0;
	
	while(index < MAX && !infile.eof()){
		
		getline(infile, divers[index].name);
		infile >> divers[index].score.difficulty;
		for(int i = 0; i < SCORES; i++){
			infile >> divers[index].score.scores[i];
		}
		divers[index].score.totalScore = calcTotalScore(divers[index].score.scores, divers[index].score.difficulty);
		
		infile.ignore(80, '\n');
		
		index++;
		
	}
	
	return index;
}

double calcTotalScore(double scores[], double difficulty){
	
	/*Pre: scores: array of doubles to hold scores for each diver
		   difficulty: double to hold the difficulty of a diver 
	
	 Purpose: calculate a diver's total score based on the difficulty
	
	 Post: return the total score
	*/
	int i = 0;
	double low = scores[i];
	double high = scores[i];
	for(i = 0; i < SCORES; i++){
		if(scores[i] < low){
			low = scores[i];
		}
		if(scores[i] > high){
			high = scores[i];
		}
	}
	
	double totalScore;
	for(i = 0; i < SCORES; i++){
		totalScore += scores[i];
	}
	totalScore -= high;
	totalScore -= low;
	totalScore /= (SCORES - 2);
	totalScore *= difficulty;
	return totalScore;
}

void bubbleSort(Diver divers[], int n){

	/*Pre: divers: struct array to hold divers
		   n: int to hold number of divers
	
	 Purpose: sort the divers by total score using bubble sort
	
	 Post: return nothing
	*/

	Diver temp; int i;
	int lights = 1; //on


	while (lights){

		lights = 0; //turn lights off
		for (i = 0; i < n - 1; i++){

			if (divers[i].score.totalScore < divers[i + 1].score.totalScore){

			  temp = divers[i];

			  divers[i] = divers[i + 1];

			  divers[i + 1] = temp;

			  lights = 1;

			}

		} //for

	}//while

}
void outputDivers(ofstream& outfile, int num, Diver divers[]){
	
	/*Pre: outfile: reference to ofstream object
		   divers: struct array to hold divers 
		   num: int to hold number of divers
	
	 Purpose: output the divers to the output file
	
	 Post: return nothing
	*/
	
	outfile << setprecision(1) << fixed;
	
	for(int i = 0; i < num; i++){
		outfile << "Name: " << setw(20) << left << divers[i].name << " Difficulty: " << setw(4) << right << divers[i].score.difficulty << "   Scores: " << divers[i].score.scores[0];
		for(int j = 1; j < SCORES; j++){
			outfile << ", " << divers[i].score.scores[j];
		}
		outfile << "   ";
		outfile << " TotalScore: " << setw(4) << right << divers[i].score.totalScore << endl;
	}
	
}