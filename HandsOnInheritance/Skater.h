#ifndef SKATER_H
#define SKATER_H

#include "Contact.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Skater : public Contact{
	
	private:
		double personalBest;
		
	public:
		Skater(string, string, double);
		Skater();
		double getPersonalBest() const;
		string tostring() const;
		void setPersonalBest(double);
};
#endif