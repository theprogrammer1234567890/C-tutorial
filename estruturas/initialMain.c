#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 100
#define FIBONACCI_SEQUENCE_SIZE 10

/****************************************************
*
*
* Builds and returns a book
****************************************************/


/*********************************
*
*Main menu in C
***********************************/
void mainMenu(int argc, char *argv[]) {

	int option=0;
	char buffer[BUFFER_SIZE];
	memset(buffer, '\0', BUFFER_SIZE);	
	
	printf("Select one of these options:\n");
	printf("1 - Search for a character in a string.\n");
	
	if(argc==1) {
		fgets(buffer, BUFFER_SIZE, stdin);
		sscanf(buffer, "%d", &option);
	}

	else {
		option=atoi(argv[1]); /*Atoi converts string to int */
	}
	
	switch(option) {
	case 1:
		/*searchCharacter(); */
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
int main (int argc, char *argv[])  {

	mainMenu(argc, argv);
	return 0;
}
