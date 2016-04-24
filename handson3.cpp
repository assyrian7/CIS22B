#include <iostream>
#include <cstring>
#include <cctype>
#include <string>

char* deleteLastElement(char* str, int size);

using namespace std;

int main(){
	
	
	char firstName[81];
	
	cout << "Enter your first name: ";
	cin >> firstName;
	
	char* name = deleteLastElement(firstName, strlen(firstName));
	
	cout << name << endl;
	
	return 0;
}
char* deleteLastElement(char* str, int size){
	
	*(str + size - 1) = *(str + size);
	
	return str;
	
}