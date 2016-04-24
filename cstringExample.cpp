#include <iostream>

using namespace std;

int stringLength(char* str);

int main(){
	
	//Comparing memory locations ordered in the stack
	char one[] = "more";  char two[] = "fun";
   
	if (one > two)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	
	char* name = "Paul";
	
	cout << stringLength(name) << endl;
	
	return 0;
}
int stringLength(char* str){
	
	int i = 0;
	while(*(str + i) != '\0'){
		cout << *(str + i);
		i++;
	}
	cout << endl;
	
	return i;
}