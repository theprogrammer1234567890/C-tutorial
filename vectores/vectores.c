#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 100
#define FIBONACCI_SEQUENCE_SIZE 10

/**************************************
*
* Fibonacci sequence. Introduce segmentation fault here.
****************************************/
void fibonacciSequence() {
 
	int fibonacciNumbers[FIBONACCI_SEQUENCE_SIZE];
	int i;	
	
	fibonacciNumbers[0]=0;
	fibonacciNumbers[1]=1;
	fibonacciNumbers[2]=1;

	for(i=3;i<FIBONACCI_SEQUENCE_SIZE;i++) {
		fibonacciNumbers[i]=fibonacciNumbers[i-1]+fibonacciNumbers[i-2];
	}

	for(i=0;i<FIBONACCI_SEQUENCE_SIZE;i++) {
		printf("%d\n", fibonacciNumbers[i]);
	}

}


void writeFile()  {

	FILE *fp; /*File pointer*/
	char buffer[BUFFER_SIZE];
	char writeData[BUFFER_SIZE];
	char fileName[50];
	
	memset(buffer, '\0', BUFFER_SIZE);
	printf("Insert the file name:\n");
	fgets(buffer, BUFFER_SIZE, stdin);
	sscanf(buffer, "%s", fileName);		


	fp=fopen(fileName, "w");
	if(fp==NULL) {
		printf("Error opening file %s\n", fileName);
		return;
	}
	
	printf("Write something to save in the file:\n");
	fgets(buffer, BUFFER_SIZE, stdin);
	sscanf(buffer, "%s", writeData);	

	fprintf(fp, "Testing fprintf:\n");
	fprintf(fp, "%s", writeData);

	fclose(fp);


}

/*****************************
*
*Reads a file. Receivs the file name as argument
*******************************/
void readFile() {

	FILE *fp; /*File pointer*/
	char buffer[BUFFER_SIZE];
	char fileName[50];
	
	memset(buffer, '\0', BUFFER_SIZE);
	printf("Insert the file name:\n");
	fgets(buffer, BUFFER_SIZE, stdin);
	sscanf(buffer, "%s", fileName);		


	fp=fopen(fileName, "r");
	if(fp==NULL) {
		printf("Error opening file %s\n", fileName);
		return;
	}
		
	while(fgets(buffer, BUFFER_SIZE, fp)!=NULL)  {
		printf("line = %s\n", buffer);
	}

	fclose(fp);

}

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

	char firstString[BUFFER_SIZE];
	char buffer[BUFFER_SIZE];
	
	memset(firstString, '\0', BUFFER_SIZE);	
	memset(buffer, '\0', BUFFER_SIZE);	
	printf("Insert string:\n");
	fgets(buffer, BUFFER_SIZE, stdin);
	sscanf(buffer, "%s", firstString);

	return strlen(firstString); /*ends the main function*/


}

/***********************************
*
*Validate string 
************************************/
int verifyString()  {

	char *firstString = "abcdefghi\0"; /*Unlike Java and C++, C needs a \0 in final of each string */
	char inputString[BUFFER_SIZE];
	char stringToCompare[BUFFER_SIZE];

	/* Initialize the vectors */
	memset(inputString, '\0', BUFFER_SIZE);	
	memset(stringToCompare, '\0', BUFFER_SIZE);

	printf("Insert any string\n");
	fgets(inputString, BUFFER_SIZE, stdin);
	sscanf(inputString, "%s", stringToCompare);

	return strcmp(stringToCompare, firstString); /*ends the main function*/

}

/***********************************
*
*Search character
************************************/
void searchCharacter()  {

	char firstString[BUFFER_SIZE]; /*Unlike Java and C++, C needs a \0 in final of each string */
	char buffer[BUFFER_SIZE];

	char *result;
	char character;
	
	memset(firstString, '\0', BUFFER_SIZE);	
	memset(buffer, '\0', BUFFER_SIZE);	
	printf("Insert string:\n");
	fgets(buffer, BUFFER_SIZE, stdin);
	sscanf(buffer, "%s", firstString);

	memset(buffer, '\0', BUFFER_SIZE);	
	printf("Choose character:\n");
	fgets(buffer, BUFFER_SIZE, stdin); 
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
	char buffer[BUFFER_SIZE];
	int a=11;
	int b=22;
	memset(buffer, '\0', BUFFER_SIZE);	
	
	printf("Select one of these options:\n");
	printf("1 - Search for a character in a string.\n");
	printf("2 - Verify if your string is correct.\n");
	printf("3 - Return your string length.\n");
	printf("4 - Pass arguments to a function by value.\n");
	printf("5 - Pass arguments to a function by reference.\n");
	printf("6 - Read a file and print the containing.\n");
	printf("7 - Write to a file.\n");
	printf("8 - Calculate fibonacci sequence.\n");

	fgets(buffer, BUFFER_SIZE, stdin);
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

	case 6:
		readFile();
		break;

	case 7:
		writeFile();
		break;

	case 8:
		fibonacciSequence();
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
