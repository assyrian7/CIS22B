#include <iostream>
#include "Car.h"

using namespace std;

char menu();
void getGas(Car&);
void runCar(Car&);

int main(){

	Car car;

	char option;
	do {
		option = menu();
		switch (option) {
			case 'G':
				getGas(car);
				break;
			case 'R':
				runCar(car);
				break;
			default:
				break;
		}
	} while (option != 'Q');
	system("pause");

	return 0;
}

/*==========================================Menu========================================================================================*/
/**
    pre: -
    post: returns upper case Character of option that was entered by the user
    purpose: Output menu to the screen to give user options to select
*/
char menu(){

	char ch;
	cout << "\n******************************" << endl;
	cout << "\n\t\tMenu" << endl;
	cout << endl;
	cout << "Enter G to get gas\n"<< endl;
	cout << "Enter R to go on a trip\n"<< endl;
	cout << "Enter Q to quit\n" << endl;
	cout << "*******************************" << endl;
	cout << "\n\nPlease enter your choice: ";
	cin >> ch; cin.ignore();

	return toupper(ch);
}

/*==========================================Getting Gas========================================================================================*/
/**
    pre: reference of Car class
    post: returns nothing
    purpose:
*/
void getGas(Car& car) {
	int gallons = -1;
	char choice;
	cout << "Would you like to enter an amount(Y or N): ";
	cin >> choice; cin.ignore();
	choice = toupper(choice);
	if (choice == 'N') {
		car.getGas();
		return;
	}

	while (gallons < 0) {
		cout << "Enter the amount of gallons you want to fill(must be at least 0): ";
		cin >> gallons;
	}
	car.getGas(gallons);
}

/*==========================================Run Car========================================================================================*/
/**
    pre: reference of Car class
    post: returns nothing
    purpose: States if the car made the trip or if it ran out of gas
*/
void runCar(Car& car) {
	int miles;
	do {
		cout << "Enter how far you want to travel(in miles, must be at least 0): ";
		cin >> miles;
	} while (miles < 0);
	if (car.runCar(miles)) {
		cout << "Your car made the trip" << endl;
	}
	else {
		cout << "Your car ran out of gas" << endl;
	}
}
