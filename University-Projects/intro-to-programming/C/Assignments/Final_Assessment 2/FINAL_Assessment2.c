// Inclusions and Definitions 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define min(a,b) (((a) < (b)) ? (a) : (b))
#define max(a,b) (((a) > (b)) ? (a) : (b))

// TypeDefinitions 
typedef char robot_name [30];
typedef int	 robot_number;
typedef	double speed;
typedef double weight;

// Create robot & Test_Results structures
typedef struct Robot
{
	robot_number number;
	robot_name name;
	int year;
	speed trial;
	weight mass;
	double best_score;
}Robot;

typedef struct Test_Results
{	
	robot_number number;
	robot_name name;
	int year;
	speed trial;
	weight mass;
	double best_score;
	int test_number;
	double speed_score;
	double finish_line_distance;
	double finish_line_time;
	double strength;
	double combat_effectiveness;
}Test_Results;

// Functions Which Are In Use For Program

void load_menu(void);
double combat(Robot* lineup, Test_Results* test);
void Display_Simulation_Result(void);
void Create_Robot(Robot* lineup);
void Print_Robot(Robot lineup);
void Print_Robot2(Robot lineup);
int Search_Robot(int Robot_Search, Robot* lineup, int Total_Robot);
void Save_Robot_Information(Robot lineup);
void Display_Winners (Test_Results* test[]);
void Save_All_Robot_Information(Test_Results* test);

// Main Program //
int main(void)

{
	load_menu ();
	return 0;
}

//Menu Functions

void load_menu(void)
{

    Robot lineup[10];

	lineup[0]= (Robot) {0, "Adam_the_link", 1999, 15, 110, 44};
	lineup[1]= (Robot) {1, "Brian_AT", 2010, 32.5, 18, 33};
	lineup[2]= (Robot) {2, "Bobby", 2013, 29.5, 7.5, 22};
	lineup[3]= (Robot) {3, "MiMi", 2018, 40.0, 8.8, 77};
	lineup[4]= (Robot) {4, "Harry", 1998, 37.2, 12.3, 88};

	Test_Results *r;
	Robot *p;
	int choice;
	int Robot_Search=0;
	int i, Total_Robot = 5 ;
	int m;
	int t=0;
	Test_Results test [10];



	// show all robot information
	printf("\nAll Robot information:\n");
	printf("\n Robot-Id |    Name       | Year  |  Speed  |  Weight  |  Combat Score |\n");
    printf("----------+-------------+------+------+-------+---------------\n");
	for (i=0; i<Total_Robot; i++)
	Print_Robot2(lineup[i]);
	printf("There are a total of %d Robots in the competition!\n\n", Total_Robot);

	do
    {
        printf("\nWelcome to the Robot-Simulator 2019!\n");
		printf("To start, select the desired number below:\n\n");
		
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


		//switch statements used for interactive menu with user
        switch(choice)
        {
            case 1:  

				printf("Please print the identifying number of the robot you wish to search for:\n");
				scanf("%d", &Robot_Search);
				if (Robot_Search >= lineup[Total_Robot]);
				else {Search_Robot(Robot_Search, lineup, Total_Robot);
				printf("%s was found\n\n", lineup[Robot_Search].name);
                	break;}
			
            case 2:
				p = &lineup[Total_Robot];
				Create_Robot(p);
				lineup[i].number=Total_Robot;
				Total_Robot++;
				printf("\nRobot information updated!\n\n");
                	break;
			
            case 3:
				printf("\nchoose the robot id\n");
				scanf("%d", &m);
				printf("\nRobot Number: = %d", lineup[m].number);
				printf("\nName: %25s", lineup[m].name);
				printf("\nYear: %d", lineup[m].year);
				printf("\nSpeed: %.2lf", lineup[m].trial);
				printf("\nWeight: %6.2lf", lineup[m].mass);
				printf("\nBest Score: %6.2lf\n\n", lineup[m].best_score);
				r = &test[t];
				t++;
				combat(&lineup[m],r);
                	break;
			
            case 4: Display_Simulation_Result() ;
                	break;
			
            case 5:
				//Jitian I ran out of time whilst trying to fix the error i had, i left what i have for this part
				//for (o=0; o<t; o++)
				//DisplayWinners(lineup[m], test[o]) ;
				printf("\nFeature not currently available! :(\n");
                	break;
			
            case 6:
				
				printf("\nthe following data are to be written into the file 'Robot.txt'\n");
				printf("\nAll Robot information:\n");
				printf(" Robot-Id |    Name     | Year |Speed | Weight| Combat Score\n");
    			printf("----------+-------------+------+------+-------+-------------\n");
				for (i=0; i<Total_Robot; i++)
				Save_Robot_Information(lineup[i]);
                	break;
			
            case 7: /*
			
				for (i=0; i<t; i++)
				{ 
							
					//open a file for writing
					FILE* file = fopen("Results.txt", "a");
					if(file == NULL)
				{
					printf("ERROR! the file failed to open\n");
					exit(-1);
				}

					//print robot info to file


					printf("|%-9d|", test->number);
					printf("%-13s|", test->name);
					printf("%-6d|", test->year);
					printf("%-6lf|", test->trial);
					printf("%-7.2lf|", test->mass);
					printf("%6.2lf     |\n", test->best_score);
					printf("|%-9d|", test->test_number);
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
					fprintf(file,"|%-9d|", test->test_number);
					fprintf(file,"%-13lf|", test->speed_score);
					fprintf(file,"%-6lf|", test->finish_line_distance);
					fprintf(file,"%-6lf|", test->finish_line_time);
					fprintf(file,"%-7.2lf|", test->strength);
					fprintf(file,"%6.2lf     |\n", test->combat_effectiveness);
					fprintf(file,"----------+-------------+------+------+-------+------------\n");

					// close the file
					fclose(file);			

				};  */
			
				printf("\nFeature not currently available! :(\n");
                	break;
			
			case 8:

				printf("\nAll Robot information:\n");
				printf("\nRobot-Id |    Name     | Year |Speed | Weight| Combat Score\n");
    			printf("----------+-------------+------+------+-------+-------------\n");

				for (i=0; i<Total_Robot; i++)
				{
					Print_Robot2(lineup[i]);
				};
			
                	break;
			
            case 9:  
				printf("Exiting the program!\n");
                exit(0);
                	break;
			
            default: printf("ERROR! Invalid choice, please RE-ENTER!\n");
               		break;
        }

    } while (choice != 9);
}


// Robot Creation Function

void Create_Robot(Robot *lineup) 

{
	printf("Please enter the Name of your Robot.\n");
	scanf("%30s", &(lineup->name));
	printf("Please enter the Year of Manufacture of your Robot.\n");
	scanf("%d", &(lineup->year));
	printf("Please enter the Speed score (m/s) of your Robot.\n");
	scanf("%lf", &(lineup->trial));
	printf("Please enter the Weight (kg) of your Robot.\n");
	scanf("%lf", &(lineup->mass));
	printf("Please Enter the Best Score your Robot has achieved\n");
	scanf("%lf", &(lineup->best_score));
	printf("\nRobot Successfully entered into database\n");
}

double combat(Robot* lineup, Test_Results* test)

{
// Open File Fight_Result.txt

	FILE * fptr;
	int i;
	char str[100];
	char fname[20]="Fight_Result.txt";
	fptr = fopen (fname,"w");

// State the Variables

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

	printf("\nYou have chosen the robot %s.\n", lineup->name);
	printf("Please enter how many seconds it took for your robot to complete the race.\n");
	scanf("%lf", &test->finish_line_time);

		while (test->finish_line_time<=0)

		{
			printf("ERROR! Please RE-ENTER how many seconds it took for your robot to complete the race.\n");
			scanf("%lf", &test->finish_line_time);
		}

	printf("Please enter how many meters the race was completed over.\n");
	scanf("%lf", &test->finish_line_distance);
		
		while (test->finish_line_distance<=0)

		{
			printf("ERROR! Please RE-ENTER how many meters the race was completed over.\n");
			scanf("%lf", &test->finish_line_distance);

		}
	
	// Complete the maths equation
	speed = (test->finish_line_distance) / (test->finish_line_time);
	
	// Recieve the strength input
	printf("How many objects did your robot lift between 0-100?\n");
	scanf("%lf", &test->strength);
	

		while (test->strength<0 || test->strength>100)

		{
			printf("ERROR! Please RE-ENTER how many objects the robot lifted between 0-100\n");
			scanf("%lf", &test->strength);
		}

	combatmax = min(speed, 50)+strength/100*50+10;
	test->combat_effectiveness = min(combatmax, 100);

	// Print the Combat Chances
	printf("Your Robot has a Combat Value of %lf\n",test->combat_effectiveness);
	printf("Would you like to use this value or your robots original best score of %lf\n", lineup->best_score);
	printf("Please enter 1 to use your robots original best score, otherwise enter any other whole number.\n");
	scanf("%d",&TrueFight);
	
	if
	(TrueFight!=1)
	{
		printf("Your Robot has %lf%% of winning. Good Luck!\n", test->combat_effectiveness);
	}
	
	else 
	printf("Your Robot has %lf%% of winning. Good Luck!\n", lineup->best_score);
	printf("Please press 1 to continue the simulation\n" );
	scanf("%d", &cont);

	// Set continue & LOOP
	while (cont != 1)
		{
			printf("ERROR! Please ENTER 1 to continue the simulation\n");
			scanf("%d", &cont);
		}

	// Reset ai and human counts
	ai = 0;
	human = 0;

	//  Create FOR Loop to generate RANDOM Fight determining winner and count number
	if

	(TrueFight!=1)
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
			if (aifight<=lineup->best_score)
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

	printf("\n-----------------------------------------");
	printf("\nRobot Number:  %d", lineup->number);
	printf("\n-----------------------------------------");
	printf("\nName: %s", lineup->name);
	printf("\n-----------------------------------------");
	printf("\nYear: %d", lineup->year);
	printf("\n-----------------------------------------");
	printf("\nSpeed: %lf",lineup->trial );
	printf("\n-----------------------------------------");
	printf("\nWeight: %6.2lf", lineup->mass);
	printf("\n-----------------------------------------");
	printf("\nBest Score: %6.2lf", lineup->best_score);
	printf("\n-----------------------------------------");
	printf("\nDistance: %lf", test->finish_line_distance);
	printf("\n-----------------------------------------");
	printf("\nTime: %lf", test->finish_line_time);
	printf("\n-----------------------------------------");
	printf("\nStrength Score: %lf", test->strength);
	printf("\n-----------------------------------------");
	printf("\nCombat Score: %lf", test->combat_effectiveness);
	printf("\n-----------------------------------------");
	
//PRINT the combat results

	printf("\n\nThe Robot won %d times and the humans won %d times!\n", ai, human);
	printf("Your speed score is %.0lf\n", max(lineup->trial, 1));
	printf("Your strength score is %lf\n", max(test->strength, 1));
	printf("Your combat strength is %lf\n", max(test->combat_effectiveness, 1));

		fgets(str, sizeof str, stdin);
		fputs(str, fptr);

	fprintf(fptr,"\n-----------------------------------------");
	fprintf(fptr,"\nRobot Number:  %d", lineup->number);
	fprintf(fptr,"\n-----------------------------------------");
	fprintf(fptr,"\nName: %s", lineup->name);
	fprintf(fptr,"\n-----------------------------------------");
	fprintf(fptr,"\nYear: %d", lineup->year);
	fprintf(fptr,"\n-----------------------------------------");
	fprintf(fptr,"\nSpeed: %lf", lineup->trial);
	fprintf(fptr,"\n-----------------------------------------");
	fprintf(fptr,"\nWeight: %6.2lf", lineup->mass);
	fprintf(fptr,"\n-----------------------------------------");
	fprintf(fptr,"\nBest Score: %6.2lf", lineup->best_score);
	fprintf(fptr,"\n-----------------------------------------");
	fprintf(fptr,"\nDistance: %lf", test->finish_line_distance);
	fprintf(fptr,"\n-----------------------------------------");
	fprintf(fptr,"\nTime: %lf", test->finish_line_time);
	fprintf(fptr,"\n-----------------------------------------");
	fprintf(fptr,"\nStrength Score: %lf", test->strength);
	fprintf(fptr,"\n-----------------------------------------");
	fprintf(fptr,"\nCombat Score: %lf", test->combat_effectiveness);
	fprintf(fptr,"\n-----------------------------------------");
	fprintf(fptr,"\nThe Robot won %d times and the humans won %d times!\n", ai, human);
	fprintf(fptr,"Your speed score is %.0lf\n", max(lineup->trial, 1));
	fprintf(fptr,"Your strength score is %lf\n", max(test->strength, 1));
	fprintf(fptr,"Your combat strength is %lf\n", max(test->combat_effectiveness, 1));
	
	/*for ( i = 0; i < 6; i++)
	test[i]=lineup[i];*/
	fclose (fptr);

	return combatmax;
}

	void Display_Simulation_Result(void)
{
	FILE * fptr;

  	char fname[20]="Fight_Result.txt";
  	char str1;

	//-------------- read the file -------------------------------------


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

	void Print_Robot(Robot lineup)

	{

		printf("\nRobot Number: = %d", lineup.number);
		printf("\nName: %s", lineup.name);
		printf("\nYear: %d", lineup.year);
		printf("\nSpeed: %lf", lineup.trial);
		printf("\nWeight: %6.2lf", lineup.mass);
		printf("\nBest Score: %6.2lf\n\n", lineup.best_score);
	}

	void Print_Robot2(Robot lineup){

	printf("|%-9d   |", lineup.number);
	printf("|%-13s  |", lineup.name);
	printf("|%-6d   |", lineup.year);
	printf("|%-6lf  |", lineup.trial);
	printf("|%-7.2lf|", lineup.mass);
	printf("|%6.2lf |\n", lineup.best_score);
	printf("----------+-------------+------+------+-------+------------\n");
		}




int Search_Robot(int Robot_Search, Robot *lineup, int Total_Robot){
	/*search and print the information of robot
	  stu[]: an array of student structures
	// return: the total number of count*/ 

	int i, count=0;
	if (Total_Robot<=0)
		return 0;
	for (i=0; i<Total_Robot; i++) {
		if(lineup[i].number == Robot_Search) {
		printf(" Robot-Id |    Name     | Year |Speed | Weight| Combat Score\n");
    	printf("----------+-------------+------+------+-------+-------------\n");
			Print_Robot2(lineup[i]);
		 count++;
		}
	}
	return count;
}

void Save_Robot_Information(Robot lineup)
  {
    




	//open a file for writing
	FILE* file = fopen("Robot.txt", "a");
	if(file == NULL)
	{
		printf("ERROR! the file failed to open\n");
		exit(-1);
	}

	//print robot info to file
   
	
	printf("|%-9d|", lineup.number); 
	printf("%-13s|", lineup.name);
	printf("%-6d|", lineup.year);
	printf("%-6lf|", lineup.trial);
	printf("%-7.2lf|", lineup.mass);
	printf("%6.2lf     |\n", lineup.best_score);
	printf("----------+-------------+------+------+-------+------------\n");
	
	fprintf(file,"|%-9d|", lineup.number); 
	fprintf(file,"%-13s|", lineup.name);
	fprintf(file,"%-6d|", lineup.year);
	fprintf(file,"%-6lf|", lineup.trial);
	fprintf(file,"%-7.2lf|", lineup.mass);
	fprintf(file,"%6.2lf     |\n", lineup.best_score);
	fprintf(file,"----------+-------------+------+------+-------+------------\n");
		
	
	// close the file
	fclose(file);
	return;
	
}

/*void Save_All_Robot_Information(Test_Results* test)
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
	printf("|%-9d|", test->test_number);
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
	fprintf(file,"|%-9d|", test->test_number);
	fprintf(file,"%-13lf|", test->speed_score);
	fprintf(file,"%-6lf|", test->finish_line_distance);
	fprintf(file,"%-6lf|", test->finish_line_time);
	fprintf(file,"%-7.2lf|", test->strength);
	fprintf(file,"%6.2lf     |\n", test->combat_effectiveness);
	fprintf(file,"----------+-------------+------+------+-------+------------\n");

	// close the file
	fclose(file);

}

void Display_Winners (Robot* lineup, Test_Results* test){
	FILE* file = fopen("Winners.txt", "w");
	if(file == NULL)
	{
		printf("ERROR! the file failed to open\n");
		exit(-1);
	}

	//print robot info to file

	printf("Test Number %d", test->number,);
	printf("\n%s|%lf\n", test->name, test->trial);
	printf("%s|%lf|\n", test->name, test->strength);
	printf("%s+|%lf|\n", test->name, test->combat_effectiveness);


	printf("----------+-------------+------+------+-------+------------\n");

	return;
}*/ 