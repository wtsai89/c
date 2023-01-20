#include "cs50.c"
#include <stdio.h>
#include <math.h>

int main(void)
{
    long number = get_long("Number: ");
    long numcopy = number;
    int digits = 0;
    int sum = 0;
    int single;
    string card;

    while (number > 0)
    {
        single = number % 10;
        sum += single;
        digits++;
        number = number / 10;
        if (number > 0)
        {
            single = (number % 10) * 2;
            while (single > 0)
            {
                sum += single % 10;
                single = single / 10;
            }
            digits++;
            number = number / 10;
        }
    }

    int firstTwo;
    if (sum % 10 != 0)
    {
        card = "INVALID";
    }
    else if (digits == 16)
    {
        firstTwo = numcopy / 100000000000000;
        if (firstTwo / 10 == 4)
        {
            card = "VISA";
        }
        else if (firstTwo > 50 && firstTwo < 56)
        {
            card = "MASTERCARD";
        }
        else
        {
            card = "INVALID";
        }
    }
    else if (digits == 15)
    {
        firstTwo = numcopy / 10000000000000;
        if (firstTwo == 34 || firstTwo == 37)
        {
            card = "AMEX";
        }
        else
        {
            card = "INVALID";
        }
    }
    else if (digits == 13)
    {
        firstTwo = numcopy / 100000000000;
        if (firstTwo / 10 == 4)
        {
            card = "VISA";
        }
        else
        {
            card = "INVALID";
        }
    }
    else
    {
        card = "INVALID";
    }

    printf("%s\n", card);
}