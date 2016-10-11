//Paul Badalian

#ifndef SKATER_H
#define SKATER_H
#define EVENTS 7
#define JUDGES 9

#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

class Skater {

private:
	string name;
	string* events;
	int** goes;
	double* eventScores;
	double* baseScores;
	double baseScoresTotal;
	double totalScore;
public:
	Skater();
	~Skater();
	void setName(string);
	void setEvents(string*);
	void setGoes(int**);
	void setEventScores(double*);
	void setBaseScoresTotal(double);
	void setTotalScore(double);
	string getName() const;
	string* getEvents() const;
	int** getGoes() const;
	double* getEventScores() const;
	double getBaseScoresTotal() const;
	double getTotalScore() const;
	bool operator>(const Skater&);
	friend ostream& operator<<(ostream&, const Skater&);
};



#endif