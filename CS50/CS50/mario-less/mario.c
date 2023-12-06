#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int x;

    do
    {
        x = get_int("How High is your pyramid?: ");
    }
    while (x < 1 || x > 8);

    for (int i = 0; i < x; i++)
    {
        for (int k = i; k < x - 1 ; k++)
        {
            printf(" ");
        }
        for (int j = x - i ; j <= x; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}

//  take user input
//  print pyramid of squares depending on input using for loop
//  print loop spaces using counter and nested for loop
//  print loop # using same method as above
//  leave nested for loop and add new line, repeat original loop.

