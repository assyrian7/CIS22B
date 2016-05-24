#include <iostream>
#include <cstring>
#define SIZE 30

using namespace std;
void transformPigLatin(char* word);
void mutate(char* str);
int main(){
	
	char first[SIZE];
	char last[SIZE]; 
	char whole[SIZE * 4];
	
	char quarter[] = " Spring 2016\n";
	//Person's first and last name is entered
	cout << "Enter first name: ";
	
	cin >> first;
	
	cout << "Enter last name: ";
	
	cin >> last;
	//Convert string to all upper characters
	for(int i = 0; i < strlen(first); i++){
		first[i] = toupper(first[i]);
	}
	
	for(int i = 0; i < strlen(last); i++){
		last[i] = toupper(last[i]);
	}
	//Each string is converted to pig latin
		
	transformPigLatin(first);
	
	strcpy(whole, first);
	
	transformPigLatin(last);
	
	strcat(whole, " ");
	
	strcat(whole, last);
	//Resulting name in pig latin is output
	
	cout << whole << endl;
	
	system("pause");
	
	return 0;
	
}

void transformPigLatin(char* word){ 

	/*Pre:
	word: reference to a string
	Post: Nothing
	Purpose: Takes a string of characters and converts to pig latin
	*/ 
	
	
	char vowel[] = "AEIOUY";// string constructor but could use vowel = "AEIOU"

	//Check if begins with vowel
	for (int i = 0; i < strlen(vowel); i++){
		if(*word == *(vowel + i)){
			
			strcat(word, "WAY"); 
			return;
		}
	}
	//string does not begin with a vowel
	
	//char* first = mutate(word);
	char nam[30];
	strcpy(nam, word);
	nam[1] = '\0';
	strcat(word, nam);
	strcat(word, "AY");
	mutate(word);
	
	return;
	
}
void mutate(char* str){
	
	/*Pre: str: pointer to a char
	
	 Purpose: delete the first char in char
	
	 Post: return nothing
	*/
	
	int size = strlen(str);
	
	char first = *str;
	
	for(int i = 0; i < size; i++){
		
		*(str + i) = *(str + i + 1);
	
	}
	
	
	
}

/* Output

Enter first name: aul
Enter last name: badal
AULWAY ADALBAY
Press any key to continue . . .

*/