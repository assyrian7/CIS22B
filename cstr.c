#include <stdio.h>
#include <string.h>

int getLen(char*);

int main(void){
	
	char* name = "Paul";
	
	printf("%d", getLen(name));
	//printf("%d", strlen(name));
}

int getLen(char* str){
	
	int i = 0;
	while(*(str + i) != '\0'){
		printf("%c", *(str + i));
		i++;
	}
	printf("%c", '\n');
	
	return i;
}