#include <stdio.h> 
#include <stdlib.h>

/*********************************
*
*Variables and operators in C
***********************************/
int main ()  {

	float floatValue=97.3; 
	int intValue=97;
	char character='a';
	

	printf("int to char = %c\n", (char)intValue); /*int value converted to ascii character */
	printf("char to int = %d\n", (int)character); /*char ascii value */
	printf("float to int = %d\n", (int)floatValue); /*float to int*/
	printf("float to char = %c\n", (char)floatValue); /*float is rounded*/

	return 0; /*ends the main function*/
}
