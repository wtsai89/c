#include "cs50.c"
#include <stdio.h>

int main(void)
{
    //Prompt for start size
    int start;
    do
    {
        start = get_int("Enter Starting Size (>=9): ");
    }
    while (start < 9);

    //Prompt for end size
    int end;
    do
    {
        end = get_int("Enter Ending Size: ");
    }
    while (end < start);

    //Calculate number of years until we reach threshold
    int count = 0;
    while (start < end)
    {
        start = start + (start / 3) - (start / 4);
        count++;
    }

    //Print number of years
    printf("Years: %i\n", count);
}
