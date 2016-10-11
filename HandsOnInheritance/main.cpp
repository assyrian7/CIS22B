//Paul Badalian
#include "Contact.h"
#include "Skater.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;


int main(){
	Contact one("Mary", "papemary@fhda.edu");
	Skater skater("Polina Edward", "edwardsp@sharksice.com", 58.2);
	cout << "Paul Badalian" << endl;
	cout << one.tostring() << endl;
	cout << skater.tostring() << endl;
	system("pause");
	return 0;
}
/*
Paul Badalian
Mary : papemary@fhda.edu
Polina Edward : edwardsp@sharksice.com : 58.2
Press any key to continue . . .
*/