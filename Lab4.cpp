#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class CreditCard{

	private:
			string cardNumber;
			double previousBalance;
			double newCharges;
			double interestRate;
			double computeMinimumPayment();
			double computeAmountOwed();

	public:
			CreditCard();
			CreditCard(string, double);
			CreditCard(string, double, double);
			CreditCard(string, double, double, double);
			~CreditCard();
			void setCardNumber(string);
			void setPreviousBalance(double);
			void setNewCharges(double);
			void setInterestRate(double);
			string getCardNumber() const;
			double getPreviousBalance() const;
			double getNewCharges() const;
			double getInterestRate() const;
			void addNewCharge(double);
			void subtractPaidOff(double);
			void generateStatement();
			void acceptPayment(double);
			friend void printToScreen(CreditCard);

};

/*	Pre: no parameters
	
	Purpose: initialize object with default values for card # and newCharges
	
	Post: construct object
*/
CreditCard::CreditCard(){
	cardNumber = "#1234567887654321";
	interestRate = 1.6;
	newCharges = 0;
}


/*	Pre: mCardNumber: card # to be set in object
		 mInterestRate: initerest rate to be set in object
	
	Purpose: initialize object with values for card # and newCharges
	
	Post: construct object
*/
CreditCard::CreditCard(string mCardNumber, double mInterestRate){
	setCardNumber(mCardNumber);
	setInterestRate(mInterestRate);
	newCharges = 0;
}


/*	
	Pre: mCardNumber: card # to be set in object
		 mInterestRate: initerest rate to be set in object
		 mPreviousBalance: previous balance to be set in object
	
	Purpose: initialize object with values for card #, newCharges, and previous balance
	
	Post: construct object
*/
CreditCard::CreditCard(string mCardNumber, double mPreviousBalance, double mInterestRate){
	setCardNumber(mCardNumber);
	setPreviousBalance(mPreviousBalance);
	setInterestRate(mInterestRate);
	newCharges = 0;
}


/*	
	Pre: mCardNumber: card # to be set in object
		 mInterestRate: initerest rate to be set in object
		 mPreviousBalance: previous balance to be set in object
		 mNewCharges: new charges to be set in object
	
	Purpose: initialize object with values for card #, newCharges, previous balance, and new charges
	
	Post: construct object
*/
CreditCard::CreditCard(string mCardNumber, double mPreviousBalance, double mInterestRate, double mNewCharges){
	setCardNumber(mCardNumber);
	setPreviousBalance(mPreviousBalance);
	setInterestRate(mInterestRate);
	setNewCharges(mNewCharges);
}


/*
	Pre: no parameters
	
	Purpose: Destruct object
	
	Post: destruct object
*/
CreditCard::~CreditCard(){
	cout << "Destructing" << endl;
}


/*	
	Pre: mCardNumber: card # to be set in object
	
	Purpose: set object with value for card #
	
	Post: return nothing
*/
void CreditCard::setCardNumber(string mCardNumber){
	cardNumber = mCardNumber;
}


/*	
	Pre: mPreviousBalance: previous balance to be set in object
	
	Purpose: set object with value previous balance, and new charges
	
	Post: return nothing
*/
void CreditCard::setPreviousBalance(double mPreviousBalance){
	previousBalance = mPreviousBalance;
}


/*	
	Pre: mInterestRate: initerest rate to be set in object
	
	Purpose: set object with value interest rate
	
	Post: return nothing
*/
void CreditCard::setInterestRate(double mInterestRate){
	interestRate = mInterestRate;
}


/*	
	Pre: mNewCharges: new charges to be set in object
	
	Purpose: set object with value new charges
	
	Post: return nothing
*/
void CreditCard::setNewCharges(double mNewCharges){
	newCharges = mNewCharges;
}


/*	
	Pre: no parameters

	Purpose: get cardNumber value from object
	
	Post: return cardNumber
*/
string CreditCard::getCardNumber() const{
	return cardNumber;
}


/*	
	Pre: no parameters

	Purpose: get previousBalance value from object
	
	Post: return previousBalance
*/
double CreditCard::getPreviousBalance() const{
	return previousBalance;
}


/*	
	Pre: no parameters

	Purpose: get interest rate value from object
	
	Post: return interest rate
*/
double CreditCard::getInterestRate() const{
	return interestRate;
}


/*	
	Pre: no parameters

	Purpose: get new charges value from object
	
	Post: return new charges
*/
double CreditCard::getNewCharges() const{
	return newCharges;
}


/*	
	Pre: newCharge: hold a new charge to be added to charges for a credit card

	Purpose: add a charge to the charges on a credit card
	
	Post: return nothing
*/
void CreditCard::addNewCharge(double newCharge){
	newCharges += newCharge;
}


/*	
	Pre: subtractPaidOff: value to be subtracted from credit card balance

	Purpose: subtract paidOff from balance
	
	Post: return nothing
*/
void CreditCard::subtractPaidOff(double paidOff){
	previousBalance -= paidOff;
}


/*	
	Pre: no parameters

	Purpose: calculate minimum payment based on the amount owed
	
	Post: return minimum payment
*/
double CreditCard::computeMinimumPayment(){
	
	double minimumPayment = computeAmountOwed() * .1;
	
	if(minimumPayment < 15)
		return computeAmountOwed();

	return minimumPayment;
	
}


/*	
	Pre: no parameters

	Purpose: calculate amount owed based on balance, interest rate, and charges
	
	Post: return amount owed
*/
double CreditCard::computeAmountOwed(){
	
	double amount = previousBalance + (previousBalance * (interestRate / 100)) + newCharges;
	return amount;

}


/*	
	Pre: no parameters

	Purpose: output to screen the minimum payment and amount owed
	
	Post: return nothing
*/
void CreditCard::generateStatement(){
	
	double minimumPayment = computeMinimumPayment();
	double amountOwed = computeAmountOwed();
	
	cout << setprecision(1) << fixed << endl;
	cout << "Minimum Payment: " << minimumPayment << endl;
	cout << "Amount Owed: " << amountOwed << endl;
	 
}


/*	
	Pre: payment: amount to pay off

	Purpose: pay off amount for balance and charges
	
	Post: return nothing
*/
void CreditCard::acceptPayment(double payment){
	subtractPaidOff(payment);
	if(payment >= newCharges){
		newCharges = 0;
	}
	else{
		newCharges -= payment;
	}
}


char menu();
void addCharge(CreditCard& card);
void generateStatement(CreditCard card);
void pay(CreditCard& card);
void input(CreditCard& card);

int main(){
	
	CreditCard card;
	char action;
	input(card);
	
	do{
		action = menu();
		switch(action){
			
			case 'A':
				addCharge(card);
				break;
			case 'G':
				generateStatement(card);
				break;
			case 'O':
				printToScreen(card);
				break;
			case 'P':
				pay(card);
				break;
			case 'Q':
				break;
		}
	}while(action != 'Q');
	
	
	return 0;
}


/*	
	Pre: card: reference to card instance in main

	Purpose: read credit card data from user and store it in card
	
	Post: return nothing
*/
void input(CreditCard& card){
	string cardNumber = "";
	double initialBalance = 0.0;
	double interestRate = 0.0;
	cout << "Enter credit card number: ";
	getline(cin, cardNumber);
	cout << "Enter initial balance: ";
	cin >> initialBalance;
	cout << "Enter interest rate: ";
	cin >> interestRate;
	card.setCardNumber(cardNumber);
	card.setPreviousBalance(initialBalance);
	card.setInterestRate(interestRate);
}


/*	
	Pre: no parameters

	Purpose: get menu option from user
	
	Post: return option
*/
char menu(){
	
	char ch;
	cout << "\n******************************" << endl;
	cout << "\n\t\tMenu" << endl;
	cout << endl;
	cout << "Enter A to add to new charges\n"<< endl;
	cout << "Enter G to generate statement\n"<< endl;
	cout << "Enter P to pay amount\n" << endl;
	cout << "Enter O to print to screen\n" << endl;
	cout << "Enter Q to quit\n" << endl;
	cout << "*******************************" << endl;
	cout << "\n\nPlease enter your choice: ";
	cin >> ch; cin.ignore();

	return toupper(ch);
}


/*	
	Pre: card: reference to card in main

	Purpose: ask user for a new charge and add it to card
	
	Post: return nothing
*/
void addCharge(CreditCard& card){
	
	double charge = 0;
	cout << "Enter new charge: ";
	cin >> charge;
	
	card.addNewCharge(charge);
	
}


/*	
	Pre: card: shadow copy of card in main

	Purpose: call the generate statement for the card
	
	Post: return nothing
*/
void generateStatement(CreditCard card){
	card.generateStatement();
}


/*	
	Pre: card: shadow copy of card in main

	Purpose: output the card information to user
	
	Post: return nothing
*/
void printToScreen(CreditCard card){
	
	cout << setprecision(1) << fixed << endl;
	cout << "Card number: " << card.cardNumber << endl;
	cout << "Previous Balance: " << card.previousBalance << endl;
	cout << "New charges: " << card.newCharges << endl;
	cout << "Interest rate: " << card.interestRate << endl;
	
}


/*	
	Pre: card: reference to card in main

	Purpose: ask user for payment and pay off that amount for the card
	
	Post: return nothing
*/
void pay(CreditCard& card){
	double amount = 0;
	card.generateStatement();
	cout << "Enter the amount you want to pay: ";
	cin >> amount;
	card.acceptPayment(amount);
}

/* Output

Enter credit card number: 123413241234112341
Enter initial balance: 400
Enter interest rate: 2.5

******************************

                Menu

Enter A to add to new charges

Enter G to generate statement

Enter P to pay amount

Enter O to print to screen

Enter Q to quit

*******************************


Please enter your choice: O

Card number: 123413241234112341
Previous Balance: 400.0
New charges: 0.0
Interest rate: 2.5
Destructing

******************************

                Menu

Enter A to add to new charges

Enter G to generate statement

Enter P to pay amount

Enter O to print to screen

Enter Q to quit

*******************************


Please enter your choice: G

Minimum Payment: 41.0
Amount Owed: 410.0
Destructing

******************************

                Menu

Enter A to add to new charges

Enter G to generate statement

Enter P to pay amount

Enter O to print to screen

Enter Q to quit

*******************************


Please enter your choice: P

Minimum Payment: 41.0
Amount Owed: 410.0
Enter the amount you want to pay: 41

******************************

                Menu

Enter A to add to new charges

Enter G to generate statement

Enter P to pay amount

Enter O to print to screen

Enter Q to quit

*******************************


Please enter your choice: O

Card number: 123413241234112341
Previous Balance: 359.0
New charges: 0.0
Interest rate: 2.5
Destructing

******************************

                Menu

Enter A to add to new charges

Enter G to generate statement

Enter P to pay amount

Enter O to print to screen

Enter Q to quit

*******************************


Please enter your choice: Q
Destructing


*/