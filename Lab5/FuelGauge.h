// FuelGauge.h
#ifndef FUELGAUGE_H
#define FUELGAUGE_H

#include <iostream>

using namespace std;

class FuelGauge
{
	private:
		int currentAmountOfFuel;

	public:
	
		FuelGauge();
		void setFuelGauge(int);
		int getCurrentAmountOfFuel() const;
		FuelGauge& operator++();
		FuelGauge operator++(int);
		FuelGauge& operator--();
		FuelGauge operator--(int);
		
};

#endif