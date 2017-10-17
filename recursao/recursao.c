#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 100

int factorialAlgorithm(int input);

int main() {

	char buffer[BUFFER_SIZE];
	int input=0;

	memset(buffer, '\0', BUFFER_SIZE);

	printf("Insert the number:\n");
	fgets(buffer, BUFFER_SIZE, stdin);
	sscanf(buffer, "%d", &input);

	printf("result = %d\n", factorialAlgorithm(input));

	return 0;
}



/**********************************
*
*
* Factorial algorithm
*****************************************/
int factorialAlgorithm(int input) {

	int secondinput = input-1;

	if(input>1)
		return input*factorialAlgorithm(secondinput);

	else 
		return input;


}
