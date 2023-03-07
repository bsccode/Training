#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define min(a,b) (((a) < (b)) ? (a) : (b))
#define max(a,b) (((a) > (b)) ? (a) : (b))
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
	float best_score;
}Robot;

//Functions in use



double speedfunction (void);
void load_menu(void);
void CreateRobot(void);
void Read(void);
void SaveRobotInformation(void);
void SaveAllResults(void);
void DisplayWinners(void);
void DisplaySimulationResult(void);
void LoadRobotArray(void); 
int combat(double speed, int strength);
int strengthfunction();
double speedfunction(void);
int main(void)

{	double speed;
	int strength;
	srand(time(NULL));

	
// Define Variables

	load_menu();

// DO WHILE LOOP





return 0;
}

//Strength Function

int strengthfunction()
{
  int strength;
//State Variables

	

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



//Menu Functions

void load_menu(speed, strength)
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
            case 1: /*Search*/ ;
                break;
            case 2:  ;
                break;
            case 3:  combat ();
                break;
            case 4: DisplaySimulationResult ();
                break;
            case 5: DisplayWinners ();
                break;
            case 6: SaveRobotInformation ();
                break;
            case 7: SaveAllResults ();
                break;
            case 8:  printf("Quitting program!\n");
                     exit(0);
                break;
            default: printf("Invalid choice!\n");
                break;
        }

    } while (choice != 8);

}

void Write(Robot* lineup)
{
  FILE * fptr;
  int i,n;
  char str[100];
  char fname[20]="Robot.txt";
  char str1;
  
    printf("\n\n Create  Robot :\n");
	printf("------------------------------------------------------------\n");   
	printf(" Input the number of lines to be written : ");
	scanf("%d", &n);
	printf("\n :: The lines are ::\n");
	fptr = fopen (fname,"w"); 
	for(i = 0; i < n+1;i++)
		{
		fgets(str, sizeof str, stdin);
		fputs(str, fptr);
		}
  fclose (fptr);
}
	
void SaveRobotInformation(void)
{
  FILE * fptr;
  int i,n;
  char str[100];
  char fname[20]="Robot.txt";
  char str1;
  
    printf("\n\n You Have Saved Information :\n");
	printf("------------------------------------------------------------\n");   
	printf(" Input the number of lines to be written : ");
	scanf("%d", &n);
	printf("\n :: The lines are ::\n");
	fptr = fopen (fname,"w"); 
	for(i = 0; i < n+1;i++)
		{
		fgets(str, sizeof str, stdin);
		fputs(str, fptr);
		}
  fclose (fptr);
}

void SaveAllResults(void)
{
  FILE * fptr;
  int i,n;
  char str[100];
  char fname[20]="SaveAll.txt";
  char str1;
  
    printf("\n\n Save your resuklted :\n");
	printf("------------------------------------------------------------\n");   
	printf(" Input the number of lines to be written : ");
	scanf("%d", &n);
	printf("\n :: The lines are ::\n");
	fptr = fopen (fname,"w"); 
	for(i = 0; i < n+1;i++)
		{
		fgets(str, sizeof str, stdin);
		fputs(str, fptr);
		}
  fclose (fptr);
}

void DisplayWinners(void)
{
	FILE * fptr;
  int i,n;
  char str[100];
  char fname[20]="Winners.txt";
  char str1;
	
/*-------------- read the file -------------------------------------*/
	
	
	fptr = fopen (fname, "r");  
	printf("\n You Win %s is  :\n",fname);
	str1 = fgetc(fptr);
	while (str1 != EOF)
		{
			printf ("%c", str1);
			str1 = fgetc(fptr);
		}
    printf("\n\n");
    fclose (fptr);
   
}

void DisplaySimulationResult(void)
{
	FILE * fptr;
  int i,n;
  char str[100];
  char fname[20]="SimulationResult.txt";
  char str1;
	
/*-------------- read the file -------------------------------------*/
	
	
	fptr = fopen (fname, "r");  
	printf("\n You died lost %s is  :\n",fname);
	str1 = fgetc(fptr);
	while (str1 != EOF)
		{
			printf ("%c", str1);
			str1 = fgetc(fptr);
		}
    printf("\n\n");
    fclose (fptr);
   
}

void Read(void)
{
	FILE * fptr;
  int i,n;
  char str[100];
  char fname[20]="RobotArray.txt";
  char str1;
	
/*-------------- read the file -------------------------------------*/
	
	
	fptr = fopen (fname, "r");  
	printf("\n READ FILE %s is  :\n",fname);
	str1 = fgetc(fptr);
	while (str1 != EOF)
		{
			printf ("%c", str1);
			str1 = fgetc(fptr);
		}
    printf("\n\n");
    fclose (fptr);
   
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
	
		speed = speedfunction();
		strength = strengthfunction();

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