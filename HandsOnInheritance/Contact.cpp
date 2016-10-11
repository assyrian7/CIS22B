#include "Contact.h"

Contact::Contact(){
	name = "Paul";
	email = "badalien@cs.org";
}
Contact::Contact(string nom, string elecMail){
	name = nom; 
	email = elecMail;
}
string Contact::getName()const {
	return name;
}
string Contact::getEmail()const {
	return email;
}
void Contact::setName(string nomChange){
	name = nomChange;
}
void Contact::setEmail(string emailUpdate){
	email = emailUpdate;
}
string Contact::tostring()const {
	return name + " : " + email;
}