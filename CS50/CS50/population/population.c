#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Global Variables
    int n;
    int t = 0;
    int nt = 0;
    int end;

    // Get Starting and End Size "Do While" loops

    do
    {
        n = get_int("Start size: ");
    }
    while (n < 9);
    do
    {
        end = get_int("End size: ");
    }
    while (end < n);

    //While loop with Mathematic loop, each iteration updates variable values.

    while (n < end)
    {
        int born = n / 3;
        int death = n / 4;
        int growth = born - death;
        n = n + growth;
        t++;
    }

    //Final Print Statement of Years Taken

    printf("Years: %i\n", t);
}