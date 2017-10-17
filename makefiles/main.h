#ifndef HEADER_FILE
#define HEADER_FILE

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

void insertNewBook();
void insertOnStructure(book newBook);
void printStructure();

#endif
