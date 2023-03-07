// Inclusions and Definitions //

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define min(a,b) (((a) < (b)) ? (a) : (b))
#define max(a,b) (((a) > (b)) ? (a) : (b))

// Type Definitions //

typedef char robotname [30];
typedef int	 robotnumber;
typedef	double speed;
typedef double weight;

// Create Robot and TestResults Structs//

typedef struct Robot

{
	robotnumber number;
	robotname name;
	int year;
	speed trial;
	weight  mass;
	double best_score;
}Robot;

typedef struct TestResults

{	
	robotnumber number;
	robotname name;
	int year;
	speed trial;
	weight  mass;
	double best_score;
	int testnumber;
	double speed_score;
	double finish_line_distance;
	double finish_line_time;
	double strength;
	double combat_effectiveness;
}TestResults;

// Functions Which Are In Use For Program

void load_menu(void);
double combat(Robot* lineup, TestResults* test);
void DisplaySimulationResult(void);
void CreateRobot(Robot* lineup);
void PrintRobot(Robot lineup);
void PrintRobot2(Robot lineup);
int SearchRobot(int RobotSearch, Robot* lineup, int TotalRobot);
void SaveRobotInformation(Robot lineup);
void DisplayWinners (TestResults* test[]);
void SaveAllRobotInformation(TestResults* test);

// Main Program //

int main(void)

{
	load_menu ();
	return 0;
}

//Menu Functions

void load_menu(void)

{

//Create Array for Robot struct and lineup
	
    Robot lineup[10];

	lineup[0]= (Robot) {0, "Max", 2005, 16, 18, 66};
	lineup[1]= (Robot) {1, "Luciile", 2088, 50, 66, 11};
	lineup[2]= (Robot) {2, "Mouse", 2090, 100, 12, 22};
	lineup[3]= (Robot) {3, "Rob", 2018, 90, 1, 88};
	lineup[4]= (Robot) {4, "Jitian", 2020, 45, 50, 32};

	TestResults *r;
	Robot *p;
	int choice;
	int RobotSearch=0;
	int i, TotalRobot = 5 ;
	int m;
	int t=0;
	TestResults test [10];



// Welcome the User
	
	printf("\nAll Robot information:\n");
	printf("\n Robot-Id |    Name     | Year |Speed | Weight| Combat Score\n");
    printf("----------+-------------+------+------+-------+---------------\n");
	for (i=0; i<TotalRobot; i++)
	PrintRobot2(lineup[i]);
	printf("There are a total of %d Robots in the competition!\n\n", TotalRobot);

	do
    
	{
        printf("\nWelcome to ROBOT WARS V.321\n\n");
        printf("1. Search Robot\n");
        printf("2. Update Robot Information\n");
        printf("3. Simulate Robot VS Human\n");
        printf("4. Display Latest Simulation Results\n");
        printf("5. Display Winners\n");
        printf("6. Save Robot Information\n");
        printf("7. Save All Results\n");
        printf("8. Display All Current Robots\n");
		printf("9. Exit\n");
        scanf("%d",&choice);



        	switch(choice)
        	{
            	case 1:  

						printf("Please print the identifying number of the robot you wish to search for:\n");
						scanf("%d", &RobotSearch);
							if 
								(RobotSearch == TotalRobot);
							else 
								{SearchRobot(RobotSearch, lineup, TotalRobot);
								printf("%s was found\n\n", lineup[RobotSearch].name);
                		break;}
			
				case 2:
						p = &lineup[TotalRobot];
						CreateRobot(p);
						lineup[i].number=TotalRobot;
						TotalRobot++;
						printf("\nRobot information has been updated!\n\n");
                		break;
            
				case 3:
						printf("\nPlease choose the Robot I.D.\n");
						scanf("%d", &m);
						printf("\nRobot Number: = %d", lineup[m].number);
						printf("\nName: %s", lineup[m].name);
						printf("\nYear: %d", lineup[m].year);
						printf("\nSpeed: %.2lf", lineup[m].trial);
						printf("\nWeight: %6.2lf", lineup[m].mass);
						printf("\nBest Score: %6.2lf\n\n", lineup[m].best_score);
						r = &test[t];
						t++;
						combat(&lineup[m],r);
                break;
            	
				case 4: DisplaySimulationResult();
                
				break;
            	
				case 5:
						printf("\nFeature not currently available\n");
//						for (o=0; o<t; o++)
//						DisplayWinners(lineup[m], test[o]) ;
					
                break;
            
				case 6: 
						printf("\nthe following data is to be written into the file 'Robot.txt'\n");
						printf("\nAll Robot information:\n");
						printf(" Robot-Id |    Name     | Year |Speed | Weight| Combat Score\n");
    					printf("----------+-------------+------+------+-------+-------------\n");
						for (i=0; i<TotalRobot; i++)
						SaveRobotInformation(lineup[i]);
                break;

			    case 7: printf("\nFeature not currently available\n");
			
							/*Open File For Writing
							FILE* file3 = fopen("Results.txt", "w");
							if(file == NULL)
							{
								printf("ERROR! the file failed to open\n");
								exit(-1);
							}
								printf(" ");
								fclose(file3);

								for (i=0; i<t; i++)
					 				{ test[i];
							


								//open a file for writing
								FILE* file3 = fopen("Results.txt", "a");
								if(file3 == NULL)
								{
									printf("ERROR! the file failed to open\n");
									exit(-1);
								}

//Print Array


						printf("|%-9d|", test->number);
						printf("%-13s|", test->name);
						printf("%-6d|", test->year);
						printf("%-6lf|", test->trial);
						printf("%-7.2lf|", test->mass);
						printf("%6.2lf     |\n", test->best_score);
						printf("|%-9d|", test->testnumber);
						printf("%-13lf|", test->speed_score);
						printf("%-6lf|", test->finish_line_distance);
						printf("%-6lf|", test->finish_line_time);
						printf("%-7.2lf|", test->strength);
						printf("%6.2lf     |\n", test->combat_effectiveness);
						printf("----------+-------------+------+------+-------+------------\n");

						fprintf(file3,"|%-9d|", test->number);
						fprintf(file3,"%-13s|", test->name);
						fprintf(file3,"%-6d|", test->year);
						fprintf(file3,"%-6lf|", test->trial);
						fprintf(file3,"%-7.2lf|", test->mass);
						fprintf(file3,"%6.2lf     |\n", test->best_score);
						fprintf(file3,"|%-9d|", test->testnumber);
						fprintf(file3,"%-13lf|", test->speed_score);
						fprintf(file3,"%-6lf|", test->finish_line_distance);
						fprintf(file3,"%-6lf|", test->finish_line_time);
						fprintf(file3,"%-7.2lf|", test->strength);
						fprintf(file3,"%6.2lf     |\n", test->combat_effectiveness);
						fprintf(file3,"----------+-------------+------+------+-------+------------\n");


// Close the file
						fclose(file3);

						};*/
                break;
				
				case 8:

						printf("\nAll Robot information:\n");
						printf("\nRobot-Id |    Name     | Year |Speed | Weight| Combat Score\n");
    					printf("----------+-------------+------+------+-------+-------------\n");

						for (i=0; i<TotalRobot; i++)
					 		{
								PrintRobot2(lineup[i]);

							};
                break;
            	
				case 9:  printf("Quitting program!\n");
                    	 exit(0);
                break;
            	
				default: printf("Invalid choice!\n");
                
				break;
      		  }

    } while (choice != 9);

}


// Robot Creation Function

void CreateRobot(Robot *lineup) 
	{
	
	printf("Please enter the Name of your Robot.\n");
	scanf("%30s", &(lineup->name));
	printf("Please enter the Year of Manufacture of your Robot.\n");
	scanf("%4d", &(lineup->year));
	printf("Please enter the Speed score (m/s) of your Robot.\n");
	scanf("%6lf", &(lineup->trial));
	printf("Please enter the Weight (kg) of your Robot.\n");
	scanf("%6lf", &(lineup->mass));
	printf("Please Enter the Best Score your Robot has achieved\n");
	scanf("%6lf", &(lineup->best_score));
	printf("\nRobot Successfully entered into database\n");
	
	}

double combat(Robot* lineup, TestResults* test)
	{

// Open File

	FILE * fptr;
//	int i;
	char str[100];
	char fname[20]="FightResult.txt";
	fptr = fopen (fname,"w");

// State Variables


	
	double strength;
    double speed;
	int fight;
	double combatmax;
	double combatmaxvalue;
	int cont;
	int ai = 0;
	int human=0;
	double aifight;
	int TrueFight;
	
//While Statement


	printf("\nYou have chosen %s\n", lineup->name);

	printf("Please enter how many seconds it took for your robot to complete the race.\n");
	scanf("%lf", &test->finish_line_time);

	while (test->finish_line_time<=0)

		{
			printf("That input is invalid\n");
			printf("Please enter how many seconds it took for your robot to complete the race\n");
			scanf("%lf", &test->finish_line_time);

		}

	printf("Please enter how many meters the race was completed over\n");
	scanf("%lf", &test->finish_line_distance);

	while (test->finish_line_distance<=0)

		{

			printf("You are lying!\n");
			printf("Please enter how many meters the race was completed over\n");
			scanf("%lf", &test->finish_line_distance);

		}

// DO MATH
	
			speed = (test->finish_line_distance) / (test->finish_line_time);

// Gather INPUT

	printf("How many objects did your robot lift between 0-100?\n");
	scanf("%lf", &test->strength);
	

	while (test->strength<0 || test->strength>100)

		{

			printf("You are lying!\n");
			printf("Please enter how many objects the robot lifted between 0-100\n");
			scanf("%lf", &test->strength);

		}

//DO MATH	
	
	combatmax = min(speed, 50)+strength/100*50+10;
	test->combat_effectiveness = min(combatmax, 100);

// Print Combat Chances
	
	printf("Your Robot has a Combat Value of %lf\n",test->combat_effectiveness);
	printf("Would you like to use this value or your robots original best score of %lf\n", lineup->best_score);
	printf("Please enter 1 to use your robots original best score, otherwise enter any other whole number.\n");
	scanf("%d",&TrueFight);
	
	if (TrueFight!=1)
		{
			printf("Your Robot has %.2lf%% of winning. Good Luck!\n", test->combat_effectiveness);
		}
	
	else 
	
		printf("Your Robot has %.2lf%% of winning. Good Luck!\n", lineup->best_score);
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
	if (TrueFight!=1)
	
	{
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
	}
	
	else
			for (fight=1; fight<=100; fight++)

				{

					aifight = rand() % 100;

			if	(aifight<=lineup->best_score)
				
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
	
	test->speed_score=lineup->trial;

// Print Results
	
	printf("\n-----------------------------------------");
	printf("\nRobot Number:  %d", lineup->number);
	printf("\n-----------------------------------------");
	printf("\nName: %s", lineup->name);
	printf("\n-----------------------------------------");
	printf("\nYear: %d", lineup->year);
	printf("\n-----------------------------------------");
	printf("\nSpeed: %.2lf",lineup->trial );
	printf("\n-----------------------------------------");
	printf("\nWeight: %6.2lf", lineup->mass);
	printf("\n-----------------------------------------");
	printf("\nBest Score: %6.2lf", lineup->best_score);
	printf("\n-----------------------------------------");
	printf("\nDistance: %.2lf", test->finish_line_distance);
	printf("\n-----------------------------------------");
	printf("\nTime: %.2lf", test->finish_line_time);
	printf("\n-----------------------------------------");
	printf("\nStrength Score: %.2lf", test->strength);
	printf("\n-----------------------------------------");
	printf("\nCombat Score: %.2lf", test->combat_effectiveness);
	printf("\n-----------------------------------------");
	
//PRINT RESULTS

	printf("\n\nThe Robot won %d times and the Human competitor won %d times!\n", ai, human);
	printf("Your speed score is %.2lf\n", max(lineup->trial, 1));
	printf("Your strength score is %.2lf\n", max(test->strength, 1));
	printf("Your combat strength is %.2lf\n", max(test->combat_effectiveness, 1));

		fgets(str, sizeof str, stdin);
		fputs(str, fptr);

	fprintf(fptr,"\n-----------------------------------------");
	fprintf(fptr,"\nRobot Number:  %d", lineup->number);
	fprintf(fptr,"\n-----------------------------------------");
	fprintf(fptr,"\nName: %s", lineup->name);
	fprintf(fptr,"\n-----------------------------------------");
	fprintf(fptr,"\nYear: %d", lineup->year);
	fprintf(fptr,"\n-----------------------------------------");
	fprintf(fptr,"\nSpeed: %.2lf", lineup->trial);
	fprintf(fptr,"\n-----------------------------------------");
	fprintf(fptr,"\nWeight: %6.2lf", lineup->mass);
	fprintf(fptr,"\n-----------------------------------------");
	fprintf(fptr,"\nBest Score: %6.2lf", lineup->best_score);
	fprintf(fptr,"\n-----------------------------------------");
	fprintf(fptr,"\nDistance: %.2lf", test->finish_line_distance);
	fprintf(fptr,"\n-----------------------------------------");
	fprintf(fptr,"\nTime: %.2lf", test->finish_line_time);
	fprintf(fptr,"\n-----------------------------------------");
	fprintf(fptr,"\nStrength Score: %.2lf", test->strength);
	fprintf(fptr,"\n-----------------------------------------");
	fprintf(fptr,"\nCombat Score: %.2lf", test->combat_effectiveness);
	fprintf(fptr,"\n-----------------------------------------");
	fprintf(fptr,"\nThe Robot won %d times and the hoomans won %d times!\n", ai, human);
	fprintf(fptr,"Your speed score is %.0lf\n", max(lineup->trial, 1));
	fprintf(fptr,"Your strength score is %.2lf\n", max(test->strength, 1));
	fprintf(fptr,"Your combat strength is %.2lf\n", max(test->combat_effectiveness, 1));
	
//	for ( i = 0; i < 6; i++)
//	test[i]=lineup[i];
	
	fclose (fptr);

	return combatmax;
}

void DisplaySimulationResult(void)
{
	FILE * fptr;

  	char fname[20]="FightResult.txt";
  	char str1;

//Read File


	fptr = fopen (fname, "r");
	printf("\n The latest test results from %s are  :\n",fname);
	str1 = fgetc(fptr);
	
	while (str1 != EOF)
			{
				printf ("%c", str1);
				str1 = fgetc(fptr);
			}
    printf("\n\n");
    fclose (fptr);
return ;
}

void PrintRobot(Robot lineup)
		{

	printf("\nRobot Number: = %d", lineup.number);
	printf("\nName: %s", lineup.name);
	printf("\nYear: %d", lineup.year);
	printf("\nSpeed: %.2lf", lineup.trial);
	printf("\nWeight: %6.2lf", lineup.mass);
	printf("\nBest Score: %6.2lf\n\n", lineup.best_score);
		}

void PrintRobot2(Robot lineup)
		{

	printf("|%-9d|", lineup.number);
	printf("%-13s|", lineup.name);
	printf("%-6d|", lineup.year);
	printf("%-6.2lf|", lineup.trial);
	printf("%-7.2lf|", lineup.mass);
	printf("%6.2lf     |\n", lineup.best_score);
	printf("----------+-------------+------+------+-------+------------\n");
		}




int SearchRobot(int RobotSearch, Robot *lineup, int TotalRobot)
		{


			int i, count=0;
			if (TotalRobot<=0)
				return 0;
		
			for (i=0; i<TotalRobot; i++) 	
				
				{
			
			if(lineup[i].number == RobotSearch)
					 {
		
						printf(" Robot-Id |    Name     | Year |Speed | Weight| Combat Score\n");
    	
						printf("----------+-------------+------+------+-------+-------------\n");
			
						PrintRobot2(lineup[i]);
					 	count++;
					 }
				}
	return count;
}

void SaveRobotInformation(Robot lineup)
  	{
//Open File
		FILE* file4 = fopen("Robot.txt", "a");
		
		if(file4 == NULL)
		{
			printf("ERROR! the file failed to open\n");
			exit(-1);
		}

//Print Array
   
	
	printf("|%-9d|", lineup.number); 
	printf("%-13s|", lineup.name);
	printf("%-6d|", lineup.year);
	printf("%-6.2lf|", lineup.trial);
	printf("%-7.2lf|", lineup.mass);
	printf("%6.2lf     |\n", lineup.best_score);
	printf("----------+-------------+------+------+-------+------------\n");
	
//Print To FIle
	
	fprintf(file4,"|%-9d|", lineup.number); 
	fprintf(file4,"%-13s|", lineup.name);
	fprintf(file4,"%-6d|", lineup.year);
	fprintf(file4,"%-6.2lf|", lineup.trial);
	fprintf(file4,"%-7.2lf|", lineup.mass);
	fprintf(file4,"%6.2lf     |\n", lineup.best_score);
	fprintf(file4,"----------+-------------+------+------+-------+------------\n");
		
	
//Close file
	
	fclose(file4);
return ;
	
	
}

// Works on Functions which I was not able to implement correctly.

/*void SaveAllRobotInformation(TestResults* test)
  {


	int i=0;


	//open a file for writing
	FILE* file = fopen("Results.txt", "a");
	if(file == NULL)
	{
		printf("ERROR! the file failed to open\n");
		exit(-1);
	}

	//print student info to file


	printf("|%-9d|", test->number);
	printf("%-13s|", test->name);
	printf("%-6d|", test->year);
	printf("%-6lf|", test->trial);
	printf("%-7.2lf|", test->mass);
	printf("%6.2lf     |\n", test->best_score);
	printf("|%-9d|", test->testnumber);
	printf("%-13lf|", test->speed_score);
	printf("%-6lf|", test->finish_line_distance);
	printf("%-6lf|", test->finish_line_time);
	printf("%-7.2lf|", test->strength);
	printf("%6.2lf     |\n", test->combat_effectiveness);
	printf("----------+-------------+------+------+-------+------------\n");

	fprintf(file,"|%-9d|", test->number);
	fprintf(file,"%-13s|", test->name);
	fprintf(file,"%-6d|", test->year);
	fprintf(file,"%-6lf|", test->trial);
	fprintf(file,"%-7.2lf|", test->mass);
	fprintf(file,"%6.2lf     |\n", test->best_score);
	fprintf(file,"|%-9d|", test->testnumber);
	fprintf(file,"%-13lf|", test->speed_score);
	fprintf(file,"%-6lf|", test->finish_line_distance);
	fprintf(file,"%-6lf|", test->finish_line_time);
	fprintf(file,"%-7.2lf|", test->strength);
	fprintf(file,"%6.2lf     |\n", test->combat_effectiveness);
	fprintf(file,"----------+-------------+------+------+-------+------------\n");


	// close the file
	fclose(file);


}

void DisplayWinners (Robot* lineup, TestResults* test){
	FILE* file = fopen("Winners.txt", "w");
	if(file == NULL)
	{
		printf("ERROR! the file failed to open\n");
		exit(-1);
	}

	//print student info to file

	printf("Test Number %d", test->number,);
	printf("\n%s|%lf\n", test->name, test->trial);
	printf("%s|%lf|\n", test->name, test->strength);
	printf("%s+|%lf|\n", test->name, test->combat_effectiveness);


	printf("----------+-------------+------+------+-------+------------\n");

	return;
}*/ 