#include <stdio.h>


// Workshop 1 Code 
// Make a Converter from km/h to m/s



int main(void)
{

//Declare Variables	
	
	int km;
	int m;
	
// Ask For INPUT
	
	printf("Please type your speed in Kilometers per hour\n");
	
	scanf("%d", &km);
	
// Do MATH
	
	m = km*1000/3600;
	
// OUTPUT result
	
	printf("You are travelling at %d meters per second \n", m); 
	
// Give Life Advice
	
	printf("Thats so quick dude\n");
	printf("You should really slow down\n");
	
	return 0;
}