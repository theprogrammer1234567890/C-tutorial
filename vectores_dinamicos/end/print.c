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

