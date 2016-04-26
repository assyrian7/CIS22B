#include <iostream>
#include <cstring>
#include <cctype>

char* deleteLastElement(char* str, int size);

using namespace std;

int main(){
	
	
	char firstName[81];
	
	cout << "Enter your family name: ";
	cin >> firstName;
	
	char* name = deleteLastElement(firstName, strlen(firstName));
	
	cout << name << endl;
	
	return 0;
}
char* deleteLastElement(char* str, int size){
	/*Pre: str: pointer to a char
		   size: size of the cstring
	
	 Purpose: Delete the last character of str
	
	 Post: return the changed str
	*/
	*(str + size - 1) = *(str + size);
	
	return str;
	
}
/* Output

Enter your family name: Badalian
Badalia

*/