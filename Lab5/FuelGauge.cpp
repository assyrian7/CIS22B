#include "FuelGauge.h"

/*==========================================Default Constructor========================================================================================*/
FuelGauge::FuelGauge(){
	currentAmountOfFuel = 0;
}

/*==========================================Setting Fuel Gauge========================================================================================*/
/**
    pre: int  gallons - value entered by user for gallons
    post: returns nothing
    purpose: setting value for the current amount of fuel
*/
void FuelGauge::setFuelGauge(int gallons){
	currentAmountOfFuel = gallons;
}

/*==========================================Getting Current Amount of Fuel========================================================================================*/
/**
    pre: -
    post: returns current amount  of fuel
    purpose: Getting value of current amount of fuel
*/
int FuelGauge::getCurrentAmountOfFuel() const{
	return currentAmountOfFuel;
}

/*==========================================Overloading operator: increment========================================================================================*/
/**
    pre: int -
    post: returns temp
    purpose: Adding one to the number of gallons
*/
FuelGauge FuelGauge::operator++(int){
	FuelGauge temp;
	temp.setFuelGauge(currentAmountOfFuel);
	currentAmountOfFuel++;
	return temp;
}

/*==========================================Overloading operator: decrement========================================================================================*/
/**
    pre: int -
    post: returns temp
    purpose:Subtracting one from the number of gallons
*/
FuelGauge FuelGauge::operator--(int){
	FuelGauge temp;
	temp.setFuelGauge(currentAmountOfFuel);
	currentAmountOfFuel--;
	return temp;
}
