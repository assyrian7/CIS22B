#ifndef CAR_H
#define CAR_H

#include "Odometer.h"
#include "FuelGauge.h"
#include <iostream>

using namespace std;

class Car{
	
	private:
		int tank;
		int milesPerGal;
		FuelGauge fuelGauge;
		Odometer odometer;
		int milesThisGal;
	
	public:
		Car();
		Car(const Car&);
		Car(int, int, int, double);
		Car(int, int, int, int, double);
		Car& getGas(int = 4000);
		int getMilesPerGal() const;
		int getMilesThisGal() const;
		Odometer getOdometer() const;
		FuelGauge getFuelGauge() const;
		bool runCar(int);
		friend void print(const Car& car);
};
#endif