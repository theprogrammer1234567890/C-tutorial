#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "main.h"

/***********************************************
*
*
* Prints the structure
*******************************************************/
void printStructure() {

	int i=0;
	book *base = myLibrary;
	struct tm tm;

	/* This is not the best technique to do this, in future we will learn a better way */
	while(base!=NULL) {
		printf("Name = %s\n", base->name);
		printf("Author = %s\n", base->author);
		printf("Type = %s\n", base->type);
		printf("Id = %d\n", base->id);
		tm = *localtime(&base->creationDate);
		printf("Creation date = %d-%d-%d %d:%d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min);
		printf("--------------------------------------\n");
		base = base->next;
	}

}

