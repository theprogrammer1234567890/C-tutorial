#include <stdio.h> 
#include <stdlib.h>
#include <string.h>


void passArgumentsByValue(int a, int b) {

	a=400;
	b=100;

}

void passArgumentsByReference(int *a, int *b) {

	*a=400;
	*b=100;

}
/***********************************
*
*Returns string length
************************************/
int returnStringLength()  {

	char firstString[100];
	char buffer[100];
	
	memset(firstString, '\0', 100);	
	memset(buffer, '\0', 100);	
	printf("Insert string:\n");
	fgets(buffer, 100, stdin);
	sscanf(buffer, "%s", firstString);

	return strlen(firstString); /*ends the main function*/


}

/***********************************
*
*Validate string 
************************************/
int verifyString()  {

	char *firstString = "abcdefghi\0"; /*Unlike Java and C++, C needs a \0 in final of each string */
	char inputString[100];
	char stringToCompare[100];

	/* Initialize the vectors */
	memset(inputString, '\0', 100);	
	memset(stringToCompare, '\0', 100);

	printf("Insert any string\n");
	fgets(inputString, 100, stdin);
	sscanf(inputString, "%s", stringToCompare);

	return strcmp(stringToCompare, firstString); /*ends the main function*/

}

/***********************************
*
*Search character
************************************/
void searchCharacter()  {

	char firstString[100]; /*Unlike Java and C++, C needs a \0 in final of each string */
	char buffer[100];

	char *result;
	char character;
	
	memset(firstString, '\0', 100);	
	memset(buffer, '\0', 100);	
	printf("Insert string:\n");
	fgets(buffer, 100, stdin);
	sscanf(buffer, "%s", firstString);

	memset(buffer, '\0', 100);	
	printf("Choose character:\n");
	fgets(buffer, 100, stdin); 
	sscanf(buffer, "%c", &character);
 
	result = strchr(firstString, character);
	printf("character string = %s\n", result);

}

/*********************************
*
*Main menu in C
***********************************/
void mainMenu() {

	int option=0;
	char buffer[100];
	int a=11;
	int b=22;
	memset(buffer, '\0', 100);	
	
	printf("Select one of these options:\n");
	printf("1 - Search for a character in a string.\n");
	printf("2 - Verify if your string is correct.\n");
	printf("3 - Return your string length.\n");
	printf("4 - Pass arguments to a function by value.\n");
	printf("5 - Pass arguments to a function by reference.\n");

	fgets(buffer, 100, stdin);
	sscanf(buffer, "%d", &option);
	
	switch(option) {
	case 1:
		searchCharacter();
		break;
	case 2:
		if(verifyString()==0)  {
			printf("String is correct\n");
		}
		else {
			printf("String is incorrect\n");
		}
		break;
	case 3:
		printf("String length = %d\n", returnStringLength());
		break;

	case 4:
		
		passArgumentsByValue(a, b);
		printf("a = %d, b = %d\n", a, b);
		break;

	case 5:
		
		passArgumentsByReference(&a, &b);
		printf("a = %d, b = %d\n", a, b);
		break;

	default:
		printf("This option does not exist\n");
		break;
	}

}

/*********************************
*
*Main function C
***********************************/
int main ()  {

	mainMenu();
	return 0;
}
