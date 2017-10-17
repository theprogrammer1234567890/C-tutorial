#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "main.h"


/*********************************
*
*Main menu in C
***********************************/
void mainMenu(int argc, char *argv[]) {

	int option=0;
	char buffer[BUFFER_SIZE];
	int exit=1; /* exit variable */

	while(exit) {

		memset(buffer, '\0', BUFFER_SIZE);	
	
		printf("Select one of these options:\n");
		printf("0 - Exit the program.\n");
		printf("1 - Insert a new book.\n");
		printf("2 - Print the entire library.\n");
		printf("3 - Edit a book.\n");
		printf("4 - Delete a book.\n");
	
		fgets(buffer, BUFFER_SIZE, stdin);
		sscanf(buffer, "%d", &option);
	
	
		switch(option) {
		case 1:
			insertNewBook();
			break;
		case 2:
			printStructure();
			break;
		case 3:
			editBook();
			break;
		case 4:
			deleteBook();
			break;
		case 0:
			saveLibrary();
			freeObjects();
			exit=0;
			break;

		default:
			printf("This option does not exist\n");
			break;
		}
	}

}

/*********************************
*
*Main function C
***********************************/
int main (int argc, char *argv[])  {

	loadLibrary();
	mainMenu(argc, argv);
	return 0;
}

