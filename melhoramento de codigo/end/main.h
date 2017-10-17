#ifndef HEADER_FILE
#define HEADER_FILE

#define BUFFER_SIZE 100
#define NAME_SIZE 30


/* Book structure */
typedef struct Book {

	char name[NAME_SIZE];
	char author[NAME_SIZE];
	char type[NAME_SIZE];
	time_t creationDate;
	int id;
	struct Book *next;
}book;

/* Global vector */
book *myLibrary;
int dinamicLibrarySize;


void insertNewBook();
void insertOnStructure(book *newBook);
void printStructure();
void editBook();
void deleteBook();
void loadLibrary();
void saveLibrary();

#endif
