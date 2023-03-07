#include <stdio.h>


int main(void)
{

// State The Variables
	
	double seconds;
	double distance;
	double speed;
	int   quit;
	
// SET DO WHILE LOOP for reset calculations
	
	do
	
	{

// Ask For INPUT - Determine ERROR AND LOOP Boundaries
	
	printf("Please enter how many seconds it took for the competitor to complete the race\n");
	scanf("%lf", &seconds);	
	
	while (seconds<=0)
	
		{
			printf("You are lying!\n");
	
			printf("Please enter how many seconds it took for the competitor to complete the race\n");
			scanf("%lf", &seconds);
		
		}		
	
	printf("Please enter how many meters the race was completed over\n");	
	scanf("%lf", &distance);
	
	while (distance<=0)
	
		{
			printf("You are lying!\n");
			printf("Please enter how many meters the race was completed over\n");	
			scanf("%lf", &distance);
		}	
	
// Do MATH
	
	speed = distance / seconds;
	
// OUTPUT Result 2 DECIMAL places
	
	printf("Your competitor completed the race at an average of %.2lf meters per second\n", speed);
	printf("Congratulations that was pretty fast!\n");
	printf("\nType 1 to quit or 2 to restart \n");
	scanf("%d", &quit);
	
// INPUT QUIT and RESET parameters	
	
	while (quit>=3 || quit<=0)
	
		{
			printf("\nThat was not 1 or 2, but I have nothing else left to show you :)\n");
			printf("\nType 1 to quit or 2 to restart\n");	
			scanf("%d", &quit);
		}
		
	} while (quit==2);
	
	return 0;
}