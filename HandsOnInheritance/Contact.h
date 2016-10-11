#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <string>
using namespace std;

class Contact
{

	private:
		string name;
		string email;

	public:

		Contact();
		Contact(string nom, string elecMail);
		string getName() const;
		string getEmail() const;
		void setName(string nomChange);
		void setEmail(string emailUpdate);
		string tostring() const;

};
#endif

