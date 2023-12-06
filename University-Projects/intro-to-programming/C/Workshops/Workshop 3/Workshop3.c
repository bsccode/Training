#include <stdio.h>
#include <stdlib.h>

struct Robot

{
  int number;
  char name [30];
  int year;
  double speed;
  double mass;
};

// SET FUNCTIONS

double speedfunction ();

int main(void)
{
  double speed;
  int quit;

struct Robot poopy = {1, "poopy", 2005, 16, 18 };
struct Robot poopymc = {2, "poopymc", 2088, 50, 66 };
struct Robot poopymcpoop = {3, "poopymcpoop", 2090, 100, 12 };
struct Robot poopymcpooper = {4, "poopymcpooper", 2018, 90, 1 };
struct Robot poopymcpoopers = {5, "poopymcpoopers", 2020, 8080, 50 };

  do
    {
      speed = speedfunction();
      printf("\n your trial speed is %.2lf\n", speed);
      printf("you will never beat %s though who has %lf speed score \n", poopymc.name, poopymc.speed );

      printf("\nType 1 to quit or 2 to restart \n");
  		scanf("%d", &quit);

      while (quit>=3 || quit<=0)


        {
          printf("\nThat was not 1 or 2, but I have nothing else left to show you :)\n");
				  printf("\nType 1 to quit or 2 to restart\n");
				  scanf("%d", &quit);}
    }
 while (quit==2);




return 0;
}

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
