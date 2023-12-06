#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define min(a,b) (((a) < (b)) ? (a) : (b))
#define max(a,b) (((a) > (b)) ? (a) : (b))

// SET Functions

void hello();
double speedfunction();
int strengthfunction();
int combat();

int main(void)

{

// State The Variables

	double speed;
	int strength;
	int quit;
	srand(time(NULL));

// SET DO WHILE LOOP for reset of program

	do

	{

// Main Functions

		hello();
		speed = speedfunction();
		strength = strengthfunction();
		combat(speed, strength);

// SET Restart Variables

		printf("\nType 1 to quit or 2 to restart \n");
		scanf("%d", &quit);

		while (quit>=3 || quit<=0)

			{
				printf("\nThat was not 1 or 2, but I have nothing else left to show you :)\n");
				printf("\nType 1 to quit or 2 to restart\n");
				scanf("%d", &quit);
			}

	}

	while (quit==2);

	return 0;

}
//Welcome Function

void hello()
{
printf("\n Welcome to the Robot VS Human Fight simulator\n");
}

//Speed Function

double speedfunction()
{

// State The Variables

	double seconds;
	double distance;
	double speed;

// Gather INPUT

	printf("Please enter how many seconds it took for your robot to complete the race.\n");
	scanf("%lf", &seconds);

	while (seconds<=0)

		{
			printf("That input is invalid\n");
			printf("Please enter how many seconds it took for your robot to complete the race\n");
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
// DO MATH
	speed = distance / seconds;

	return speed;
}

//Strength Function

int strengthfunction()
{

//State Variables

	int strength;

// Gather INPUT

	printf("How many objects did your robot lift between 0-100?\n");
	scanf("%d", &strength);

	while (strength<0 || strength>100)

		{

			printf("You are lying!\n");
			printf("Please enter how many objects the robot lifted between 0-100\n");
			scanf("%d", &strength);

		}

	return strength;
}

int combat(double speed, int strength)
{

// State Variables

	int fight;
	int combatmin;
	int combatminvalue;
	int combatmax;
	int combatmaxvalue;
	int cont;
	int ai = 0;
	int human=0;
	int aifight;

//DO MATH

	combatmin = min(speed, 50)+strength/100*50-10;
	combatminvalue = max(combatmin, 0);
	combatmax = min(speed, 50)+strength/100*50+10;
	combatmaxvalue = min(combatmax, 100);

// Print Combat Chances

	printf("Your Robot has between %d%% and %d%% of winning. Good Luck!\n", combatminvalue , combatmaxvalue);
	printf("Please press 1 to continue the simulation\n" );
	scanf("%d", &cont);

// Set continue and LOOP

	while (cont != 1)

		{

			printf("Please follow the simulators instructions my dude.\n");
			printf("Please enter 1 to continue the simulation\n");
			scanf("%d", &cont);

		}

// Reset ai and human counts

	ai = 0;
	human = 0;

//  Create FOR Loop to generate RANDOM Fight determining winner and count number

	for (fight=1; fight<=100; fight++)

		{

			aifight = rand() % 100;

			if (aifight<=combatmaxvalue)
				{
					printf("ai win\n");
					ai++;
				}
			else
				{
					printf("human win\n");
					human++;
				}
		}

//PRINT RESULTS

	printf("The Robot won %d times and the hoomans won %d times!\n", ai, human);
	printf("Your speed score is %.0lf\n", max(speed, 1));
	printf("Your strength score is %d\n", max(strength, 1));
	printf("Your combat strength is %d\n", max(combatmax, 1));

return 0;
}
