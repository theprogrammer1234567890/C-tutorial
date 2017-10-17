#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "main.h"

/*****************************************
*
*
* Edits a book with a choosen id
*******************************************/
void editBook() {

	char buffer[BUFFER_SIZE];
	book *base = myLibrary;
	int bookID=0;
	int isEdited=0;
	char newName[NAME_SIZE];
	char newAuthor[NAME_SIZE];
	char newType[NAME_SIZE];

	memset(buffer, '\0', BUFFER_SIZE);
	memset(newName, '\0', NAME_SIZE);
	memset(newAuthor, '\0', NAME_SIZE);
	memset(newType, '\0', NAME_SIZE);
	

	printf("Insert the book id:\n");
	fgets(buffer, BUFFER_SIZE, stdin);
	sscanf(buffer, "%d", &bookID);

	printf("Insert a new name for the book:\n");
	fgets(buffer, BUFFER_SIZE, stdin);
	/* the name is edited only if the user writes another name */
	if(buffer[0]!='\n' && buffer[0]!='\t') {
		sscanf(buffer, "%s", newName);
	}

	/* the author is edited only if the user writes another name */
	printf("Insert the author:\n");
	fgets(buffer, BUFFER_SIZE, stdin);
	if(buffer[0]!='\n' && buffer[0]!='\t') {
		sscanf(buffer, "%s", newAuthor);
	}

	/* the author is edited only if the user writes another name */
	printf("Insert the type:\n");
	fgets(buffer, BUFFER_SIZE, stdin);
	if(buffer[0]!='\n' && buffer[0]!='\t') {
		sscanf(buffer, "%s", newType);
	}

	/* This is not the best technique to do this, in future we will learn a better way */
	while(base!=NULL) {
		if(base->id==bookID) {
			if(strlen(newName)>0)
				strcpy(base->name, newName);

			if(strlen(newAuthor)>0)
				strcpy(base->author, newAuthor);

			if(strlen(newType)>0)
				strcpy(base->type, newType);
			isEdited=1;
		}

		base = base->next;
	}

	if(isEdited==0) 
		printf("There are no books with this id\n");

}

















