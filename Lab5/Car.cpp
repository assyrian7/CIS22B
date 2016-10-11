#include "Car.h"
#include "Odometer.h"
#include "FuelGauge.h"

Car::Car(){
	/*Pre: 

	Purpose: initialize the car with default values

	Post: return nothing
	*/
	tank = 20;
	milesThisGal = 20;
	odometer.setMileage(100000);
	fuelGauge.setFuelGauge(20);
	milesPerGal = 20;
}
Car::Car(int mTank, int mMilesPerGal, int mCurrentAmountOfFuel, double mMileage) {
	/*Pre: mTank: amount of gallons the car's tank can hold
		   mMilesPerGal: amount of miles the car can travel per gallon
		   mCurrentAmountOfFuel: amount of gallons currently in the tank
		   mMileage: total amount of miles the car has traveled

	Purpose: initialize the car with arguments

	Post: return nothing
	*/
	tank = mTank;
	milesPerGal = mMilesPerGal;
	fuelGauge.setFuelGauge(mCurrentAmountOfFuel);
	odometer.setMileage(mMileage);
	milesThisGal = milesPerGal;

}
Car::Car(int mTank, int mMilesPerGal, int mCurrentAmountOfFuel, int mMilesThisGal, double mMileage) {
	/*Pre: mTank: amount of gallons the car's tank can hold
	mMilesPerGal: amount of miles the car can travel per gallon
	mCurrentAmountOfFuel: amount of gallons currently in the tank
	mMilesThisGal: amount of miles that can be driven with the remaining fuel in the current gallon
	mMileage: total amount of miles the car has traveled

	Purpose: initialize the car with arguments

	Post: return nothing
	*/
	tank = mTank;
	milesPerGal = mMilesPerGal;
	fuelGauge.setFuelGauge(mCurrentAmountOfFuel);
	odometer.setMileage(mMileage);
	milesThisGal = mMilesThisGal;
	if (milesThisGal > milesPerGal) {
		milesThisGal = milesPerGal;
	}

}
Car::Car(const Car& car){
	/*Pre: car: const reference to a car instance that has the new values for this instance

	Purpose: set this instance's values with car's values

	Post: return nothing
	*/
	tank = car.tank;
	milesThisGal = car.milesThisGal;
	odometer.setMileage(car.getOdometer().getMileage());
	fuelGauge.setFuelGauge(car.getFuelGauge().getCurrentAmountOfFuel());
}
Car& Car::getGas(int gallons){
	/*Pre: gallons: count for the amount of gallons remaining in the tank

	Purpose: fill up the car's tank with the amount specified

	Post: return a reference to the instance
	*/
	int gallonsLeft = tank - fuelGauge.getCurrentAmountOfFuel();
	if(gallons > gallonsLeft){
		for(int i = 0; i < gallonsLeft; i++){
			fuelGauge++;
		}
		milesThisGal = milesPerGal;
	}
	else{
		for(int i = 0; i < gallons; i++){
			fuelGauge++;
		}
	}
	print(*this);
	return *this;
}
Odometer Car::getOdometer() const{
	/*Pre: 

	Purpose: return the odometer to the user

	Post: return the odometer
	*/
	return odometer;
}

FuelGauge Car::getFuelGauge() const{
	/*Pre: 

	Purpose: return the fuelgauge to the user

	Post: return the fuelgauge
	*/
	return fuelGauge;
}

int Car::getMilesPerGal() const{
	/*Pre: 

	Purpose: return the amount of miles per gallon to the user

	Post: return milesPerGal
	*/
	return milesPerGal;
}
int Car::getMilesThisGal() const {
	/*Pre: 

	Purpose: return the amount of miles this gallon in the tank to the user

	Post: return milesThisGal
	*/
	return milesThisGal;
}
bool Car::runCar(int miles){
	/*Pre: miles: amount of miles that the car will travel

	Purpose: read the data for each diver and store it in the array

	Post: return a bool stating whether the car made the entire trip or not
	*/
	for(int i = 0; i < miles; i++){
		if(fuelGauge.getCurrentAmountOfFuel() <= 0){
			return false;
		}
		else if(milesThisGal <= 0){
			milesThisGal = milesPerGal;
			fuelGauge--;
			if(fuelGauge.getCurrentAmountOfFuel() <= 0){
				return false;
			}
		}
		milesThisGal--;
		odometer++;
	}
	print(*this);
	return true;
}
void print(const Car& car){
	/*Pre: car: const reference to a car

	Purpose: output the car's gallons left, miles in the current gallon, and mileage

	Post: return the number of divers read
	*/
	cout << "Fuel: " << car.getFuelGauge().getCurrentAmountOfFuel() << ", Miles this gallon: " << car.getMilesThisGal() << ", Odometer: " << car.getOdometer().getMileage() << endl;
}