#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char robotname [30];
typedef int	 robotnumber;
typedef	double speed;
typedef double weight;

typedef struct Robot
{
	robotnumber number;
	robotname name;
	int year;
	speed trial;
	weight  mass;
	float best_score;
}Robot;

int main()
{
	int Robotnumber=3;
	Robot Robot_info[10];
    
	Robot_info[0] =(Robot){1, "Jitian", "1992", 68.7, 12, 61.0};
	Robot_info[1] =(Robot){2,  "Rob", "1993", 80.5, 12, 33.1};
	Robot_info[2] =(Robot){3, "Brett", "1994", 90.0, 1212, 33};

	int i=0;


	//open a file for writing
	FILE* file = fopen("Robot.txt", "w");
	if(file == NULL)
	{
		printf("ERROR! the file failed to open\n");
		exit(-1);
	}

	//print student info to file
    printf("the following data are to be written into the file 'Robot.txt'\n");
	for (i=0; i<Robotnumber; i++)
		printf("%d %s %s %f\n", Robot_info[i].student_ID, Robot_info[i].first_name, Robot_info[i].last_name, Robot_info[i].course_average);
	
	for (i=0; i<no_of_students; i++){
		fprintf(file, "%d %s %s %f\n", Robot_info[i].student_ID, Robot_info[i].first_name, Robot_info[i].last_name, Robot_info[i].course_average);
		
	}
	// clode the file
	fclose(file);
	
	
	return 0;
}