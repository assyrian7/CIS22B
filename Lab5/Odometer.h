#ifndef ODOMETER_H
#define ODOMETER_H

//Max miles for Odometer
#define MAX 999999

class Odometer{
	
	private:
		double mileage;
	
	public:
		Odometer();
		Odometer(double);
		void setMileage(double);
		double getMileage() const;
		Odometer& operator++();
		Odometer operator++(int);
	
};
#endif