#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// define custom types for use in program
typedef char robotname [30];
typedef int	 robotnumber;
typedef	double speed;
typedef double weight;

// Create ROBOT Struct

typedef struct Robot
{
	robotnumber number;
	robotname name;
	int year;
	speed trial;
	weight  mass;
}Robot;

//Functions in use

void PrintRobot (struct Robot lineup);
void CreateRobot (Robot* lineup);
double speedfunction (void);

int main(void)

{
// Define Variables	

	double speed;
	int quit;
	int build;
	int i;
	int robotnumber=0;
	Robot lineup[50];
	Robot  *p;
	p = &lineup[robotnumber+5];	

 // Defining Array
 
	lineup[robotnumber]= (Robot) {1, "AdamTheLink", 1999, 15, 110 };
	lineup[robotnumber+1]= (Robot) {2, "BrainAT", 2010, 32.5, 18 };
	lineup[robotnumber+2]= (Robot) {3, "BOBBY", 2013, 29.5, 7.5 };
	lineup[robotnumber+3]= (Robot) {4, "MiMi", 2018, 40, 8.8 };
	lineup[robotnumber+4]= (Robot) {5, "Dannielle", 2020, 80, 50 };
	
// DO WHILE LOOP	
	
	do
	{
		printf("\nThe following is the list of robots that could be used for the robotics competition!\n");
		printf("\nRobot | Name  |  Year  |  Top Speed(m/s)  |  Weight (kg)|\n");
		for(i=0; i<=4; i++)
		PrintRobot(lineup[i]);
		printf("\nWould you like to create a custom robot for the competition?\n");
		printf("\nPress 1 for yes, any other number to continue onto the trial.\n");
		scanf("%d", &build);

//CREATE ROBOT Function		

		if(build==1)
			{ 	
				CreateRobot(p);
			}
		else;
		
			speed = speedfunction();
			printf("\n Your trial speed is %lf\n", speed);
			printf ("\nRobots capable of being used for a robotics competition with this trial speed are: \n");
			printf("\nRobot | Name  |  Year  |  Top Speed(m/s)  |  Weight (kg)|\n");	

// Split Functions due to difficulties of printing array if no robot added by user

		if(build==1)
			{
				for(i=0; i<=5; i++) 
				if (speed <= lineup[i].trial)
		 
				{
					PrintRobot(lineup[i]);
				}
			
			
			}
		
		else 
		
			for(i=0; i<=4; i++) 
			if (speed <= lineup[i].trial)
		 
			{
				PrintRobot(lineup[i]);
			}
		
		printf("\nType 1 to quit or 2 to restart \n");
		scanf("%d", &quit);
		while (quit>=3 || quit<=0)
        
		{
			printf("\nThat was not 1 or 2, but I have nothing else left to show you :)\n");
			printf("\nType 1 to quit or 2 to restart\n");
			scanf("%d", &quit);
		}
	} while (quit==2);




return 0;
}

// Speed Function

double speedfunction(void)
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

//Print Robot Function

void PrintRobot (struct Robot lineup )
{	
	printf("-------------------------------------------------------------------------------------");
	printf ("\n| %d | %s | %d | %.2lf | %.2lf |\n", lineup.number, lineup.name, lineup.year, lineup.trial, lineup.mass); 
}

//Create Robot Function

void CreateRobot (Robot* lineup)
{ 
	printf("Please enter the Number Identifier of your Robot.\n");
	scanf("%d", &(lineup->number));
	printf("Please enter the Name of your Robot.\n");
	scanf("%30s", &(lineup->name));
	printf("Please enter the Year of Manufacture of your Robot.\n");
	scanf("%d", &(lineup->year));
	printf("Please enter the Speed score (m/s) of your Robot.\n");
	scanf("%lf", &(lineup->trial));
	printf("Please enter the Weight (kg) of your Robot.\n");
	scanf("%lf", &(lineup->mass));
	printf("\nRobot Successfully entered into database\n");
}