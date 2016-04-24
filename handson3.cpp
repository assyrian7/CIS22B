#include <iostream>
#include <cstring>
#include <cctype>
#include <string>

char* deleteLastElement(char* str, int size);

using namespace std;

int main(){
	
	
	string input;
	int size;
	
	cout << "Enter your name: ";
	getline(cin, input);
	
	size = strlen(input.c_str());
	
	char* name = deleteLastElement(input.c_str(), size);
	
	for(int i = 0; i < size; i++){
		cout << *(name + i);
	}
	cout << endl;
	
	return 0;
}
char* deleteLastElement(char* str, int size){
	
	*(str + size - 1) = *(str + size);
	
	return str;
	
}