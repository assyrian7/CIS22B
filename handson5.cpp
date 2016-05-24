#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#define MAX 100

using namespace std;

class Account{
private:
	double balance;
	string client;
public:
	Account();
	Account(string, double);
	~Account(){
		//cout << "Destructing" << endl;
	} //inline
	double getBalance();
	string getClient() const;
	void setBalance(double);
	void setClient(string);
	void deposit(double);
	void withdraw(double);
};
Account::Account()
{
	//cout << "Default Constructor";
	client = "";
	balance = 0.0;
}
Account::Account(string person, double amt)
{
	client = person;
	balance = amt;
}
//*****get balance function ****/
double Account::getBalance()
{
	return balance;
}
//** get client's name ****/
string Account::getClient()const
{
	return client;
}

void Account::setBalance(double val)
{
	balance = val;

}

void Account::setClient(string name)
{
	client = name; 
}
void Account::deposit(double dep)
{
	if (dep > 0)
	balance += dep;
}
void Account::withdraw(double takeOut)
{
	 if (takeOut > 0)
		balance -= takeOut;
	else
		balance += takeOut;
}

int main(){
	
	double sum = 0;
	int max = 100;
	double balance;
	string client;
	int index = 0;
	ifstream infile("accountArray.txt");
	
	if(infile.fail()){
		cout << "Failed to open input file" << endl;
		return 1;
	}
	
	Account accounts[max];
	
	while(index < max && !infile.eof()){
		
		infile >> balance;
		getline(infile, client);
		client = client.substr(1);
		accounts[index].setBalance(balance);
		accounts[index].setClient(client);
		accounts[index].withdraw(25);
		sum += accounts[index].getBalance();
		
		index++;
	}
	
	index--;
	
	cout << setprecision(1) << fixed;
	
	for(int i = 0; i < index; i++){
		cout << "Client: " << left << setw(13) << accounts[i].getClient() << "Balance:" << right << setw(9) << accounts[i].getBalance() << endl;
	}
	
	cout << "Balance Sum: " << sum;
	
	return 0;
	
}
/* Output
Client: Hamdi        Balance:  99190.6
Client: Paul         Balance:  75089.0
Client: Zhongfu      Balance:  79440.3
Client: Jan          Balance:  64481.4
Client: Matthew      Balance:   2401.4
Client: Christopher  Balance:  58607.5
Client: Yosias       Balance:  49155.0
Client: Andrew       Balance:  93500.1
Balance Sum: 615365.5
*/
