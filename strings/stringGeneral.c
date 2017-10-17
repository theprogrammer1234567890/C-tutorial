#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

/*********************************
*
*Strings in C
***********************************/
int main ()  {

	char firstString[10] = "abcdefghi\0"; /*Unlike Java and C++, C needs a \0 in final of each string */
	char secondString[13] = "ABC\0"; /*String to append other string */
	char inputString[20]; /* String to receive a copy */
	char *result;
	int size = strlen(firstString);
	char stringToCompare[20];

	result = strchr(firstString, 'c');
	printf("The character in the fourth position is %s\n", result);
	strcat(secondString, firstString);
	printf("secondString = %s\n", secondString);
	/* Initialize the vectors */
	memset(inputString, '\0', 20);	

	printf("String before the copy:\n");
	printf("%s\n", inputString);
	strcpy(inputString, firstString);
	printf("String after the copy:\n");
	printf("%s\n", inputString);
	printf("String length = %d\n", size);
	

	/* Initialize the vectors */
	memset(inputString, '\0', 20);	
	memset(stringToCompare, '\0', 20);

	printf("Insert any string\n");
	fgets(inputString, 20, stdin);
	sscanf(inputString, "%s", stringToCompare);

	if(strcmp(stringToCompare, firstString)==0) {
		printf("The strings are equal\n");
	}
	else {
		printf("The strings are different\n");
	}
	
	return 0; /*ends the main function*/
	
}
