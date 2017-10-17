#include <stdio.h> 
#include <stdlib.h>
#define ANY_NAME_CHAR_CONSTANT 'a'
#define ANY_NAME_INT_CONSTANT 12345

/*********************************
*
*Constants in C
***********************************/
int main ()  {

	char character = ANY_NAME_CHAR_CONSTANT;
	int integer = ANY_NAME_INT_CONSTANT;
	
	printf("constant name = %c\n", character);
	printf("constant name = %d\n", integer);
	return 0;
}
