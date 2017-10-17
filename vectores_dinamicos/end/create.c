#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "main.h"

/***************************************************
*
*
* Inserts the book on the structure
******************************************************/
void insertOnStructure(book newBook) {

	int i;
	int isFull=1;
	int oldDinamicLibrarySize = LIBRARY_SIZE;
	/* This is not efficient but we will learn a better form to do this */
	for(i=0;i<dinamicLibrarySize-1;i++) {
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
	if(isFull==1) {
		
		dinamicLibrarySize = dinamicLibrarySize+LIBRARY_SIZE;
		printf("Library is full\n"); 
		myLibrary = (book *)realloc(myLibrary, dinamicLibrarySize*sizeof(book));
		for(i=oldDinamicLibrarySize;i<dinamicLibrarySize;i++) {
			printf("asddsdasdasdds = %d\n", myLibrary[i].id);
			memset(myLibrary[i].name, '\0', NAME_SIZE);
			memset(myLibrary[i].author, '\0', NAME_SIZE);
			memset(myLibrary[i].type, '\0', NAME_SIZE);
			myLibrary[i].id = 0;
		} 
		insertOnStructure(newBook);
	}

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

