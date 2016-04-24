
#include <iostream>
#include <iomanip>
#define TAX_RATE 0.0825
#define TIP_RATE 0.20

double calcTotal(double, double* tax, double* tip);
//void calculateVariables(double bill, double &tax, double &tip, double &total);
void outputVariables(double bill, double tax, double tip, double total);

using namespace std;

int main(){
	
	double bill, tax, tip, total;
	
	cout << "Enter your bill: ";
	cin >> bill;
	
	//calculateVariables(bill, tax, tip, total);
	
	total = calcTotal(bill, &tax, &tip);
	
	outputVariables(bill, tax, tip, total);
	
	system("pause");
	
	return 0;
	
}
/*
void calculateVariables(double bill, double &tax, double &tip, double &total){
	tax = bill * TAX_RATE;
	tip = bill * TIP_RATE;
	total = bill + tax + tip;
}
*/
double calcTotal(double bill, double* tax, double* tip){
	/*Pre: bill: amount of bill
			taxAmt: pointer to an amount of tax
			tipAmt: pointer to an amount of tip
	  Post: Total of the bill is returned
	  Purpose: Compute tax, tip, and the bill total*/
	
	double total;
	
	*tax = TAX_RATE * bill;
	*tip = TIP_RATE * (bill + *tax);
	total = bill + *tax + *tip;
	return total;
}

void outputVariables(double bill, double tax, double tip, double total){
	cout << setprecision(2) << fixed << endl;
	cout << "Original bill: $" << bill << endl;
	cout << "Tax: $" << tax << endl;
	cout << "Tip: $" << tip << endl;
	cout << "Total: $" << total << endl;
}