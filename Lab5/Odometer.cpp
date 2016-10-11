#include "Odometer.h"

Odometer::Odometer() {
	/*Pre: 
	
	Purpose: initialize the Odomoter with a default mileage of 100000 miles

	Post: return nothing
	*/
	mileage = 100000;
}
Odometer::Odometer(double mMileage) {
	/*Pre: mMileage: the count for the car's total distance traveled

	Purpose: initialize the Odometer with the argument value mMileage

	Post: return nothing
	*/
	mileage = mMileage;
}
void Odometer::setMileage(double mMileage){
	/*Pre: mMileage: the count for the car's total distance traveled

	Purpose: set the mileage for the Odometer

	Post: return nothing
	*/
	mileage = mMileage;
}
double Odometer::getMileage() const{
	/*Pre: no parameters

	Purpose: return the car's Odometer reading to the user

	Post: return the mileage
	*/
	return mileage;
}

Odometer Odometer::operator++(int) {
	/*Pre: 

	Purpose: increment the mileage for the Odometer

	Post: return a temp Odometer
	*/
	Odometer temp;
	temp.setMileage(mileage);
	if (mileage >= MAX)
		mileage = 0;
	else
		mileage++;
	return *this;
}