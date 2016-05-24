/*
*	Paul Badalian
*	Aaron John
*	Cars problem
*	bad.alien7@gmail.com
*	aaronjohn2@me.com
*/
#include <iostream>
#include <fstream>
#include <string>
#define MAX 100
using namespace std;

struct car{
	int year;
	string make;
	string model;
	int mileage;
	float price;
	string vin;
};

char getOption();
void add(struct car lot[], int* num);
void del(struct car lot[], int* num);
void outFile(ofstream& outFile, struct car lot[], int num);
void print(struct car lot[], int num);
int getData(ifstream& inFile, struct car lot[]);

int main (){

	struct car lot[MAX];
	int num; 
	char action;
	ifstream inFile;
	ofstream out;
	
	inFile.open("cars.txt");
	
	if(inFile.fail()){
		cout << "File could not be opened" << endl;
		return 1;
	}
	
	out.open("out.txt");

	//Input data from file
	num = getData(inFile, lot);
	

	do{
		action = getOption();
		switch (action){
		case 'A':
			add(lot, &num);
			//lot[num++] = selected;
			break;
		case 'D':
			del(lot, &num);
			break;
		case 'F':
			outFile(out, lot, num);
			break;
		case 'P':
			print(lot, num);
			break;
		case 'Q':
			break;
		}//switch
	}while (action != 'Q');

	return 0;
}

char getOption(){
	
	char ch;
	cout << "\n******************************" << endl;
	cout << "\n\t\tMenu" << endl;
	cout << endl;
	cout << "Enter A to add a car\n"<< endl;
	cout << "Enter D to delete a car\n"<< endl;
	cout << "Enter F to output to a file\n" << endl;
	cout << "Enter P to print to screen\n" << endl;
	cout << "Enter Q to quit\n" << endl;
	cout << "*******************************" << endl;
	cout << "\n\nPlease enter your choice: ";
	cin >> ch; cin.ignore();

	return toupper(ch);
}


void add(struct car lot[], int* num){
	
	struct car newCar;
	int year;
	string make;
	string model;
	int mileage;
	float price;
	string vin;
	
	cout <<"Enter car year: ";
	cin >> year;
	cout << "Enter car make: ";
	cin >> make;
	cout << "Enter car model: ";
	cin >> model;
	cout << "Enter car price: ";
	cin >> price;
	cout << "Enter car vin: ";
	cin >> vin;
	
	newCar.year = year;
	newCar.make = make;
	newCar.model = model;
	newCar.mileage = mileage;
	newCar.price = price;
	newCar.vin = vin;
	
	lot[(*num)++] = newCar;
	
}

int getData(ifstream& inFile, struct car lot[]){
	
	int index = 0;
	
	while(index < MAX && !inFile.eof()){
		
		
		inFile >> lot[index].year;
		inFile >> lot[index].make;
		inFile >> lot[index].model;
		inFile >> lot[index].mileage;
		inFile >> lot[index].price;
		inFile >> lot[index].vin;

		index++;
		
	}
	
	return index;
}

void outFile(ofstream& outFile, struct car lot[], int num){
	
	for(int i = 0; i < num; i++){
		
		outFile << lot[i].year << " " << lot[i].make << " " << lot[i].model << " " << lot[i].mileage << " " << lot[i].price << " " << lot[i].vin << endl;  
		
	}
	
}

void del(struct car lot[], int* num){
	
	
	int index = -1;
	string make;
	string model;
	
	cout << "Enter the make of the car you want to delete: ";
	cin >> make;
	cout << "Enter the model of the car: ";
	cin >> model;
	
	for(int i = 0; i < *num; i++){
		
		if(lot[i].make == make && lot[i].model == model){
			
			index = i;
			
		}
		
	}
	
	if(index == -1){
		
		cout << "Car not found nothing to delete" << endl;
		return;
		
	}
	
	for(int i = index; i < *num; i++){
		lot[i] = lot[i + 1];
	}
	
	(*num)--;
	
	
}

void print(struct car lot[], int num){
	
	
	for(int i = 0; i < num; i++){
		
		cout << lot[i].year << " " << lot[i].make << " " << lot[i].model << " " << lot[i].mileage << " " << lot[i].price << " " << lot[i].vin << endl;  

		
	}
	
}





