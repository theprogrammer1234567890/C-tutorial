#include <stdio.h> 
#include <stdlib.h>

/*********************************
*
*Hello world in C
***********************************/
int main ()  {

	int i=0;
	int option=0;
	int duration=0;
	
	printf("Select one of these options:\n");
	printf("1 - Select while cycle duration.\n");
	printf("2 - Select do while cycle duration.\n");
	printf("3 - Select for cycle duration.\n");

	scanf("%d", &option);
	
	switch(option) {
	case 1:
		printf("Insert the cycle duration\n");
		scanf("%d", &duration);
		while(i<duration) {
			printf("Increment value = %d\n", i);
			i++;
		}
		break;
	case 2:
		printf("Insert the cycle duration\n");
		scanf("%d", &duration);
		do {
			printf("Increment value = %d\n", i);
			i++;
		} while(i<duration);
		break;
	case 3:
		printf("Insert the cycle duration\n");
		scanf("%d", &duration);
		for(i=0;i<duration;i++) {
			printf("Increment value = %d\n", i);
		}
		break;

	default:
		printf("This option does not exist\n");
		break;
	}
	

	return 0; /*ends the main function*/
}
