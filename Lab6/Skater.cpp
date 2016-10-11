//Paul Badalian

#include "Skater.h"

Skater::Skater() {
	/* 
		Pre: nothing
		Purpose: construct Skater instance
		Post: return nothing
	*/
	events = new string[EVENTS];
	goes = new int*[EVENTS];
	for (int i = 0; i < EVENTS; i++) {
		goes[i] = new int[JUDGES];
	}
	eventScores = new double[EVENTS];
	totalScore = 0.0;
	name = "";
	baseScoresTotal = 0;
}

Skater::~Skater() {
	/*
	Pre: nothing
	Purpose: destruct Skater instance
	Post: return nothing
	*/
	cout << "Nothing" << endl;
}

void Skater::setEvents(string* mEvents) {
	/*
	Pre: mEvents: string pointer to skater events
	Purpose: set the events for the Skater instance
	Post: return nothing
	*/
	for (int i = 0; i < EVENTS; i++) {
		events[i] = mEvents[i];
	}
}
void Skater::setGoes(int** mGoes) {
	/*
	Pre: mGoes: int double pointer to skater goes
	Purpose: set the goes for the Skater instance
	Post: return nothing
	*/
	for (int i = 0; i < EVENTS; i++) {
		for (int j = 0; j < JUDGES; j++) {
			goes[i][j] = mGoes[i][j];
		}
	}
}
void Skater::setName(string mName) {
	/*
	Pre: name: string for the skater's name
	Purpose: set the name for the skater instance
	Post: return nothing
	*/
	name = mName;
}
void Skater::setBaseScoresTotal(double mBaseScoresTotal) {
	/*
	Pre: mBaseScoresTotal: double for the total of base scores for the skater
	Purpose: set the baseScoresTotal for the skater instance
	Post: return nothing
	*/
	baseScoresTotal = mBaseScoresTotal;
}
void Skater::setTotalScore(double mTotalScore) {
	/*
	Pre: mTotalScore: double for the total score for the skater
	Purpose: set the totalScore for the skater instance
	Post: return nothing
	*/
	totalScore = mTotalScore;
}
void Skater::setEventScores(double* mEventScores) {
	/*
	Pre: mEventScores: double pointer to the eventScores for the skater
	Purpose: set the eventScores for the skater instance
	Post: return nothing
	*/
	for (int i = 0; i < EVENTS; i++) {
		eventScores[i] = mEventScores[i];
	}
}
int** Skater::getGoes() const {
	/*
	Pre: nothing
	Purpose: return the skater goes to the user
	Post: return goes
	*/
	return goes;
}
string* Skater::getEvents() const {
	/*
	Pre: nothing
	Purpose: construct Skater instance
	Post: return nothing
	*/
	return events;
}
string Skater::getName() const {
	/*
	Pre: nothing
	Purpose: return the skater name to the user
	Post: return name
	*/
	return name;
}
double* Skater::getEventScores() const {
	/*
	Pre: nothing
	Purpose: return the skater eventScores to the user
	Post: return eventScores
	*/
	return eventScores;
}
double Skater::getBaseScoresTotal() const {
	/*
	Pre: nothing
	Purpose: return the skater baseScoresTotal to the user
	Post: return baseScoresTotal
	*/
	return baseScoresTotal;
}
double Skater::getTotalScore() const {
	/*
	Pre: nothing
	Purpose: return the skater totalScore to the user
	Post: return totalScore
	*/
	return totalScore;
}
bool Skater::operator>(const Skater& right){
	/*
	Pre: right: const reference to a skater for comparison
	Purpose: tell the program which totalScore is larger
	Post: return the comparison
	*/
	if (totalScore > right.totalScore) {
		return true;
	}
	else {
		return false;
	}
}
ostream& operator<<(ostream& out, const Skater& skater) {
	/*
	Pre: out: reference to ostream instance for output
		 skater: const reference to skater instance that will be outputed
	Purpose: output skater data
	Post: return out
	*/
	out << skater.name << endl;
	for (int i = 0; i < EVENTS; i++) {
		out << setw(8) << left << skater.events[i] << setw(2) << right << skater.goes[i][0];
		for (int j = 1; j < JUDGES; j++) {
			out << setw(5) << right << skater.goes[i][j];
		}
		out << " || Technical Score: " << skater.eventScores[i] << endl;
		
	}
	out << "Total Score: " << skater.totalScore << endl;
	
	return out;
}
