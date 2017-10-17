#include <stdio.h> 
#include <stdlib.h>

/*********************************
*
*Variables and operators in C
***********************************/
int main ()  {

	float dollarAmount=0; 
	int divAmount=0;
	char buffer[100];
	char alphabetSymbol='a';
	float euroAmount=0; 
	int divRest=0;

	/*Inserts by the user. The most correct way to inpput values is using fgets and sscanf, not scanf*/
	printf("Insert a letter to increment in alphabet:\n");
	fgets(buffer, 100, stdin);
	sscanf(buffer, "%c", &alphabetSymbol);
	printf("Insert a dollar amount to convert:\n"); 
	fgets(buffer, 100, stdin);
	sscanf(buffer, "%f", &dollarAmount);
	printf("Insert an integer to calculate the int division rest by 3:\n");
	scanf("%d", &divAmount);
	
	
	/* Operations*/
	euroAmount=dollarAmount*0.950123278;
	divRest=divAmount%3;
	alphabetSymbol=alphabetSymbol++;

	printf("Amount in euro = %.2f\n", euroAmount);
	printf("Div amount = %d\n", divRest);
	printf("Char symbol = %c\n", alphabetSymbol);

	return 0; /*ends the main function*/
}
