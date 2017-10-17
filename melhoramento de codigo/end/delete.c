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
void deleteBook() {

	char buffer[BUFFER_SIZE];
	book *base = myLibrary;
	book *backBase = NULL;
	int bookID=0;
	int findBook=0;

	memset(buffer, '\0', BUFFER_SIZE);

	printf("Insert the book id:\n");
	fgets(buffer, BUFFER_SIZE, stdin);
	sscanf(buffer, "%d", &bookID);

	while(base!=NULL) {
		if(base->id==bookID) {
			findBook=1;
			if(backBase!=NULL) 
				backBase->next = base->next;
				
			else 
				myLibrary=base->next;
			free(base); /* Deletes the book */
		}

		backBase = base;
		base = base->next;
	}

	if(findBook==0)
		printf("There are no books with this id\n");

}
