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



double speedfunction (void);
void load_menu(void);


int main(void)

{

	Robot lineup;
// Define Variables
int i;
char buf [1000];
//Menu
FILE * inputfile;

fopen ("RobotArray.txt", "r" );

while (fgets(buf,1000, inputfile)!=NULL)
printf("%s\n", buf);

	load_menu();
fclose(inputfile);

// DO WHILE LOOP





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



/* void PrintRobot (void)
{
	File* inputfile =fopen ("RobotArray.txt", )

}*/

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

//Menu Functions

void load_menu(void)
{
    int choice;

    do
    {
        printf("ROBOT WARS V.321\n\n");
        printf("1. Search Robot\n");
        printf("2. Update Robot Information\n");
        printf("3. Simulate Robot VS Human\n");
        printf("4. Display Simulation Results\n");
        printf("5. Display Winners\n");
        printf("6. Save Robot Information\n");
        printf("7. Save All Results\n");
        printf("8. Exit\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:  ;
                break;
            case 2:  ;
                break;
            case 3:  ;
                break;
            case 4:  ;
                break;
            case 5:  ;
                break;
            case 6:  ;
                break;
            case 7:  ;
                break;
            case 8:  printf("Quitting program!\n");
                     exit(0);
                break;
            default: printf("Invalid choice!\n");
                break;
        }

    } while (choice != 8);

}
