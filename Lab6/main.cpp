//Paul Badalian

#include <iostream>
#include <fstream>
#include <string>
#include "List.h"
#include "Skater.h"
#define EVENTS 7
#define SCORES 7
#define JUDGES 9
#define MAX 200

using namespace std;

int readSOVScores(ifstream& infile, string events[], double scores[][SCORES]);
int getAndInsertData(string& competition, List& list, ifstream& infile, string events[], double scores[][SCORES], int numEvents);
int findEvent(string event, string events[], int numEvents);
int getRealIndex(int index);
void findHighAndLow(double* high, double* low, double scores[]);
void a(Skater& skater);

int main() {

	List list;
	int index = 0;
	string competition;
	string events[MAX];
	double scores[MAX][SCORES];
	ifstream baseData("SOV Lab 6 Data V3.txt");
	ifstream results("Champ_Ladies_Short.txt");
	if (baseData.fail() || results.fail()) {
		cout << "One or both files couldn't open" << endl;
		system("pause");
		return 1;
	}

	int totalEvents = readSOVScores(baseData, events, scores);
	index = getAndInsertData(competition, list, results, events, scores, totalEvents);

	cout << competition << endl;
	cout << "Chief Accountant" << endl << endl;

	list.displayList();	


	system("pause");

	return 0;
}
void a(Skater& skater) {
	List list;
	list.insertNode(skater);
}
int readSOVScores(ifstream& infile, string events[], double scores[][SCORES]) {
	/*
	Pre: infile: reference to ifstream instance
		 events: string array
		 scores
	Purpose: read the SOV scores
	Post: return the number of events
	*/
	int index = 0;
	while (!infile.eof()) {
		infile >> events[index];
		for (int i = 0; i < SCORES; i++) {
			infile >> scores[index][i];
		}
		index++;
	}

	return index;
}
int findEvent(string event, string events[], int numEvents) {
	/*
	Pre: event: string
		 events: string array
	Purpose: return the index of the specified event
	Post: return the row of the event
	*/
	
	int row = 0;

	for (int i = 0; i < numEvents; i++) {
		if (event.compare(events[i]) == 0) {
			row = i;
		}
	}
	return row;
}
int getAndInsertData(string& competition, List& list, ifstream& infile, string events[], double scores[][SCORES], int numEvents) {
	/*
	Pre: competition: string reference
		 list: List reference
		 events: string array
		 scores: 2d array of doubles
	Purpose: read results data and insert it into the list
	Post: return the number of contestants
	*/
	int index = 0;
	int tempScore = 0;
	int row = 0;
	string name;
	
	double baseScoresTotal = 0;
	double totalScore = 0;
	double tempScores[JUDGES];
	double high = 0;
	double low = 0;
	
	getline(infile, competition);

	while (!infile.eof() && index < MAX) {

		Skater skater;
		string skaterEvents[EVENTS];
		double eventScores[EVENTS];
		int** skaterScores = new int*[EVENTS];
		for (int i = 0; i < EVENTS; i++) {
			skaterScores[i] = new int[JUDGES];
		}

		getline(infile, name);
		baseScoresTotal = 0;
		totalScore = 0;
		high = -1;
		low = 20;
		for (int i = 0; i < EVENTS; i++) {

			infile >> skaterEvents[i];
			eventScores[i] = 0;

			for (int j = 0; j < JUDGES; j++) {

				infile >> tempScore;
				skaterScores[i][j] = tempScore;
				row = findEvent(skaterEvents[i], events, numEvents);
				tempScore = getRealIndex(tempScore);
				eventScores[i] += scores[row][tempScore];
				tempScores[j] = scores[row][tempScore];
			}
			infile.ignore();
			findHighAndLow(&high, &low, tempScores);
			eventScores[i] -= high;
			eventScores[i] -= low;
			eventScores[i] /= (JUDGES - 2);
			eventScores[i] += scores[row][3];
			baseScoresTotal += scores[row][3];
			totalScore += eventScores[i];

		}

		skater.setName(name);
		skater.setEvents(skaterEvents);
		skater.setGoes(skaterScores);
		skater.setEventScores(eventScores);
		skater.setBaseScoresTotal(baseScoresTotal);
		skater.setTotalScore(totalScore);
		
		list.insertNode(skater);

		index++;

		for (int i = 0; i < EVENTS; i++) {
			delete[] skaterScores[i];
		}
		delete[] skaterScores;
	}

	
	
	return index;

}
int getRealIndex(int index) {
	/*
	Pre: index: int
	Purpose: return real index of goe to user
	Post: return realIndex
	*/
	return 3 - index;

}
void findHighAndLow(double* high, double* low, double scores[]) {
	/*
	Pre: high: double pointer
		 low: double pointer
		 scores: double array
	Purpose: set the high and low value of scores to high and low
	Post: return nothing
	*/
	*low = 20;
	*high = -1;

	for (int i = 0; i < JUDGES; i++) {
		if (scores[i] > *high) {
			*high = scores[i];
		}
	}
	for (int i = 0; i < JUDGES; i++) {
		if (scores[i] < *low) {
			*low = scores[i];
		}
	}

}
/* `Output
	
	2014 Championship Ladies Short Program
	Chief Accountant

	Contestants:
	Gracie Gold
	Polina Edmonds
	Mirai Nagasu
	Rachael Flatt
	Angela Wang

	Results:

	Gracie Gold

	3Lz      1    2    2    2    1    2    2    2    2 || Technical Score: 7.3
	LSp4     3    2    2    2    2    2    3    2    2 || Technical Score: 3.77143
	FCSp4    2    1    2    2    2    3    2    1    2 || Technical Score: 4.12857
	3Lo      2    1    2    1    1   -1    1    1    1 || Technical Score: 5.9
	2A       2    2    2    2    2    1    1    1    2 || Technical Score: 4.15714
	StSq4    2    3    2    2    3    2    3    2    2 || Technical Score: 5.5
	CCoSp4   3    2    1    2    2    3    3    2    2 || Technical Score: 4.64286
	Total Score: 35.4

	Polina Edmonds

	3Lz      2    2    1    1    1    1    2    2    1 || Technical Score: 7
	3F       3    1    1    1    2   -1    2   -1    1 || Technical Score: 6
	FCSp4    3    1    1    1    2   -1    2    1    2 || Technical Score: 3.91429
	StSq3    2    1    1    1    2    2    1    2    2 || Technical Score: 4.08571
	LSp4     2    2    2    1    3    2    2    2    2 || Technical Score: 3.7
	2A       2    1    1    1    1    1    1    1    1 || Technical Score: 3.8
	CCoSp4   2    2    1    1    2    1    1    2    0 || Technical Score: 4.28571
	Total Score: 32.7857

	Mirai Nagasu

	3T       1    2    1    2    1    2    1    2    2 || Technical Score: 5.2
	CCoSp4   1    1    1    1    2    1    1    2    1 || Technical Score: 4.07143
	FCSp4    2    1    2    1    2    2    1    1    1 || Technical Score: 3.91429
	3Lo      2    1    1    2    1   -1    0    1    1 || Technical Score: 6
	StSq4    3    1    2    1    2    2    1    1    1 || Technical Score: 4.9
	2A       2    2    2    2    2    1    1    1    1 || Technical Score: 4.08571
	LSp4     2    3    3    3    3    3    3    2    2 || Technical Score: 4.05714
	Total Score: 32.2286

	Rachael Flatt

	1Lz     -3   -3   -3   -3   -3   -3   -3   -3   -3 || Technical Score: 0.3
	3F      -1    1    0    0    0    0    1    1    0 || Technical Score: 8.62857
	LSp1     0    0   -1    0   -1   -2    0    0   -1 || Technical Score: 2.22857
	2A       0    1    1    1    1    0    1    1    1 || Technical Score: 4.2
	FCSp4   -1    0    0    0    0    0    0    1    0 || Technical Score: 6.01429
	CCoSp3  -1   -1    0   -1    0    1   -1    0   -2 || Technical Score: 3.75714
	StSq3    1    2    3    2    2   -1    2    1    0 || Technical Score: 4.22857
	Total Score: 29.3571

	Angela Wang

	2A       2    2    1    2    1    2    1    1    2 || Technical Score: 4.08571
	3Lz     -3   -3   -2   -2   -2   -2   -3   -3   -3 || Technical Score: 4.14286
	CCoSp3   1    2    1    1    0    1    0    1    0 || Technical Score: 4.28571
	StSq3    1    2    1    1    1    2    1    2    1 || Technical Score: 3.94286
	3F      -1   -1   -1   -1   -1   -1    0   -1   -1 || Technical Score: 4.6
	FSSp4    1    1    1    1    1    1    0    1    0 || Technical Score: 3.85714
	LSp4     1    2    1    2    2    2    2    1    2 || Technical Score: 3.55714
	Total Score: 28.4714

	Press any key to continue . . .
*/