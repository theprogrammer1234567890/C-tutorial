#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "main.h"

/*******************************
*
*
* Loads the library
*********************************/
void loadLibrary() {

	FILE *fp;
	char buffer[BUFFER_SIZE];
	char dataType[BUFFER_SIZE];
	book *loadedBook = (book *)malloc(sizeof(book));
	book *bookToInsert = myLibrary;

	memset(buffer, '\0', BUFFER_SIZE);	
	memset(dataType, '\0', BUFFER_SIZE);

	fp = fopen("library.txt", "r");
	
	while(fgets(buffer, BUFFER_SIZE, fp)!=NULL) {
		sscanf(buffer, "%s %*s", dataType);
		if(strcmp(dataType, "NAME:")==0) {
			
			sscanf(buffer, "%*s %s", loadedBook->name);
			
		}
		if(strcmp(dataType, "AUTHOR:")==0) {
			
			sscanf(buffer, "%*s %s", loadedBook->author);
			
		}
		if(strcmp(dataType, "TYPE:")==0) {
			
			sscanf(buffer, "%*s %s", loadedBook->type);
			
		}
		if(strcmp(dataType, "ID:")==0) {
			
			sscanf(buffer, "%*s %d", &loadedBook->id);
			
		}
		if(strcmp(dataType, "CREATION_DATE:")==0) {
			
			sscanf(buffer, "%*s %ld", &loadedBook->creationDate);
			
		}
		if(strcmp(dataType, "--------------------------------------")==0) {
			loadedBook->next=NULL;
			if(bookToInsert!=NULL) {
				while(bookToInsert->next!=NULL) 
					bookToInsert=bookToInsert->next;
				bookToInsert->next=loadedBook;
				bookToInsert->next->next=NULL;
				
			}
			else {
				myLibrary=loadedBook;
				bookToInsert = myLibrary;
				
			}
			loadedBook = (book *)malloc(sizeof(book));
			
		}
	}

	free(loadedBook);
	fclose(fp);
	
}

/*******************************
*
*
* Saves the library
*********************************/
void saveLibrary() {

	FILE *fp;
	char buffer[BUFFER_SIZE];

	fp = fopen("library.txt", "w");
	
	int i=0;
	book *base = myLibrary;
	struct tm tm;

	while(base!=NULL) {
		fprintf(fp, "NAME: %s\n", base->name);
		fprintf(fp, "AUTHOR: %s\n", base->author);
		fprintf(fp, "TYPE: %s\n", base->type);
		fprintf(fp, "ID: %d\n", base->id);
		fprintf(fp, "CREATION_DATE: %ld\n", base->creationDate);
		fprintf(fp, "--------------------------------------\n");
		base = base->next;
	}

	fclose(fp);
	
}

/*********************************
*
*
* Frees all objects
**************************************/
void freeObjects() {

	int i=0;
	book *base = myLibrary;
	book *objectToDelete;
	struct tm tm;

	while(base!=NULL) {
		objectToDelete = base;
		base = base->next;
		free(objectToDelete);
	}

}



