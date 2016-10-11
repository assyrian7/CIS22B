#include "Skater.h"

double Skater::getPersonalBest() const{
	return personalBest;
}
string Skater::tostring() const{
	ostringstream convert;
	convert << personalBest;
	return Contact::tostring() + " : " + convert.str();
}
Skater::Skater() : Contact(){
	personalBest = 58.2;
}
Skater::Skater(string name, string email, double mPersonalBest) : Contact(name, email){
	personalBest = mPersonalBest;
}
void Skater::setPersonalBest(double mPersonalBest){
	personalBest = mPersonalBest;
}
