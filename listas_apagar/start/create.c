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
void insertOnStructure(book *newBook) {

	book *myNewObject = myLibrary;
	if(myNewObject==NULL) {
		myLibrary = newBook;	
	}
	else {
		while(myNewObject->next!=NULL) {
			myNewObject = myNewObject->next;
		}
		myNewObject->next = newBook;
	}
}
/****************************************************
*
*
* Builds the book
****************************************************/
void insertNewBook() {

	book *newBook = (book *)malloc(sizeof(book));
	char buffer[BUFFER_SIZE];
	memset(buffer, '\0', BUFFER_SIZE);	

	printf("Insert the name of the book:\n");
	fgets(buffer, BUFFER_SIZE, stdin);
	sscanf(buffer, "%s", newBook->name);

	printf("Insert the id:\n");
	fgets(buffer, BUFFER_SIZE, stdin);
	sscanf(buffer, "%d", &newBook->id);

	printf("Insert the author:\n");
	fgets(buffer, BUFFER_SIZE, stdin);
	sscanf(buffer, "%s", newBook->author);

	printf("Insert the type:\n");
	fgets(buffer, BUFFER_SIZE, stdin);
	sscanf(buffer, "%s", newBook->type);

	newBook->creationDate = time(NULL);

	insertOnStructure(newBook);

}

