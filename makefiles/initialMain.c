#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define BUFFER_SIZE 100
#define NAME_SIZE 30
#define LIBRARY_SIZE 200


/* Book structure */
typedef struct Book {

	char name[NAME_SIZE];
	char author[NAME_SIZE];
	char type[NAME_SIZE];
	time_t creationDate;
	int id;
}book;

/* Global vector */
book myLibrary[LIBRARY_SIZE];

/***********************************************
*
*
* Prints the structure
*******************************************************/
void printStructure() {

	int i=0;
	struct tm tm;

	/* This is not the best technique to do this, in future we will learn a better way */
	while(strlen(myLibrary[i].name)!=0) {
		printf("Name = %s\n", myLibrary[i].name);
		printf("Author = %s\n", myLibrary[i].author);
		printf("Type = %s\n", myLibrary[i].type);
		printf("Id = %d\n", myLibrary[i].id);
		tm = *localtime(&myLibrary[i].creationDate);
		printf("Creation date = %d-%d-%d %d:%d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min);
		i++;
		printf("--------------------------------------\n");
	}

}

/***************************************************
*
*
* Inserts the book on the structure
******************************************************/
void insertOnStructure(book newBook) {

	int i;
	int isFull=1;
	/* This is not efficient but we will learn a better form to do this */
	for(i=0;i<LIBRARY_SIZE;i++) {
		if(strlen(myLibrary[i].name)==0) {
			strcpy(myLibrary[i].name, newBook.name);
			strcpy(myLibrary[i].author, newBook.author);
			strcpy(myLibrary[i].type, newBook.type);
			myLibrary[i].creationDate=newBook.creationDate;
			myLibrary[i].id=newBook.id;
			isFull=0;
			break;
		}
			
	}
	if(isFull==1) 
		printf("Library is full\n");

}
/****************************************************
*
*
* Builds the book
****************************************************/
void insertNewBook() {

	book newBook;
	char buffer[BUFFER_SIZE];
	memset(buffer, '\0', BUFFER_SIZE);	

	printf("Insert the name of the book:\n");
	fgets(buffer, BUFFER_SIZE, stdin);
	sscanf(buffer, "%s", newBook.name);

	printf("Insert the id:\n");
	fgets(buffer, BUFFER_SIZE, stdin);
	sscanf(buffer, "%d", &newBook.id);

	printf("Insert the author:\n");
	fgets(buffer, BUFFER_SIZE, stdin);
	sscanf(buffer, "%s", newBook.author);

	printf("Insert the type:\n");
	fgets(buffer, BUFFER_SIZE, stdin);
	sscanf(buffer, "%s", newBook.type);

	newBook.creationDate = time(NULL);

	insertOnStructure(newBook);

}

/*********************************
*
*Main menu in C
***********************************/
void mainMenu(int argc, char *argv[]) {

	int option=0;
	char buffer[BUFFER_SIZE];
	int exit=1; /* exit variable */
	memset(myLibrary, '\0', LIBRARY_SIZE); /* global vector initialization */

	while(exit) {

		memset(buffer, '\0', BUFFER_SIZE);	
	
		printf("Select one of these options:\n");
		printf("0 - Exit the program.\n");
		printf("1 - Insert a new book.\n");
		printf("2 - Print the entire library.\n");
	
		fgets(buffer, BUFFER_SIZE, stdin);
		sscanf(buffer, "%d", &option);
	
	
		switch(option) {
		case 1:
			insertNewBook();
			break;
		case 2:
			printStructure();
			break;
		case 0:
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

	mainMenu(argc, argv);
	return 0;
}
