#include "cs50.c"
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    for (int i = 1; i <= height; i++)
    {
        //left space
        for (int j = 0; j < height - i; j++)
        {
            printf(" ");
        }

        //left blocks
        for (int j = 0; j < i; j++)
        {
            printf("#");
        }

        //mid gap
        printf("  ");

        //right blocks
        for (int j = 0; j < i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}