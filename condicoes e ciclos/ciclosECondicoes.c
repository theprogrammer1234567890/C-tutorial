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

	if(option!=1 && option!=2 && option!=3)  {
		printf("This option does not exist\n");
		exit(-1);
	}

	printf("Insert the cycle duration\n");
	scanf("%d", &duration);

	if(option==1) {
		while(i<duration) {
			printf("Increment value = %d\n", i);
			i++;
		}
	}

	else if(option==2) {
		do {
			printf("Increment value = %d\n", i);
			i++;
		} while(i<duration);

	}
	else {
		for(i=0;i<duration;i++) {
			printf("Increment value = %d\n", i);
		}

	}
	

	return 0; /*ends the main function*/
}
